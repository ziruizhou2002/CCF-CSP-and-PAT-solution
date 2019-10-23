#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;
    scanf("%d",&N);
    int a[6]={0},t[6]={0};//a为储存a1-a5的数组，t为记录符合条件的数的个数的数组
    int t2=1;//辅助帮助计算a2交替求和的临时变量
    for(int i=0;i<N;++i){
        int temp;
        scanf("%d",&temp);
        if(temp%5==0&&temp%2==0){
            a[1]+=temp;
            ++t[1];
        }else if(temp%5==1){
            a[2]+=t2*temp;
            t2=-t2;
            ++t[2];
        }else if(temp%5==2){
            ++a[3];
            ++t[3];
        }else if(temp%5==3){
            a[4]+=temp;
            ++t[4];
        }else if(temp%5==4&&temp>a[5]){
            a[5]=temp;
            ++t[5];
        }
    }
    for(int i=1;i<6;++i){
        printf("%s",i>1?" ":"");
        if(t[i]>0)//printf("%.*f",max,i)表示输出有max位小数的i
            printf("%.*f",i!=4?0:1,i!=4?(double)a[i]:(double)a[i]/t[i]);
        else
            printf("N");
    }
    return 0;
}
