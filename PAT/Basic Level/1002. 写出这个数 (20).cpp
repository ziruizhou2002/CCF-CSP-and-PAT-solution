#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int sum=0;
    for(int i=0;i<s.size();++i)
        sum+=s[i]-'0';
    s=to_string(sum);
    string temp[10]={
        "ling","yi","er","san","si","wu","liu","qi","ba","jiu"
    };
    for(int i=0;i<s.size();++i)
        printf("%s%s",i>0?" ":"",temp[s[i]-'0'].c_str());
    return 0;
}
