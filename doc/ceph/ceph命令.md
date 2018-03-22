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

rados -p foo put myobject blah.txt

rados -p foo rm myobject





## ceph集群写object









