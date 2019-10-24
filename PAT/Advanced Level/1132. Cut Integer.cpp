#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;
    scanf("%d",&N);
    while(N--){
        long long z,a,b;
        scanf("%lld",&z);
        string s=to_string(z);//将long long 转换成字符串
        a=stoll(s.substr(0,s.size()/2));//将字符串转换成long long 
        b=stoll(s.substr(s.size()/2));
        if(a*b!=0&&z%(a*b)==0)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
