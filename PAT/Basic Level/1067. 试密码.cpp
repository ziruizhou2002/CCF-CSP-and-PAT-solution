#include<bits/stdc++.h>
using namespace std;
int main(){
    string password;
    int N;
    cin>>password>>N;
    getchar();
    while(true){
        string ss;
        getline(cin,ss);
        if(ss.size()==1&&ss[0]=='#')
            break;
        else
            if(ss==password){
                cout<<"Welcome in"<<endl;
                break;
            }else{
                cout<<"Wrong password: "<<ss<<endl;
                --N;
                if(N==0){
                    cout<<"Account locked"<<endl;
                    break;
                }
            }
    }
    return 0;
}
