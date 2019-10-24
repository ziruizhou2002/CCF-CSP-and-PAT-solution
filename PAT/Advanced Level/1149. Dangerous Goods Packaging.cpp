#include<bits/stdc++.h>
using namespace std;
int main(){
    int N,M,K,a,b;
    scanf("%d%d",&N,&M);
    unordered_map<int,unordered_set<int>>mp;
    for(int i=0;i<N;++i){
        scanf("%d%d",&a,&b);
        mp[a].insert(b);
    }
    while(M--){
        scanf("%d",&K);
        unordered_set<int>s;
        while(K--){
            scanf("%d",&a);
            s.insert(a);
        }
        bool flag=true;
        for(auto i:s)
            for(auto j:mp[i])
                if(s.find(j)!=s.end())
                    flag=false;
        printf("%s\n",flag?"Yes":"No");
    }
    return 0;
}
