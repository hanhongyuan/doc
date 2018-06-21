#!/bin/bash
Stack=$1
if [ "${Stack}" = "" ]; then
 Stack="install"
else
 Stack=$1
fi
profile(){
source /etc/profile
}
install(){
Jdk_url=http://download.oracle.com/otn-pub/java/jdk/8u91-b14/
Jdk_version=jdk-8u91-linux-x64.tar.gz
#tomcat
tomcat_url=http://archive.apache.org/dist/tomcat/tomcat-7/v7.0.65/bin/
tomcat_version=apache-tomcat-7.0.65.tar.gz
#commons-daemon
commons_daemon=http://apache.fayea.com//commons/daemon/source/commons-daemon-1.0.15-src.tar.gz
#guacamole-server
guacamole_server_url=http://downloads.sourceforge.net/project/guacamole/current/source/
guacamole_server_version=guacamole-server-0.9.8.tar.gz
#guacamole-0.9.8.war
guacamole098war_url=http://downloads.sourceforge.net/project/guacamole/current/binary/
guacamole098war_version=guacamole-0.9.8.war
#install depend
yum -y install cairo-devel libjpeg-turbo-devel libjpeg-devel libpng-devel uuid-devel freerdp-devel pango-devel libssh2-devel libtelnet-devel libvncserver-devel pulseaudio-libs-devel openssl-devel libvorbis-devel gcc wget net-tools
#download jdk64
cd /root
if [ -f $Jdk_version ]; then
echo "$Jdk_version exist"
else
wget --no-check-certificate --no-cookies --header "Cookie: oraclelicense=accept-securebackup-cookie" $Jdk_url$Jdk_version -O $Jdk_version
fi
#download tomcat
if [ -f $tomcat_version ]; then
echo "$tomcat_version exist"
else
wget $tomcat_url$tomcat_version
fi
#download commons-daemon
if [ -f commons-daemon-1.0.15-src.tar.gz ]; then
echo "commons-daemon-1.0.15-src.tar.gz exist"
else
wget $commons_daemon
fi
#download guacamole-server
if [ -f $guacamole_server_version ]; then
echo "$guacamole_server_version exist"
else
wget $guacamole_server_url$guacamole_server_version
fi
#download guacamole-0.9.8.war
if [ -f $guacamole098war_version ]; then
echo "$guacamole098war_version exist"
else
wget $guacamole098war_url$guacamole098war_version
fi
#Install jdk
cd /root
tar -zxvf $Jdk_version -C /usr/
mv /usr/jdk1.8.0_91 /usr/jdk1.8
#Install tomcat
tar -zxvf $tomcat_version -C /usr/
mv /usr/apache-tomcat-7.0.65 /usr/tomcat7
sed -i '2i CATALINA_OPTS="-Xms1024m -Xmx4096m -XX:PermSize=256m -XX:MaxPermSize=512m"' /usr/tomcat7/bin/daemon.sh
sed -i '2i CATALINA_HOME=/usr/tomcat7' /usr/tomcat7/bin/daemon.sh
sed -i '2i JAVA_HOME=/usr/jdk1.8' /usr/tomcat7/bin/daemon.sh
sed -i '2i # description: simple example to start tomcat' /usr/tomcat7/bin/daemon.sh
sed -i '2i # chkconfig: 2345 20 80' /usr/tomcat7/bin/daemon.sh
#Configuration variable
cp /etc/profile /etc/profile.bak
echo 'JAVA_HOME=/usr/jdk1.8' >> /etc/profile
echo 'PATH=$JAVA_HOME/bin:$PATH' >> /etc/profile
echo 'CLASSPATH=$JAVA_HOME/jre/lib/ext:$JAVA_HOME/lib/tools.jar' >> /etc/profile
echo 'GUACAMOLE_HOME=/etc/guacamole' >> /etc/profile
echo 'export PATH JAVA_HOME CLASSPATH GUACAMOLE_HOME' >> /etc/profile
profile
#install commons-daemon
cd /root
tar -zxvf commons-daemon-1.0.15-src.tar.gz
cd commons-daemon-1.0.15-src/src/native/unix/ && ./configure && make
cp jsvc /usr/tomcat7/bin
cp /usr/tomcat7/bin/daemon.sh /etc/init.d/tomcat7
chmod 755 /etc/init.d/tomcat7
useradd -s /sbin/nologin tomcat
chown -R tomcat:tomcat /usr/tomcat7
chkconfig --add tomcat7
service iptables stop
systemctl stop firewalld.service
#install guacamole-server-0.9.8
cd /root
tar -xzf $guacamole_server_version
cd guacamole-server-0.9.8/
./configure --with-init-dir=/etc/init.d
make && make install && ldconfig
#install guacamole-0.9.8.war
cd /root
cp guacamole-0.9.8.war /usr/tomcat7/webapps/guacamole.war
#Configure guacamole
mkdir /etc/guacamole && cd /etc/guacamole/
touch guacamole.properties && touch user-mapping.xml
mkdir /usr/share/tomcat7 && mkdir /usr/share/tomcat7/.guacamole
ln -s /etc/guacamole/guacamole.properties /usr/share/tomcat7/.guacamole/
echo '--port:' >> /etc/guacamole/guacamole.properties
cat >/etc/guacamole/user-mapping.xml<<EOF
<user-mapping>
<authorize username="admin" password="wwwtiewwcom">
<connection name="vnc">
<protocol>vnc</protocol>
<param name="hostname">192.168.2.206</param>
<param name="port">5901</param>
<param name="username">root</param>
<param name="password">123456</param>
</connection>
<connection name="rdp">
<protocol>rdp</protocol>
<param name="hostname">192.168.2.206</param>
<param name="port">3389</param>
<param name="username">root</param>
<param name="password">123456</param>
</connection>
<connection name="ssh">
<protocol>ssh</protocol>
<param name="hostname">192.168.2.206</param>
<param name="port">22</param>
<param name="username">root</param>
<param name="password">123456</param>
</connection>
</authorize>
</user-mapping>
EOF
#Start tomcat guacamole
/etc/init.d/tomcat7 start
if netstat -ntulp |grep -w 8080; then
if /etc/init.d/guacd restart; then
echo -e "Start tomcat \033[32mok\033[0m"
echo -e "Start guacamole \033[32mok\033[0m"
echo -e "\033[32mGuacamole installed successfully\033[0m"
else
echo -e "Start guacamole \033[31mfailed\033[0m"
echo -e "\033[31mGuacamole installation failed\033[0m"
fi
else
echo -e "Start tomcat \033[31mfailed\033[0m"
echo -e "\033[31mStart tomcat failed\033[0m"
fi
}
uninstall(){
/etc/init.d/tomcat7 stop
/etc/init.d/guacd stop
rm -rf /usr/jdk1.8
rm -rf /usr/tomcat7
rm -rf /etc/profile
cp /etc/profile.bak /etc/profile
rm -rf /etc/init.d/tomcat7
userdel tomcat
rm -rf /etc/guacamole
rm -rf /usr/share/tomcat7
rm -rf /root/guacamole-server-0.9.8 
rm -rf /root/commons-daemon-1.0.15-src
rm -rf /etc/init.d/guacd
profile
echo -e "\033[32mUninstalled successfully\033[0m"
}
case "${Stack}" in
 install)
 install
 ;;
 uninstall)
 uninstall
 ;;
 *)
 echo "Usage: $0 {install|uninstall}"
 ;;
esac