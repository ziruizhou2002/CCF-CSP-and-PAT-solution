#include<bits/stdc++.h>
using namespace std;
int main(){
    string input="";
    int hashTable[128]={0};
    getline(cin,input);
    for(char a:input)
        if(isalpha(a))
            ++hashTable[tolower(a)];
    int maxIndex=max_element(hashTable,hashTable+128)-hashTable;
    printf("%c %d",maxIndex,hashTable[maxIndex]);
    return 0;
}
