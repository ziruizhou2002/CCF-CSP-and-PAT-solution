#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;
    scanf("%d",&N);
    string id;
    int weight[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};//前17位权重
    char temp[11]={'1','0','X','9','8','7','6','5','4','3','2'};//模11取余后的字符
    bool output=false;//表示是否有错误的身份号码输出
    getchar();//吸收N后面的换行符
    for(int i=0;i<N;++i){
        getline(cin,id);
        int sum=0;
        bool f=false;
        for(int i=0;i<17;++i){
            if(!isdigit(id[i])){//检测前17位是否有非数字字符
                cout<<id<<endl;
                output=true;
                f=true;
                break;
            }else
                sum+=weight[i]*(id[i]-'0');
        }
        if(!f&&id[17]!=temp[sum%11]){//检测最后一位校验码是否正确
            output=true;
            cout<<id<<endl;
        }
    }
    if(!output)//如果目前没有任何错误的身份号码输出，则输出All passed
        printf("All passed");
    return 0;
}
