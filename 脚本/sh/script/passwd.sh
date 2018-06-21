#/bin/bash
num=`cat ip_passwd|wc -l`
i=1
while (($i <= $num))
do 
    ip=`cat ip_passwd|awk '{print $1}'|sed -n "$i"p`
    passwd=`cat ip_passwd|awk '{print $2}'|sed -n "$i"p`
    ping $ip -c1 &>/dev/null 
    sshpass -p $passwd ssh-copy-id -i ~/.ssh/id_rsa.pub  -o StrictHostKeyChecking=no root@$ip &>/dev/null
    if [ $? -eq 0 ];then 
    echo "$ip 秘钥分发成功"
    else 
    echo "$ip 秘钥分发失败"
    fi
    let "i++"
done
