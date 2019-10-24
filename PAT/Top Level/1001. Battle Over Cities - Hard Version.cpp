#include<bits/stdc++.h>
using namespace std;
struct Edge{//高速公路
    int city1,city2,cost;//两端城市和公路代价
    Edge(int c1,int c2,int c3):city1(c1),city2(c2),cost(c3){}
};
int N,M,cost[505],father[505];//cost表示城市被攻占时保持其他城市连通需付出的代价，father代表并查集
vector<int>ans;//最终结果
vector<Edge>repairs,uses;//需要整修和正在使用的高速公路
int findFather(int x){//查找父亲结点并进行路径压缩
    if(x==father[x])
        return x;
    int temp=findFather(father[x]);
    father[x]=temp;
    return temp;
}
int countRoot(){//查找并查集1-N中存在几个集合
    int root=0;
    for(int i=1;i<=N;++i)
        if(father[i]==i)
            ++root;
    return root;
}
int main(){
    scanf("%d%d",&N,&M);
    for(int i=0;i<M;++i){
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        if(d==0)//该公路需要整修，放入repairs中
            repairs.push_back(Edge(a,b,c));
        else//该公路正常使用，放入uses中
            uses.push_back(Edge(a,b,c));
    }
    sort(repairs.begin(),repairs.end(),[](const Edge&e1,const Edge&e2){
        return e1.cost<e2.cost;
    });//按代价从小到大对repairs排序
    for(int i=1;i<=N;++i){
        iota(father,father+N+1,0);//初始化并查集
        for(Edge&e:uses){//遍历uses，将公路两端的城市并入一个集合
            int ua=findFather(e.city1),ub=findFather(e.city2);
            if(e.city1!=i&&e.city2!=i&&ua!=ub)
                father[ua]=ub;
        }
        for(Edge&e:repairs){//遍历repairs，将公路两端的城市并入一个集合，并更新cost数组相应元素
            int ua=findFather(e.city1),ub=findFather(e.city2);
            if(e.city1!=i&&e.city2!=i&&ua!=ub){
                father[ua]=ub;
                cost[i]+=e.cost;
            }
        }
        if(countRoot()>2)//如果并查集中存在多于2个集合，表示当前城市被攻占后其余城市不可能连通
            cost[i]=INT_MAX;//该城市被攻占付出的代价最大
    }
    int MAX=0;
    for(int i=1;i<=N;++i)//遍历cost数组求出代价最大的城市
        if(cost[i]!=0&&cost[i]>MAX){
            MAX=cost[i];
            ans.clear();
            ans.push_back(i);
        }else if(cost[i]!=0&&cost[i]==MAX)
            ans.push_back(i);
    if(ans.empty())
        printf("0\n");
    for(int i=0;i<ans.size();++i)
        printf("%s%d",i==0?"":" ",ans[i]);
    return 0;
}
