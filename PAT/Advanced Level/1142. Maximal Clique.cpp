#include<bits/stdc++.h>
using namespace std;
const int MAXV=205;
vector<vector<int>>graph(MAXV);
int main()
{
    int Nv,Ne,M;
    scanf("%d%d",&Nv,&Ne);
    while(Ne--){//读取无向图的边
        int a,b;
        scanf("%d%d",&a,&b);
        graph[b].push_back(a);
        graph[a].push_back(b);
    }
    scanf("%d",&M);
    while(M--){
        int K;
        scanf("%d",&K);
        unordered_map<int,int>record;//键表示读取的点集能够到达的顶点编号，值表示读取的点集有多少个点能到达键代表的顶点
        vector<int>v(K);//储存读入的点集中各个顶点编号
        for(int i=0;i<K;++i){
            scanf("%d",&v[i]);
            ++record[v[i]];//递增当前点在map中对应的值
            for(int ii:graph[v[i]])//遍历其能到达的顶点
                ++record[ii];//递增能够到达的点在map中对应的值
        }
        bool clique=true,maximal=true;
        for(auto i=record.cbegin();i!=record.cend()&&clique;++i){//遍历map
            auto j=find(v.cbegin(),v.cend(),i->first);
            if(j!=v.cend()&&i->second!=K)//当前map的键代表的顶点编号在vector中并且其值不等于K，则该点集不是Clique
                clique=false;
            else if(j==v.cend()&&i->second==K)//当前map的键代表的顶点编号不在vector中并且其值等于K，则该点集不是maximal Clique
                maximal=false;
        }
        //输出
        if(!clique)
            printf("Not a Clique\n");
        else if(!maximal)
            printf("Not Maximal\n");
        else
            printf("Yes\n");
    }
    return 0;
}
