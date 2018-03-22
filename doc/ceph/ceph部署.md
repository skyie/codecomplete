<h1>ceph部署</h1>
[TOC]
    ceph lumious版本bluestore部署

# 部署

## 添加osd
    ceph-disk prepare --bluestore /dev/sdX --block.wal /dev/sdX
    ceph-disk activate /dev/sdX1






# 集群操作
## 删除osd
    ceph auth del osd.<id>
    ceph osd crush remove osd.<id>
    ceph osd rm <id>
    umount /var/lib/ceph/osd/ceph-<id>
    rm -fr /var/lib/ceph/osd/ceph-<id>


## 删除存储池


## 



