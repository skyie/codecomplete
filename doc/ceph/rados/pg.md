# PG状态

## 生成状态机的脚本
http://bean-li.github.io/ceph-peering-state-model/
```
1. 进入ceph源码目录
2. cat src/osd/PG.h src/osd/PG.cc | doc/scripts/gen_state_diagram.py > /tmp/peering_graph.generated.dot
默认尺寸7,7 很模糊，修改为512,512会清晰一点
digraph G {
    size="7,7"
    compound=true;
    subgraph cluster0 {

3. dot -Tpng peering_graph.generated.dot -o peering.png  # 需要apt install graphviz


```




