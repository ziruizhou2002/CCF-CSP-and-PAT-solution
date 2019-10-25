#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    long long ans=0,sum=0,mod=1000000007;
    vector<long long>v(s.size(),1);
    for(int i=v.size()-2;i>=0;--i)//计算每一位对应的所要乘的因子
        v[i]=(v[i+1]*10+1)%mod;
    for(int i=v.size()-1;i>=0;--i)//从低位向高位进行相乘并加和
        if(s[i]!='0'){
            sum+=v[i]*(s[i]-'0');
            ans=(ans+sum)%mod;
        }
    printf("%lld",ans);
    return 0;
}
