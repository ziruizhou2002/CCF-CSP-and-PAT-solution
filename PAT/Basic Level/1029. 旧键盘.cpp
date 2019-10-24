#include<bits/stdc++.h>
using namespace std;
int main(){
    string s1,s2;
    cin>>s1>>s2;
    bool hashTable[128]={false};
    for(char c:s2)
        hashTable[toupper(c)]=true;
    for(int i=0;i<s1.size();++i)
        if(!hashTable[toupper(s1[i])]){
            printf("%c",toupper(s1[i]));
            hashTable[toupper(s1[i])]=true;
        }
    return 0;
}
