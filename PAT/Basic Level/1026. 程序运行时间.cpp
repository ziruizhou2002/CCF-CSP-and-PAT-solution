#include<bits/stdc++.h>
using namespace std;
int main(){
    int c1,c2;
    scanf("%d%d",&c1,&c2);
    c2=(int)round((c2-c1)/100.0);//c2、c1两者作差化成秒并四舍五入（可以调用标准库中的round函数）
    printf("%02d:%02d:%02d",c2/3600,c2/60%60,c2%60);//输出需保证时分秒均为2位
    return 0;
}
