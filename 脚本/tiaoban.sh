#!/bin/bash
function trapper(){
        trap '' SIGHUP SIGINT SIGQUIT SIGTSTP SIGTERM
}
function menu(){
        cat <<-EOF
###############hostlist##########################
	1)  192.168.19.16      /*待定*/                 #   
	2)  192.168.19.17      /*待定*/                 #
	3)  192.168.19.18      /*待定*/                 #  
	4)  192.168.19.19      /*数据库服务器*/         #  
	5)  192.168.19.20      /*数据库备份服务器*/     #
	6)  192.168.19.21      /*待定*/                 #   
	7)  192.168.19.22      /*待定*/                 #
	8)  192.168.19.30      /*待定*/                 #
	9)  192.168.19.31      /*待定*/                 #  
	10) 192.168.19.32     /*待定*/                  #
	11) 192.168.19.33     /*待定*/                  #
##################################################
EOF
}
"tiaoban.sh" 39L, 475C                                                     3,2-9         Top
function host(){
#GROUPNAME="yunwei"
#USERGROUP=$(groups $USER |cut -f2 -d':')
#USERR="jump2"
 #   if [ $GROUPNAME == $USERGROUP ];then
  #  USERR="jump"
   # fi
    case "$1" in
        1)      echo "Now,you are login 192.168.19.16"
                ssh $USER@192.168.19.16
        ;;
        2)
                echo "Now, you are login 192.168.19.17"
                ssh $USER@192.168.19.17
        ;;
        3)
		echo "Now,you are login 192.168.19.18"
                ssh $USER@192.168.19.18
        ;;
        4)
		echo "Now,you are login 192.168.19.19"
                ssh $USER@192.168.19.19
        ;;
        5)
		echo "Now,you are login 192.168.19.20"
                ssh $USER@192.168.19.20
        ;;
        6)
		echo "Now,you are login 192.168.19.21"
                ssh $USER@192.168.19.21
        ;;
        7)
		echo "Now you are login 192.168.19.22"
                ssh $USER@192.168.19.22
        ;;
        8)
		echo "Now,you are login 192.168.19.30"
                ssh $USER@192.168.19.30
        ;;
        9)
		echo "Now you are login 192.168.19.31"
                ssh $USER@192.168.19.31
        ;;
        10)
		echo "Now,you are login 192.168.19.32"
                ssh $USER@192.168.19.32
        ;;
        11)
		echo "Now ,you are login 192.168.19.33"
                ssh $USER@192.168.19.33
        ;;
	110)
		echo "hello my root,please input your password" 
		su root
	;;
        *)
		echo "select error." 
    esac
    
}
function main(){
        while true
        do
                trapper
                clear
                menu
                read -p "please select:" num
                host $num
        done
}
main
