#include<bits/stdc++.h>
using namespace std;
int main(){
    int N,M,a;
    scanf("%d%d",&N,&M);
    int A[N+1]={0};
    while(M--)
        for(int i=1;i<=N;++i){
            scanf("%d",&a);
            A[i]+=a;
        }
    int MAX=max_element(A+1,A+N+1)-A;
    printf("%d\n",A[MAX]);
    for(auto i=1;i<=N;++i)
        if(A[i]==A[MAX])
            printf("%s%d",i==MAX?"":" ",i);
    return 0;
}
