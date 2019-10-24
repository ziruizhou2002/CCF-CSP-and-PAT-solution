#include<bits/stdc++.h>
using namespace std;
int main(){
    int N,M,K;
    scanf("%d",&N);
    unordered_set<int>sets[N+1];
    for(int i=1;i<=N;++i){
        scanf("%d",&M);
        while(M--){
            int a;
            scanf("%d",&a);
            sets[i].insert(a);
        }
    }
    scanf("%d",&K);
    while(K--){
        int a,b,num=0;
        scanf("%d%d",&a,&b);
        for(auto i=sets[a].cbegin();i!=sets[a].cend();++i)
            if(sets[b].find(*i)!=sets[b].cend())
                ++num;
        printf("%.1f%%\n",(double)num/(sets[a].size()+sets[b].size()-num)*100);
    }
    return 0;
}
