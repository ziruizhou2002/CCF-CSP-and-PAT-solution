#include<bits/stdc++.h>
using namespace std;
int main(){
    int N,M,D,A=0,B=0;
    double e;
    scanf("%d%lf%d",&N,&e,&D);
    for(int i=0;i<N;++i){
        scanf("%d",&M);
        int temp=0;
        for(int j=0;j<M;++j){
            double a;
            scanf("%lf",&a);
            if(a<e)
                ++temp;
        }
        if(2*temp>M&&M>D)
            ++B;
        else if(2*temp>M&&M<=D)
            ++A;
    }
    printf("%.1f%% %.1f%%",(double)A/N*100,(double)B/N*100);
    return 0;
}
