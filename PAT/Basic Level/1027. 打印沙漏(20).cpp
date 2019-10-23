//二维数组输出方式
#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;
    char c;
    scanf("%d %c",&N,&c);
    //获取漏斗上半部分行数mid，总行数row
    int mid=(int)sqrt((N+1)/2*1.0);
    int row=2*mid-1;
    //定义二维数组
    char result[row][row];
    //初始化二维数组
    for(int i=0;i<row;++i)
        for(int j=0;j<row;++j)
            result[i][j]=' ';
    //填充二维数组
    for(int i=0;i<mid;++i)
        for(int j=mid-1-i;j<mid+i;++j)
            result[mid-1-i][j]=result[mid-1+i][j]=c;
    //输出二维数组
    for(int i=0;i<row;++i){
        bool output=true;
        for(int j=0;j<row;++j){
            if(result[i][j]==' '&&!output)
                break;
            if(result[i][j]!=' '){
                output=false;
            }
            printf("%c",result[i][j]);
        }
        printf("\n");
    }
    //输出剩余字符个数
    printf("%d",N-2*mid*mid+1);
    return 0;
}


//直接输出方式
#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;
    char c;
    scanf("%d %c",&N,&c);
    //获取漏斗上半部分行数mid，总行数row
    int mid=(int)sqrt((N+1)/2*1.0);
    int row=2*mid-1;
    //输出上半部分
    int space=0;
    for(int i=row;i>=1;i-=2){
        for(int j=0;j<space;++j)
            printf(" ");
        ++space;
        for(int j=0;j<i;++j)
            printf("%c",c);
        printf("\n");
    }
    --space;
    //输出下半部分
    for(int i=3;i<=row;i+=2){
        --space;
        for(int j=0;j<space;++j)
            printf(" ");
        for(int j=0;j<i;++j)
            printf("%c",c);
        printf("\n");
    }
    //输出剩余字符个数
    printf("%d",N-2*mid*mid+1);
    return 0;
}
