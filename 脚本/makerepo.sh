#!/bin/bash
#
if [ -e $1 ];them
echo "$1 exists"
exit 3
fi

read -p "Repository ID:" REPOID
until [ $REPOID == 'QUIT' ];do
echo $REPOID >>$REPOFILE
