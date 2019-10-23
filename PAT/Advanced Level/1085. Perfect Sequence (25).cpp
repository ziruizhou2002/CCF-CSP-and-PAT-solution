#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;
    long long p;
    scanf("%d%lld",&N,&p);
    long long a[N];
    for(int i=0;i<N;++i)
        scanf("%lld",&a[i]);
    sort(a,a+N);
    int maxLength=-1;
    for(int i=0;i<N;++i){
        int t=upper_bound(a+i+1,a+N,a[i]*p)-a-i;
        maxLength=max(t,maxLength);
    }
    printf("%d",maxLength);
    return 0;
}
