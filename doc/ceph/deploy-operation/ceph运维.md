# ceph运维手册

[TOC]
# ceph常用命令整理
## pool




## rados
rados df # 查看使用情况
```
root@ubuntu:~# rados df
POOL_NAME  USED OBJECTS CLONES COPIES MISSING_ON_PRIMARY UNFOUND DEGRADED RD_OPS RD    WR_OPS WR   
iscsi-pool 211M      70      0    210                  0       0        0    654 1066k    591 207M 
pool          0       0      0      0                  0       0        0      0     0      0    0 

total_objects    70
total_used       5013M
total_avail      122G
total_space      127G
```


rados -p foo ls
```
root@aStor-2388:~# rados -p replica_pool ls
rbd_data.a674d74b0dc51.000000000000000b
rbd_data.a674d74b0dc51.0000000000000008




```
rados -p foo put myobject blah.txt

rados -p foo rm myobject


```
rados -p rbd get rb.0.1014.74b0dc51.000000000000 test

hexdump -vC test


```

root@aStor-2388:~# rbd -p replica_pool ls
608c23f737cd11e89d0200fefdad059f_1


root@aStor-2388:~# rbd -p replica_pool info 608c23f737cd11e89d0200fefdad059f_1
rbd image '608c23f737cd11e89d0200fefdad059f_1':
	size 102400 MB in 25600 objects
	order 22 (4096 kB objects)
	block_name_prefix: rbd_data.a674d74b0dc51  
	format: 2
	features: layering, exclusive-lock
	flags: 
	create_timestamp: Wed Apr  4 13:59:48 2018



rbd ojectname名称：

查看映射
ceph osd map <pool_name>  <obj>
	osdmap e314 pool 'replica_pool' (4) object 'myobject' -> pg 4.5da41c62 (4.462) -> up ([11,13,1], p11) acting ([11,13,1], p11)


xxd查看对应偏移下的内容
	xxd -seek 0x00030 /dev/sdb2|more


## ceph集群写object
test
test





# osd


# pg


# crush

	ceph osd getcrushmap -o  crush;crushtool -d crush  -o crush.txt
	crushtool -c  crush.txt   -o new_crush;ceph osd setcrushmap -i   new_crush

# 日志调试

	ceph daemon /var/run/ceph/ceph-osd.1.asok help 查看支持的命令



	ceph daemon /var/run/ceph/ceph-osd.1.asok config set debug_osd 30/30 左边代表打到日志文件的级别，右边assert记录内存信息
的级别，一般用不到
	# 30/30 全开 默认是1/5
	源码中的lcout(cct, 1)<< 的1就代表日志级别，越大越详细这个还没试过
	ceph tell osd.0 injectargs --debug-osd 15/15
	ceph --cluster=ceph --admin-daemon /var/run/ceph/ceph-mon.`hostname`.asok mon_status


# 认证
	mkdir -p /var/lib/ceph/mgr/ceph-`hostname`
	ceph auth get-or-create mgr.`hostname` mon 'allow profile mgr' osd 'allow *' mds 'allow *'  -o /var/lib/ceph/mgr/ceph-`hostname`/keyring
	systemctl restart ceph-mgr@`hostname`
	systemctl enable ceph-mgr@`hostname`
	

# rbd
	查看pool中的obj
rados ls -p <pool_name>

查看pool中imge
rbd ls <pool_name>

查看imge信息
rbd info <pool_name>/<image_name>

查看object映射的位置
ceph osd map <pool_name>  <obj_name>

查看obj里的内容
rados -p replica_pool get rbd_id.3c62a22b00fa11e887bcfcfefd1d759f_1 ~/a
pool上传一个ojbect
rados -p replica_pool pub <object_name> <file.txt>

# osdmap
ceph osd new 9ebbbdd8-aef7-424f-8d84-07cd05199999 osd.67

ceph osd getmap > /tmp/osdmap
ceph-dencoder import /tmp/osdmap type OSDMap decode dump_json | less

ceph osd getmap 1177 > /tmp/osdmap.1177
ceph-dencoder import /tmp/osdmap.1177 type OSDMap decode dump_json | less


