#include<bits/stdc++.h>
using namespace std;
int main(){
    string input;
    getline(cin,input);
    int Pnum[input.size()]={0};//Pnum数组表示该字符左侧字符P的数量
    for(int i=1;i<input.size();++i){//如果i-1位置是P字符，则Pnum[i]=Pnum[i-1]+1;否则Pnum[i]=Pnum[i-1]
        Pnum[i]=Pnum[i-1];
        if(input[i-1]=='P')
            ++Pnum[i];
    }
    int tnum=0,sumPAT=0;//tnum表示该字符右侧字符T的数量，sumPAT表示PAT字符串总数
    for(int i=input.size()-1;i>=0;--i)
        if(input[i]=='T')
            ++tnum;
        else if(input[i]=='A')
            sumPAT=(sumPAT+Pnum[i]*tnum)%1000000007;
    printf("%d\n",sumPAT);
    return 0;
}
