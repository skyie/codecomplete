资料链接：
http://www.sysnote.org

https://bcache.evilpiepirate.org/

SSD进行bcache：

1.
make-bcache -C /dev/sdl  #一个ssd只执行一次就行了，执行多次会报错提示已经有bcache
2.ls -l /sys/fs/是否出现bcache目录，bcache目录下应该类似如下：
root@master:~# ls -l /sys/fs/bcache/
total 0
drwxr-xr-x 7 root root    0 Jul 27 17:08 dbb80353-ed61-4265-b790-f59a68644542
--w------- 1 root root 4096 Jul 27 15:01 register
--w------- 1 root root 4096 Jul 27 14:52 register_quiet

如果没有执行以下命令：
echo /dev/sdl > /sys/fs/bcache/register  #这一步观察一下是否必要做

3.记录下ssd的bcache 的cset uuid
     bcache-super-show -f /dev/sdl

root@master:~# bcache-super-show -f /dev/sdl
sb.magic        ok
sb.first_sector        8 [match]
sb.csum            AB5B85A0125080C8 [match]
sb.version        3 [cache device]

dev.label        (empty)
dev.uuid        a328dbf1-0683-45ef-bff4-ad4b806e1a2f
dev.sectors_per_block    1
dev.sectors_per_bucket    1024
dev.cache.first_sector    1024
dev.cache.cache_sectors    468860928
dev.cache.total_sectors    468861952
dev.cache.ordered    yes
dev.cache.discard    no
dev.cache.pos        0
dev.cache.replacement    0 [lru]

cset.uuid        dbb80353-ed61-4265-b790-f59a68644542

4.hdd 盘/dev/sdk执行
     
     4.1先擦除：
          root@master:~# wipefs  -a /dev/sdk
     wipefs: error: /dev/sdk: probing initialization failed: Device or resource busy
     如果报错可能之前有make-bcache过，执行
          echo 1 > /sys/block/bcache/bcache0/stop
     4.2 
          make-bcache -B /dev/sdi2
     4.3 根据之前记录的 <cset.uuid>
     echo <cache set uuid> > /sys/block/bcache<N>/bcache/attach  #这一步就是将/dev/sdk加入到了bcache里了，
      如果系统就一个ssd做了bcache,那么bcache<N>=bcache0, 多个就以此累加
root@master:~# lsblk /dev/sdk
NAME      MAJ:MIN RM   SIZE RO TYPE MOUNTPOINT
sdk         8:160  0 838.4G  0 disk
└─bcache0 251:0    0 838.4G  0 disk
说明sdk加入到bcache0就完成了


          


bcache-super-show -f /dev/sdl|grep cset.uuid|awk '{print $2}'  #bcache的cset  UUID
HDD加入到bcache

make-bcache -B /dev/sdk   #sdk是要加入bcache的HDD盘，执行完后实际还没加进去
echo <cache set uuid> > /sys/block/bcache<N>/bcache/attach


hdd盘sdi从ssd   sdh中删除：



















































HDD从bcache踢出去：


echo 57c288fd-89da-41b0-85d4-0f46a2f6bd9d > /sys/block/bcache0/bcache/detach  
echo 1 >  /sys/block/bcache0/bcache/stop

最后需要echo 1 > /sys/fs/bcache/<uuid>/stop,否则会报错：Device or resource busy


ssd uuid


Q1：查看磁盘是HDD还是SSD？







Q2：Device or resource busy 磁盘操作报错原因？



BLUESTORE_PART1 = "0% 106M"
BLUESTORE_PART2 = "106M  5430M"   # 100M + 15360M = 15460M
BLUESTORE_PART3 = "5430M  21506M" # 15460M + 5120M = 20580M
BLUESTORE_PART4 = "21506M  100%"

parted -s --align optimal /dev/sdd mklabel gpt
parted -s --align optimal /dev/sdd  mkpart primary xfs 0% 106M
parted -s --align optimal /dev/sdd  mkpart primary xfs  106M  5430M
parted -s --align optimal /dev/sdd  mkpart primary xfs  5430M  21506M
parted -s --align optimal /dev/sdd  mkpart primary xfs   21506M  100%



parted -s --align optimal /dev/sdd mklabel gpt
parted -s --align optimal /dev/sdd  mkpart primary xfs 0% 106M
parted -s --align optimal /dev/sdd  mkpart primary xfs  106M  5426M
parted -s --align optimal /dev/sdd  mkpart primary xfs  5426M  10746M
parted -s --align optimal /dev/sdd  mkpart primary xfs   10746M  100%



for i in sd{b..g}
do
parted -s --align optimal /dev/$i mklabel gpt
parted -s --align optimal /dev/$i  mkpart primary xfs 0% 106M
parted -s --align optimal /dev/$i  mkpart primary xfs  106M  5426M
parted -s --align optimal /dev/$i  mkpart primary xfs  5426M  10746M
parted -s --align optimal /dev/$i  mkpart primary xfs   10746M  100%
done


make-bcache -C  /dev/sdh   # /sys/fs/bache/下多个一个<uuid>
make-bcache -B  /dev/sdi2  #/sys/block/bcach<i>  生成出来
make-bcache  -B  /dev/sdi3

#get  sdh uuid     ls /dev/bcache
echo <uuid>  > /sys/block/bcache<i>/attach
     echo 22fe54ca-1d1b-49d2-bfbe-231f36f6c6d2 > /sys/block/bcache1/bcache/attach

echo 22fe54ca-1d1b-49d2-bfbe-231f36f6c6d2 > /sys/block/bcache1/bcache/detach
echo 1 > /sys/block/bcache1/bcache/stop
wipefs -a /dev/sdi2 



root@master:~# ll /dev/bcache/by-uuid/
total 0
drwxr-xr-x 2 root root 60 Aug  2 17:59 ./
drwxr-xr-x 3 root root 60 Aug  2 17:59 ../
lrwxrwxrwx 1 root root 13 Aug  2 17:59 9bb03dad-ee22-4e8b-a201-88ddb2af5418 -> ../../bcache1



31a7de99-fd92-464b-9463-6455b21ed7a5  sdi1
d03cf598-b876-4cef-83a2-dcaf97faf2cc   sdi3

bluestore block path =
bluestore block db path =
bluestore block wal path =


del osd:

id=2
systemctl stop ceph-osd@$id
umount /var/lib/ceph/osd/ceph-$id
ceph-disk destroy /dev/sdi1
ceph-disk zap /dev/sdi

systemctl disable ceph-osd@$id
ceph osd crush remove osd.$id; ceph auth del osd.$id; ceph osd rm $id



 ceph-deploy --overwrite-conf  osd  prepare --bluestore master:/dev/sdi1
 ceph-deploy --overwrite-conf  osd  activate master:/dev/sdi1

查看磁盘是否是机械盘还是固态ssd
cat /sys/block/sda/queue/rotational  /sys/block/sda/queue/rotational  
0表示SSD,1表示机械硬盘













