#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>>edges;//存储边
int color[10005];//存储顶点颜色
int main(){
    int N,M,K;
    scanf("%d%d",&N,&M);
    while(M--){
        int a,b;
        scanf("%d%d",&a,&b);
        edges.push_back({a,b});
    }
    scanf("%d",&K);
    while(K--){
        unordered_set<int>colors;//对所有颜色进行去重
        for(int i=0;i<N;++i){
            scanf("%d",&color[i]);
            colors.insert(color[i]);
        }
        bool f=true;
        for(int i=0;i<edges.size()&&f;++i)
            if(color[edges[i].first]==color[edges[i].second])
                f=false;
        if(f)
            printf("%d-coloring\n",colors.size());
        else
            puts("No");
    }
    return 0;
}
