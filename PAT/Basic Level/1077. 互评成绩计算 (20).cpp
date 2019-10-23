#include<bits/stdc++.h>
using namespace std;
int main(){
    int N,M;
    scanf("%d%d",&N,&M);
    for(int i=0;i<N;++i){
        double G1=0.0,G2;
        vector<int>g1;
        scanf("%lf",&G2);
        for(int j=0;j<N-1;++j){
            int k;
            scanf("%d",&k);
            if(0<=k&&k<=M)
                g1.push_back(k);
        }
        sort(g1.begin(),g1.end());
        for(int j=1;j<g1.size()-1;++j)
            G1+=g1[j]*1.0;
        printf("%.0f\n",round((G2+G1/(g1.size()-2))/2));
    }
    return 0;
}
