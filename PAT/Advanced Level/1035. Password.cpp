#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;
    scanf("%d",&N);
    string user,password;
    vector<pair<string,string>>account;//存储进行字符替换之后的user和对应的password
    unordered_map<char,char>trans={//存储字符和对应的替换字符的map
        {'1','@'},{'0','%'},{'l','L'},{'O','o'}
    };
    for(int i=0;i<N;++i){
        cin>>user>>password;
        bool f=false;//指示当前password是否已经经过替换
        for(int i=0;i<password.size();++i)
            if(trans.find(password[i])!=trans.cend()){//如果有要替换的字符
                password[i]=trans[password[i]];//替换字符
                f=true;
            }
        if(f)//如果password经过了替换
            account.push_back({user,password});//加入account中
    }
    if(account.empty()){
        if(N==1)
            printf("There is 1 account and no account is modified");
        else
            printf("There are %d accounts and no account is modified",N);
    }else{
        printf("%d\n",account.size());
        for(auto i=account.cbegin();i!=account.cend();++i){
            cout<<i->first<<" "<<i->second<<endl;
        }
    }
    return 0;
}
