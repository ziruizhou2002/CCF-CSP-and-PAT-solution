#include<bits/stdc++.h>
using namespace std;
int main(){
    int NC,NP;
    scanf("%d",&NC);
    long long coupon[NC];
    for(int i=0;i<NC;++i)
        scanf("%lld",&coupon[i]);
    scanf("%d",&NP);
    long long product[NP];
    for(int i=0;i<NP;++i)
        scanf("%lld",&product[i]);
    sort(coupon,coupon+NC);
    sort(product,product+NP);
    long long result=0;
    for(int i=0;i<NP&&i<NC&&coupon[i]<0&&product[i]<0;++i)
        result+=coupon[i]*product[i];
    for(int i=NC-1,j=NP-1;i>=0&&j>=0&&coupon[i]>0&&product[j]>0;--i,--j)
        result+=coupon[i]*product[j];
    printf("%lld",result);
    return 0;
}
