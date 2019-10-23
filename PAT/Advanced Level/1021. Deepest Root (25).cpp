#include<bits/stdc++.h>
using namespace std;
const int INF=1e4+5;//结点的最大数量
vector<vector<int>>graph(INF);//图
bool visit[INF];//是否已访问过
int maxlevel[INF],level[INF];//以数组小标为编号的结点为根节点时树的最大深度、当前根节点下所有节点的深度
void DFS(int v,int start){//深度优先遍历
    visit[v]=true;
    for(int i:graph[v])
        if(!visit[i]){
            level[i]=level[v]+1;//当前结点深度为其父节点深度+1
            maxlevel[start]=max(maxlevel[start],level[i]);//更新树的深度
            DFS(i,start);//递归遍历
        }
}
int main(){
    int N;
    scanf("%d",&N);
    for(int i=1;i<N;++i){
        int a,b;
        scanf("%d%d",&a,&b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int num=0;//记录连通分量数量
    for(int i=1;i<=N;++i)//深度优先遍历求连通分量数量
        if(!visit[i]){
            ++num;//每进行一次遍历连通分量数+1
            DFS(i,i);
        }
    if(num>1)
        printf("Error: %d components",num);//图不连通，输出连通分量数量
    else{//图连通
        for(int i=2;i<=N;++i){//i=1时已经进行一次深度优先遍历，故从2开始
            memset(level,0,sizeof(level));//将level数组元素均置为0
            memset(visit,false,sizeof(visit));//将visit数组元素均置为false
            DFS(i,i);//深度优先遍历
        }
        vector<int>v;//存储为根节点时使树的深度最大的结点
        int deepLevel=0;//查找所有为根节点时使树的深度最大的结点
        for(int i=1;i<=N;++i)
            if(maxlevel[i]>deepLevel){
                v.clear();
                v.push_back(i);
                deepLevel=maxlevel[i];
            }else if(maxlevel[i]==deepLevel)
                v.push_back(i);
        for(int i=0;i<v.size();++i)//输出
            printf("%d\n",v[i]);
    }
    return 0;
}
