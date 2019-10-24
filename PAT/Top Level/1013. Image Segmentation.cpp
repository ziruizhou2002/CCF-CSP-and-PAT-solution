#include<bits/stdc++.h>
using namespace std;
struct Edge{//边类
    int v1,v2;
    double weight;
    Edge(int vv1,int vv2,double w):v1(vv1),v2(vv2),weight(w) {}
    bool operator <(const Edge&e)const{//重载小于运算符
        return this->weight>e.weight;
    }
};
priority_queue<Edge>edges;
struct Node{
    int father;//父节点的编号，如果是根结点，表示整棵树结点个数的负值
    double maxWeight,h;//最小生成树中最长的边的长度、整个组件的H值
    Node(double f,int fa=-1,double w=0.0):h(f),father(fa),maxWeight(w) {}
};
vector<Node>nodes;//并查集数组
int findFather(int x){//寻找根结点并进行路径压缩
    if(nodes[x].father<0)//father值小于0，该结点为根结点
        return x;//返回根结点编号
    int t=findFather(nodes[x].father);
    nodes[x].father=t;
    return t;
}
int n,m,a,b;
double c,w;
int main(){
    scanf("%d%d%lf",&n,&m,&c);
    while(n--)//初始化并查集
        nodes.push_back(Node(c));
    while(m--){
        scanf("%d%d%lf",&a,&b,&w);
        edges.push(Edge(a,b,w));
    }
    while(!edges.empty()){
        Edge e=edges.top();
        edges.pop();
        int ua=findFather(e.v1),ub=findFather(e.v2);
        if(ua>ub)//ua指向编号小的根结点,ub指向编号大的根结点
            swap(ua,ub);
        if(ua!=ub&&e.weight<=nodes[ua].h&&e.weight<=nodes[ub].h){//合并并查集
            nodes[ua].father+=nodes[ub].father;//更新ua指向的father值
            nodes[ub].father=ua;//让编号大的根结点向编号小的根结点合并
            nodes[ua].maxWeight=max(nodes[ua].maxWeight,e.weight);
            nodes[ua].h=nodes[ua].maxWeight+c/abs(nodes[ua].father);
        }
    }
    vector<set<int>>ans={{}};//存储最终结果
    for(int i=0;i<nodes.size();++i)//遍历并查集，找到各个根结点并放入ans中
        if(nodes[i].father<0){
            nodes[i].father=-ans.size();
            ans.push_back({i});
        }
    for(int i=0;i<nodes.size();++i)//遍历并查集，找到各个非根结点并放入其根节点在ans中的对应set中
        if(nodes[i].father>=0)
            ans[abs(nodes[findFather(i)].father)].insert(i);
    for(int i=1;i<ans.size();++i){//输出
        for(auto j=ans[i].begin();j!=ans[i].end();++j)
            printf("%s%d",j==ans[i].begin()?"":" ",*j);
        puts("");
    }
    return 0;
}
