# iscsi



## iscsi操作

发现远程目标

eg:
iscsiadm -m discovery -t sendtargets -p 192.168.1.1:3260

登录目标节点：

eg:
单向认证：
iscsiadm -m node -T iqn.2018-03.com.sangfor.asan:test4 -o update -n node.session.auth.username --value=test4
iscsiadm -m node -T iqn.2018-03.com.sangfor.asan:test4 -o update -n node.session.auth.password --value=1111111111111
iscsiadm -m node -T iqn.2018-03.com.sangfor.asan:test4 -l
登录后lsblk可以看到本地多了一块挂载的磁盘

格式化挂载的磁盘
mkfs.xfs /dev/sdX

挂载本地目录使用
mkdir -p /mnt/test
mount /dev/sdX /mnt/test

本地写文件
dd if=/dev/zero of=/mnt/test/test.txt bs=4M count=100











# 


