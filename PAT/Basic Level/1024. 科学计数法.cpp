#include<bits/stdc++.h>
using namespace std;
int main(){
    string s,s1="";
    cin>>s;//读取输入的科学计数法形式的字符串
    if(s[0]=='-')//如果是负数先输出-号
        cout<<"-";
    int i=1;
    while(s[i]!='E'){//将小数部分删去小数点存储到s1字符串中
        if(s[i]!='.')
            s1+=s[i];
        ++i;
    }
    i=stoi(s.substr(++i));//将指数部分存储为一个整型变量
    if(i<0){//i为负,输出“0.000XXX”的形式，其中小数点后连续的0的个数为i-1，而后面XXX部分即为s1整个字符串
        cout<<"0.";
        i=abs(i)-1;
        for(int j=0;j<i;++j)
            cout<<"0";
        cout<<s1;
    }else//i为正，分两种情况
        if(i>=s1.size()-1){//如果i>=s1.size()-1，先输出s1整个字符串，然后输出i+1-s1.size()个0
            cout<<s1;
            for(int j=0;j<i+1-s1.size();++j)
                cout<<"0";
        }else//否则输出s1整个字符串，并在输出s1的第i个字符之后输出一个小数点
            for(int j=0;j<s1.size();++j){
                cout<<s1[j];
                if(j==i)
                    cout<<".";
            }
    return 0;
}
