#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[]){
    int a,b;
    cin>>a>>b;
    if(a+b<0)
        cout<<"-";
    string s=to_string(abs(a+b));
    vector<string>v;
    for(int i=s.size();i>0;i-=3)
        v.push_back(i>=3?s.substr(i-3,3):s.substr(0,i));
    for(int i=v.size()-1;i>=0;--i)
        printf("%s%s",v[i].c_str(),i>0?",":"");
}
