# coredump

1. Linux开启coredump
ulimit -a 第一次想core file size 大小为0，或者ulimit -c 输出为0表示不产生core文件。
ulimit -c unlimited 设置生成core文件，不限制core文件大小。但是不是永久生效，如果
要永久生效修改/etc/profile




2. 设置coredump产生的路径
mkdir -p /data/coredump
echo /data/coredump/core.%e.%p> /proc/sys/kernel/core_pattern

%e:程序名
%p:进程id



