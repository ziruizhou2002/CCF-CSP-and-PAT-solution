#include<bits/stdc++.h>
using namespace std;
int main(){
    int M,K;
    scanf("%d",&M);
    while(M--){
        scanf("%d",&K);
        int i,N;
        for(i=10;K/i!=0;i*=10);
        for(N=1;N<10&&K*K*N%i!=K;++N);
        if(N==10)
            puts("No");
        else
            printf("%d %d\n",N,K*K*N);
    }
    return 0;
}
