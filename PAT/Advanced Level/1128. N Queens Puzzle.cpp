#include<bits/stdc++.h>
using namespace std;
int K,N,A[1005];
bool judge(){
    for(int i=1;i<N+1;++i)
        for(int j=i+1;j<N+1;++j)
            if(A[j]==A[i]||abs(j-i)==abs(A[j]-A[i]))
                return false;
    return true;
}
int main(){
    scanf("%d",&K);
    while(K--){
        scanf("%d",&N);
        for(int i=1;i<N+1;++i)
            scanf("%d",&A[i]);
        printf("%s\n",judge()?"YES":"NO");
    }
    return 0;
}
