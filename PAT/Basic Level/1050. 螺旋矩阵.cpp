#include<bits/stdc++.h>
using namespace std;
int main(){
    int N,m,n;//m记录行数，n记录列数
    scanf("%d",&N);
    int a[N];
    for(int i=0;i<N;++i)
        scanf("%d",&a[i]);
    sort(a,a+N);//排序，注意这是按从小到大的顺序排序
    for(n=(int)sqrt(N*1.0);n>=0;--n)//求出m,n
        if(N%n==0){
            m=N/n;
            break;
        }
    int matrix[m][n];//定义要填充的二维数组
    for(int i=0;i<m;++i)//初始化
        for(int j=0;j<n;++j)
            matrix[i][j]=0;
    
    int direction[4][2]={//定义左上右下的方向数组
        {0,1},{1,0},{0,-1},{-1,0}};
    int direct=0,i=0,j=-1;
    for(int k=N-1;k>=0;--k){ //进行填充
        int ii=i+direction[direct%4][0],jj=j+direction[direct%4][1];//记录将要填充的位置
        if(ii<0||ii>=m||jj<0||jj>=n||matrix[ii][jj]!=0)
            direct+=1;//如果将要填充的位置超出了matrix的维度或者已被填充,改变方向
        i+=direction[direct%4][0];
        j+=direction[direct%4][1];
        matrix[i][j]=a[k];
    }
    
    for(i=0;i<m;++i){//输出
        for(j=0;j<n;++j){
            if(j>0)
                printf(" ");
            printf("%d",matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}
