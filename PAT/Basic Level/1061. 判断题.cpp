#include<bits/stdc++.h>
using namespace std;
int main() {
    int N,M;
    scanf("%d%d",&N,&M);
    int A[M],B[M];
    for(int i=0;i<M;++i)
        scanf("%d",&A[i]);
    for(int i=0;i<M;++i)
        scanf("%d",&B[i]);
    for(int i=0;i<N;++i){
        int score=0;
        for(int j=0;j<M;++j){
            int k;
            scanf("%d",&k);
            if(k==B[j])
                score+=A[j];
        }
        printf("%d\n",score);
    }
    return 0;
}
