#include<bits/stdc++.h>
using namespace std;
int main(){
    string A,B,C="",trans="0123456789JQK";
    cin>>A>>B;
    reverse(A.begin(),A.end());
    reverse(B.begin(),B.end());
    int len=max(A.size(),B.size());//取A、B字符串中最长的长度
    for(int i=0;i<len;++i){
        int numA=i<A.size()?A[i]-'0':0;//记录相应A字符串位置的数字，如果超过了A的长度，记0
        int numB=i<B.size()?B[i]-'0':0;//记录相应B字符串位置的数字，如果超过了B的长度，记0
        if(i%2==0)//字符串下标从0开始，而题目中个位从1开始编号，所以对于奇数位偶数位的处理要反过来
            C+=trans[(numA+numB)%13];
        else{
            int t=numB-numA;
            if(t<0)
                t+=10;
            C+=t+'0';
        }
    }
    reverse(C.begin(),C.end());//翻转C字符串
    puts(C.c_str());//输出
    return 0;
}
