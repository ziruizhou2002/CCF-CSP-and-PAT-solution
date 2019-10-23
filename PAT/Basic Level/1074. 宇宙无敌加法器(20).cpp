#include<bits/stdc++.h>
using namespace std;
int main(){
    string carry,n1,n2,n="";
    cin>>carry>>n1>>n2;
    int c=0,len=max(n1.size(),n2.size())+1;//为了循环中能直接处理最后进位的情况，令len为n1,n2最大长度+1
    reverse(carry.begin(),carry.end());
    reverse(n1.begin(),n1.end());
    reverse(n2.begin(),n2.end());
    for(int i=0;i<len;++i){
        int a=i<n1.size()?n1[i]-'0':0,b=i<n2.size()?n2[i]-'0':0,mod=10;
        if(i<carry.size()&&carry[i]!='0')
            mod=carry[i]-'0';
        n+=(a+b+c)%mod+'0';
        c=(a+b+c)/mod;
    }
    while(n.size()>1&&n.back()=='0')//删除字符串尾部的'0'字符
        n.pop_back();
    reverse(n.begin(),n.end());
    puts(n.c_str());
    return 0;
}
