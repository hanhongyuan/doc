FROM tomcat
WORKDIR /root
COPY {{JOB_NAME}}.WAR  /tomact/webapps/{{JOB_NAME}}.WAR
COPY application.properties {{JOB_NAME}}.properties
EXPOSE 8080
CMD /tomcat/bin/start.sh