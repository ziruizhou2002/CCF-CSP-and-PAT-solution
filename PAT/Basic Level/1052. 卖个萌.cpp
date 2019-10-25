#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<vector<string>>emotion;//存储表情符号
    for(int i=0;i<3;++i){
        string line;
        getline(cin,line);//读取一行字符串
        vector<string>temp;//存储这一行字符串的表情符号
        for(int j=0;j<line.size();++j)
            if(line[j]=='[')//遇到'['字符
                for(int k=j+1;k<line.size();++k)//查找']'字符并将'['字符和']'字符之间的字符串存储到temp中
                    if(line[k] == ']') {
                        temp.push_back(line.substr(j+1, k-j-1));
                        break;
                    }
        emotion.push_back(temp);//将当前行的表情符号存储到emotion中
    }
    int N;
    cin>>N;
    while(N--){
        int a,b,c,d,e;
        cin>>a>>b>>c>>d>>e;
        //如果输入的下标不在[1,emotion[i].size()]范围内
        if(a>emotion[0].size()||b>emotion[1].size()||c>emotion[2].size()||d>emotion[1].size()||e>emotion[0].size()||a<1||b<1||c<1||d<1||e<1)
            cout<<"Are you kidding me? @\\/@"<<endl;//下标不合法，输出相应字符串
        else//否则输出表情
            cout<<emotion[0][a-1]<<"("<<emotion[1][b-1]<<emotion[2][c-1]<<emotion[1][d-1]<<")"<<emotion[0][e-1]<<endl;
    }
    return 0;
}
