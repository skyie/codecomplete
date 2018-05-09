#  ceph部署

ceph安装包
http://docs.ceph.com/docs/master/install/get-packages/

https://download.ceph.com/debian-luminous/pool/main/c/ceph/





## 卸载ceph
1. 停止ceph相关服务

2. ceph-deploy purge <hostname> 卸载ceph安装包

3. ceph-deploy purgedata <hostname> 清除ceph数据

4. 删除/var/lib/ceph目录 --是否需要？




**问题**
1. purgedata的时候报错：
```
Running command: find /var/lib/ceph -mindepth 1 -maxdepth 2 -type d -exec umount {} ;', 
'[aStor-8972][WARNING] umount: /var/lib/ceph/osd: not mounted\n', '[aStor-8972][WARNING] umount: /var/lib/ceph/osd/ceph-1: target is busy\n', '[aStor-8972][WARNING]         (In some cases useful info about processes that', 
'[aStor-8972][WARNING]          use the device is found by lsof(8) or fuser(1).)
```
有以下几种
- purgedata前需要先将osd服务


## 升级
下载ceph的deb包
ceph_<v>_amd64.deb
ceph-base
ceph-common
ceph-fuse


_
