#include<bits/stdc++.h>
using namespace std;
int N,M,S,weight[105];
vector<int> tree[105],path;
void DFS(int v,int pathWeight){
    pathWeight+=weight[v];
    if(pathWeight>S||(pathWeight==S&&!tree[v].empty()))
        return;
    path.push_back(v);
    if(pathWeight==S)
        for(int i=0;i<path.size();++i)
            printf("%s%d%s",i>0?" ":"",weight[path[i]],i==path.size()-1?"\n":"");
    for(int i:tree[v])
        DFS(i,pathWeight);
    path.pop_back();
}
int main(){
    scanf("%d%d%d",&N,&M,&S);
    for(int i=0;i<N;++i)
        scanf("%d",&weight[i]);
    while(M--){
        int id,K,a;
        scanf("%d%d",&id,&K);
        while(K--){
            scanf("%d",&a);
            tree[id].push_back(a);
        }
        sort(tree[id].begin(),tree[id].end(),[](int a,int b){
            return weight[a]>weight[b];
        });
    }
    DFS(0,0);
    return 0;
}
