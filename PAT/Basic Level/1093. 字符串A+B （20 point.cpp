#include<bits/stdc++.h>
using namespace std;
int main(){
    string str;
    unordered_set<char>s;
    while(getline(cin,str))
        for(char c:str)
            if(s.find(c)==s.end()){
                s.insert(c);
                putchar(c);
            }
    return 0;
}
