#include<bits/stdc++.h>
using namespace std;
int main(){
    string A,Q="";
    int B,R=0;
    cin>>A>>B;
    for(char a:A){//大整数除法
        R=R*10+a-'0';
        Q+=R/B+'0';
        R%=B;
    }
    while(!Q.empty()&&Q.front()=='0')//删除Q首部的'0'
        Q.erase(Q.begin());
    printf("%s %d",Q.size()==0?"0":Q.c_str(),R);//Q为空先输出一个0再输出R
    return 0;
}
