#include<bits/stdc++.h>
using namespace std;
int main(){
    string input ;
    getline(cin,input);
    map<char,int>result;
    for(int i=0;input[i]!='\0';++i)
        ++result[input[i]];
    for(auto i=result.cbegin();i!=result.cend();++i){
        printf("%c:%d\n",i->first,i->second);
    }
    return 0;
}
