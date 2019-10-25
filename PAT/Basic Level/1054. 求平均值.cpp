#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;
    scanf("%d",&N);
    double sum=0.0;//合法输入的所有数据之和
    int num=0;//合法输入的数据数量
    char s[100],ss[100];
    while(N--){
        scanf("%s",s);//按字符串读入
        double k=0.0;
        sscanf(s,"%lf",&k);//将这一字符串输出为一个浮点数
        sprintf(ss,"%.2f",k);//将这一浮点数输出为一个有两位小数的字符串
        bool flag=true;//判断两个字符串是否一致
        for(int i=0;s[i]!='\0'&&flag;++i)
            if(s[i]!=ss[i])
                flag=false;
        if(!flag||k>1000||k<-1000){//不是输出指定字符串
            printf("ERROR: %s is not a legal number\n",s);
        }else{//是合法输入进行累加
            ++num;
            sum+=k;
        }
    }
    if(num==0)
        printf("The average of 0 numbers is Undefined");
    else if(num==1)
        printf("The average of 1 number is %.2f",sum);
    else
        printf("The average of %d numbers is %.2f",num,sum/num);
    return 0;
}
