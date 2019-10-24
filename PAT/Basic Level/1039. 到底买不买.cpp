#include<bits/stdc++.h>
using namespace std;
int main(){
    int hashTable[128]={0};
    string s1,s2;
    cin>>s1>>s2;
    for(int i=0;i<s1.size();++i)
        ++hashTable[s1[i]];
    for(int i=0;i<s2.size();++i)
        --hashTable[s2[i]];
    int duo=0,shao=0;
    for(int i=0;i<128;++i)
        if(hashTable[i]>0)
            duo+=hashTable[i];
        else if(hashTable[i]<0)
            shao-=hashTable[i];
    if(shao==0)
        printf("Yes %d",duo);
    else
        printf("No %d",shao);
    return 0;
}
