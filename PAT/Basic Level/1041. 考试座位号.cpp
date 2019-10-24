#include<bits/stdc++.h>
using namespace std;
int main(){
    int N,b,c;
    scanf("%d",&N);
    long long id[1005],testid[1005],a;
    for(int i=0;i<N;++i){
        scanf("%lld%d%d",&a,&b,&c);
        id[b]=a;
        testid[b]=c;
    }
    scanf("%d",&N);
    while(N--){
        scanf("%d",&b);
        printf("%014lld %d\n",id[b],testid[b]);
    }
    return 0;
}
