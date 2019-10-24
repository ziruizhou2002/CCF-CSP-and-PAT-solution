#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    double a[n],sum=0.0;
    for(int i=0;i<n;++i)
        scanf("%lf",&a[i]);
    for(int i=0;i<n;++i){
//        下面这一写法是错的，因为n最大为10的5次方，(i+1)*(n-i)可能会超出int的存储范围，造成溢出
//        sum+=(i+1)*(n-i)*a[i];
        sum+=(i+1)*a[i]*(n-i);//这一写法是正确的，(i+1)*a[i]会转化成double型，不会造成溢出
    }
    printf("%.2f",sum);
    return 0;
}
