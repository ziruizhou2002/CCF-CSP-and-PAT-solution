#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[3]={0},b[3]={0};
    scanf("%d.%d.%d %d.%d.%d",&a[0],&a[1],&a[2],&b[0],&b[1],&b[2]);
    long long sum=((long long)a[0]*17+a[1])*29+a[2];//有可能超出int存储范围，最好用long long存储
    sum+=((long long)b[0]*17+b[1])*29+b[2];
    printf("%lld.%lld.%lld",sum/(29*17),sum/29%17,sum%29);
    return 0;
}