# rados
```
查看池内的objects
rados -p replica_pool ls

查看omap的keys
root@aStor-9047:~# rados -p replica_pool listomapkeys rbd_directory
id_1f791c74b0dc51
name_testimg

# 查看池内对象的omap
root@aStor-9047:/home/aStor2.2/Trunk# rados -p replica_pool listomapvals rbd_directory
id_1f791c74b0dc51
value (11 bytes) :
00000000  07 00 00 00 74 65 73 74  69 6d 67                 |....testimg|
0000000b

name_testimg
value (18 bytes) :
00000000  0e 00 00 00 31 66 37 39  31 63 37 34 62 30 64 63  |....1f791c74b0dc|
00000010  35 31                                             |51|
00000012

# 对象的stat
root@aStor-9047:~# rados -p replica_pool  stat  rbd_info
replica_pool/rbd_info mtime 2018-03-26 17:43:43.000000, size 19

# 获取对象内容到写到文件里
root@aStor-9047:~# rados -p replica_pool  get rbd_info /tmp/f1.txt
root@aStor-9047:~# hexdump -C /tmp/f1.txt  看到是19个字节
00000000  6f 76 65 72 77 72 69 74  65 20 76 61 6c 69 64 61  |overwrite valida|
00000010  74 65 64                                          |ted|
00000013
	对size 0的listomapvals有内容，而有size的listomapvals 没内容

hexdump -C /tmp/f1.txt 十六进制显示文件内容












```





















## 新添磁盘到集群






## 从集群踢出磁盘




## 坏盘进行换盘操作

1. 定位到故障磁盘
	通过监控或者megacli,smartctl监控到某个磁盘坏掉

2. 找到故障磁盘对应的osd
	lsblk 找到坏盘对应的osd

3. 停止osd服务
	systemctl stop ceph-osd@<osd_id>.service
	ceph osd out osd.<osd_id>   # osd服务stop后osd down了，但并不会马上把上面数据迁移走，需要等默认配置例如5min后
		osd被标记未out后，才会开始数据迁移



4. 删除osd
	注意需要等待数据迁移完成恢复健康后，从集群中删除osd,没迁移删除osd可能丢数据

	crushmap中删除
	ceph osd crush rm osd.<id>
	认证中删除
	ceph auth del osd.<id>
	删除osd 
	ceph osd rm <id>
	取消挂载点
	umount /var/lib/ceph/osd/ceph-<id>
	删除osd下的目录
	rm -fr /var/lib/ceph/osd/ceph-<id>


5. 拔掉坏盘插入新盘，加入集群
	插入新盘加入集群后，新的数据会迁移到新盘的osd上


## 集群重平衡



## 系统盘恢复









# 运维过程中的问题
1. 系统启动阶段部署osd的的时候，新插一块盘，系统无法启动？







2.purgedata的时候报错：
```
Running command: find /var/lib/ceph -mindepth 1 -maxdepth 2 -type d -exec umount {} ;', 
'[aStor-8972][WARNING] umount: /var/lib/ceph/osd: not mounted\n', '[aStor-8972][WARNING] umount: /var/lib/ceph/osd/ceph-1: target is busy\n', '[aStor-8972][WARNING]         (In some cases useful info about processes that', 
'[aStor-8972][WARNING]          use the device is found by lsof(8) or fuser(1).)
```
原因：
	umount的时候目录被占用：
	1. osd服务没stop就umount；
	2. 运维的管理后台服务中有正在使用目录的流程，例如备份服务
	3. 有人



3. ssh相关问题
- 系统重装后原来的节点的host key变化，其他节点的/root/.ssh/known_host没更新，ssh恢复的节点报中间人攻击

- 两个节点IP互相对换后ssh连接 由于/root/.ssh/known_hosts没更新提示中间人攻击


4. 母盘制作执行swapoff -a 提示can't allocate memory
关于swap分区的解释的博客：
http://www.cnblogs.com/kerrycode/p/5246383.html
	swap分区是磁盘划分的一个分区，应对系统内存不足时，将一部分内存页交换到交换分区，腾出内存给更需要内存的进程。这样
系统其实可以使用比实际物理内存更大的内存。swapoff -a关闭交换分区应该是将swap分区内使用的内存页放回到系统内存中。如果
此时系统内存不足的话就会报这个错误












