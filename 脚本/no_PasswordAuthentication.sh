/bin/bash

ansible all -m shell -a "sed -i  s/'PasswordAuthentication no'/'PasswordAuthentication yes'/ /etc/ssh/sshd_config "
ansible all -m command -a "systemctl restart sshd"
