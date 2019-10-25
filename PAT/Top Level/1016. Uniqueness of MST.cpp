#include<bits/stdc++.h>
using namespace std;
struct Edge{//边的类
    int v1,v2,weight;
    bool isTreeEdge;//标识该边能否成为最小生成树中的边
    Edge(int vv1,int vv2,int w,bool is=false):v1(vv1),v2(vv2),weight(w),isTreeEdge(is) {}
};
vector<Edge>edges;
int n,m,father[505];//father为并查集
int findFather(int x){//查找并查集的根结点并进行路径压缩
    if(x==father[x])
        return x;
    int temp=findFather(father[x]);
    father[x]=temp;
    return temp;
}
int main(){
    scanf("%d%d",&n,&m);
    while(m--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        edges.push_back(Edge(a,b,c));
    }
    sort(edges.begin(),edges.end(),[](const Edge&e1,const Edge&e2){
        return e1.weight<e2.weight;
    });//对边按权值排序
    iota(father,father+n+1,0);//初始化并查集
    int total=0,num=0;//最小生成树的权值、最小生成树中的边的数量
    bool yes=true;//最小生成树是否唯一
    for(int i=0,j=0;i<edges.size();i=j){//遍历edges
        //扫描与edges[i]权值相等的边并判断该边能否成为最小生成树中的边
        for(j=i;j<edges.size()&&edges[j].weight==edges[i].weight;++j)
            if(findFather(edges[j].v1)!=findFather(edges[j].v2))
                edges[j].isTreeEdge=true;
        for(int k=i;k<j;++k){//扫描与edges[i]权值相等的边并插入到最小生成树中
            int ua=findFather(edges[k].v1),ub=findFather(edges[k].v2);
            if(ua!=ub){//边的两个结点不在一个集合中
                total+=edges[k].weight;//递增权值
                father[ua]=ub;//合并边的两个端点
                ++num;//递增最小生成树边的数量
            }else if(edges[k].isTreeEdge)//如果边的两个结点在一个集合中而该边能成为最小生成树中的边
                yes=false;//最小生成树不唯一
        }
    }
    if(num==n-1)
        printf("%d\n%s",total,yes?"Yes":"No");
    else
        printf("No MST\n%d",n-num);
    return 0;
}
