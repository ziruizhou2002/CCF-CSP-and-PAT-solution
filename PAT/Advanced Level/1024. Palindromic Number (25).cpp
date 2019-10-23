#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int K,step=0;
void add(){//大整数加法
    int num=0,i=0;
    for(;i<s1.size();++i){//开始进行大整数加法
        int k=s1[i]-'0'+s2[i]-'0'+num;//k储存对应位置下s1与s2的数字之和
        s1[i]=k%10+'0';//取各位数存入s1的相应位置
        num=k/10;//十位数作为进位
    }
    if(num!=0)//最终进位不为0
        s1+=num+'0';//添加到s1末尾
}
bool isPalindromic(string&s){
    for(int i=0,j=s.size()-1;i<j;++i,--j)//从字符串两端同时向中间遍历查看有没有不同字符，有返回false，若都相同返回true
        if(s[i]!=s[j])
            return false;
    return true;
}
int main(){
    cin>>s1>>K;
    for(;!isPalindromic(s1)&&step<K;++step){
        s2=s1;
        reverse(s1.begin(),s1.end());//翻转s1
        add();//进行加法
    }
    reverse(s1.begin(),s1.end());//将s1翻转，以便输出
    printf("%s\n%d",s1.c_str(),step);
}
