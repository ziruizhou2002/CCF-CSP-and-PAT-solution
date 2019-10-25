#include<bits/stdc++.h>
using namespace std;
int main(){
    string str;
    int N,k;
    cin>>str>>N;
    for(int i=1;i<N;++i){
        string s="";//临时储存结果的字符串
        for(int j=0;j<str.size();j=k){
            for(k=j;k<str.size()&&str[k]==str[j];++k);//找到与str[j]字符不同的字符的位置
            s+=str[j]+to_string(k-j);//在s末尾加上str[j]字符和连续str[j]字符的个数
        }
        str=s;
    }
    cout<<str;
    return 0;
}
