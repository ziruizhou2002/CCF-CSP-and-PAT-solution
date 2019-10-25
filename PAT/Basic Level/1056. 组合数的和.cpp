#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;
    scanf("%d",&N);
    int A[N],sum=0;
    for(int i=0;i<N;++i)
        scanf("%d",&A[i]);
    for(int i=0;i<N;++i)
        for(int j=0;j<N;++j)
            if(j!=i)
                sum+=A[i]*10+A[j];
    printf("%d",sum);
    return 0;
}
