#include<bits/stdc++.h>
using namespace std;
int A[1005][1005];
int M,N,TOL;
int around[8][2]={//8个方向
    {-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}
};
bool outofBorder(int i,int j){//坐标是否越界
    if(i<0||i>=N||j<0||j>=M)
        return true;
    return false;
}
bool f(int i,int j){//判断与周围的像素点的差的绝对值是否超过TOL
    for(int k=0;k<8;++k){
        int ii=i+around[k][0],jj=j+around[k][1];
        if(!outofBorder(ii,jj))
            if(abs(A[i][j]-A[ii][jj])<=TOL)//差的绝对值小于等于TOL，直接返回false
                return false;
    }
    return true;
}
int main(){
    scanf("%d%d%d",&M,&N,&TOL);
    map<int,int>record;//记录每个像素点出现的次数
    for(int i=0;i<N;++i)
        for(int j=0;j<M;++j){
            scanf("%d",&A[i][j]);
            ++record[A[i][j]];
        }
    int num=0,ii=-1,jj=-1;
    for(int i=0;i<N;++i)
        for(int j=0;j<M;++j)
            if(record[A[i][j]]==1&&f(i,j)){//像素点值唯一且与周围的像素点的差的绝对值超过给定的TOL
                ii=i;
                jj=j;
                ++num;//满足条件的像素点数量递增
                if(num>1){//满足条件的像素点不唯一
                    printf("Not Unique");//输出"Not Unique"
                    return 0;
                }
            }
    if(num==0)
        printf("Not Exist");
    else
        printf("(%d, %d): %d",jj+1,ii+1,A[ii][jj]);
    return 0;
}
