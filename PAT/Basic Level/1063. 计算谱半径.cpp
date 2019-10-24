#include<bits/stdc++.h>
using namespace std;
int main() {
    int N;
    scanf("%d",&N);
    double MAX=0.0;
    for(int i=0;i<N;++i){
        int a,b;
        scanf("%d%d",&a,&b);
        double t=sqrt(1.0*(a*a+b*b));
        MAX=max(MAX,t);
    }
    printf("%.2f",MAX);
    return 0;
}
