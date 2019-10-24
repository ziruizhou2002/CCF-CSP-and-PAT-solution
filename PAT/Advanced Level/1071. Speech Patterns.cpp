#include<bits/stdc++.h>
using namespace std;
int main(){
    map<string,int>m;
    string s,t="";
    getline(cin,s);
    for(int i=0;i<s.size();++i)
        if(isalnum(s[i]))
            t+=tolower(s[i]);
        else if(t.length()>0){
            ++m[t];
            t="";
        }
    if(!t.empty())
        ++m[t];
    auto index=m.cbegin();
    for(auto i=m.cbegin();i!=m.cend();++i)
        if(i->second>index->second)
            index=i;
    cout<<index->first<<" "<<index->second;
    return 0;
}
