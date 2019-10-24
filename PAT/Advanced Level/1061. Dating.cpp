#include<bits/stdc++.h>
using namespace std;
int main(){
    unordered_map<char,string>week={//ABCDEFG七个字符到星期的映射
        {'A',"MON"},{'B',"TUE"},{'C',"WED"},{'D',"THU"},
        {'E',"FRI"},{'F',"SAT"},{'G',"SUN"}
    };
    unordered_map<char,int>hour;
    for(int i=0;i<24;++i)
        hour.insert({i<10?i+'0':i-10+'A',i});
    string input[4];
    for(int i=0;i<4;++i)
        getline(cin,input[i]);
    int cnt=0;
    for(int i=0;input[0][i]!='\0'&&input[1][i]!='\0';++i)
        if(input[0][i]==input[1][i])
            if(week.find(input[0][i])!=week.cend()&&cnt==0){
                cout<<week[input[0][i]]<<" ";
                ++cnt;
            }else if(hour.find(input[0][i])!=hour.cend()&&cnt==1){
                printf("%02d:",hour[input[0][i]]);
                ++cnt;
            }
    for(int i=0;input[2][i]!='\0';++i)
        if(isalpha(input[2][i])&&input[2][i]==input[3][i]){
            printf("%02d",i);
            break;
        }
    return 0;
}
