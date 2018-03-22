[TOC]
# parted
eg:
    parted /dev/sdb
    mklabel gpt
    mkpart primary 0% 100% # 格式化为一个分区,使用百分比不会提示那个没对齐影响性能的提示
    print # 打印结果
    quit # 退出
    mkfs.xfs /dev/sdb1 # 格式化分区
    mount /dev/sdb1 /mnt # 挂在到/mnt目录
    修改/etc/fstab开机自动挂载
        文件系统 挂载目录 文件系统格式 挂载可选参数 dump  pass
        UUID=<UUID> /mnt        xfs          default   0     0
        上面UUID是执行blkid的输出UUID








