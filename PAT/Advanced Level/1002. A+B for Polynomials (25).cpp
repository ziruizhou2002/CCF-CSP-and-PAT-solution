#include<bits/stdc++.h>
using namespace std;
double coefficient[1005]={0};
int main(){
    int K;
    scanf("%d",&K);
    while(K--){
        int a;
        double b;
        scanf("%d%lf",&a,&b);
        coefficient[a]+=b;
    }
    scanf("%d",&K);
    while(K--){
        int a;
        double b;
        scanf("%d%lf",&a,&b);
        coefficient[a]+=b;
    }
    int size=0;
    for(int i=0;i<1005;++i)
        if(coefficient[i]!=0)
            ++size;
    printf("%d",size);
    for(int i=1005;i>=0;--i)
        if(coefficient[i]!=0)
            printf(" %d %.1f",i,coefficient[i]);
    return 0;
}
