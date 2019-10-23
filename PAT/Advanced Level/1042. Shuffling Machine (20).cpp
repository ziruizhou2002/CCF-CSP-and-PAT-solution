#include<bits/stdc++.h>
using namespace std;
int main(){
    int *n1=new int[54],*n2=new int[54];//定义两个动态数组
    int order[54],times;//存储给定的顺序、要重复移动几次
    scanf("%d",×);
    for(int i=0;i<54;++i){//读取数据并将n1初始化为0~53这54个数字
        scanf("%d",&order[i]);
        n1[i]=i;
    }
    while(times--){
        for(int i=0;i<54;++i)//进行移动
            n2[order[i]-1]=n1[i];
        swap(n1,n2);//交换两个指针
    }
    char head[6]="SHCDJ";//定义字符数组
    for(int i=0;i<54;++i)
        printf("%s%c%d",i>0?" ":"",head[n1[i]/13],n1[i]%13+1);
    return 0;
}
