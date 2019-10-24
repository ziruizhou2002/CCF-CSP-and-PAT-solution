#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    vector<string>v;
    while(cin>>s)
        v.push_back(s);
    for(auto i=v.rbegin();i!=v.rend();++i)//反向迭代器
        printf("%s%s",i==v.rbegin()?"":" ",i->c_str());
    return 0;
}
