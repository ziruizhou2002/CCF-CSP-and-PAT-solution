#include<bits/stdc++.h>
using namespace std;
int main(){
    int N,M;
    scanf("%d",&N);
    int A[N+1]={0};
    for(int i=1;i<N+1;++i){
        scanf("%d",&A[i]);
        A[i]+=A[i-1];
    }
    scanf("%d",&M);
    while(M--){
        int a,b;
        scanf("%d%d",&a,&b);
        int k=abs(A[a-1]-A[b-1]);
        printf("%d\n",min(k,A[N]-k));
    }
    return 0;
}
