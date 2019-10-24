#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;
    scanf("%d",&N);
    int A[N];
    for(int i=0;i<N;++i)
        scanf("%d",&A[i]);
    sort(A,A+N);
    int s1=accumulate(A,A+N/2,0),s2=accumulate(A+N/2,A+N,0);
    printf("%d %d",N%2,s2-s1);
    return 0;
}
