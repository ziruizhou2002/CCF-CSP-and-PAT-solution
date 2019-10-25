#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;
    scanf("%d%*c",&N);
    while(N--){
        bool digit=false,letter=false,legal=true;
        string str;
        getline(cin,str);
        if(str.size()<6){
            puts("Your password is tai duan le.");
            continue;
        }
        for(int i=0;i<str.size()&&legal;++i)
            if(!isalnum(str[i])&&str[i]!='.')
                legal=false;
            else if(isalpha(str[i]))
                letter=true;
            else if(isdigit(str[i]))
                digit=true;
        if(!legal)
            puts("Your password is tai luan le.");
        else if(letter&&digit)
            puts("Your password is wan mei.");
        else if(!digit)
            puts("Your password needs shu zi.");
        else if(!letter)
            puts("Your password needs zi mu.");
    }
    return 0;
}
