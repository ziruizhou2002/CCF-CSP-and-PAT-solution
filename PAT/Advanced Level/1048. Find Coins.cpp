#include<bits/stdc++.h>
using namespace std;
int main(){
    int N,M;
    scanf("%d%d",&N,&M);
    map<int,int>m;
    while(N--){
        int a;
        scanf("%d",&a);
        ++m[a];
    }
    for(auto i=m.cbegin();i!=m.cend();++i){
        if((M-i->first==i->first&&i->second>=2)||(M-i->first!=i->first&&m.find(M-i->first)!=m.cend())){
            printf("%d %d",i->first,M-i->first);
            return 0;
        }
    }
    printf("No Solution");
    return 0;
}
