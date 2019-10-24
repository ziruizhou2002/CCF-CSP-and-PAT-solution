#include<bits/stdc++.h>
using namespace std;
int main(){
    int K1,K2;
    scanf("%d",&K1);
    int A1[K1+1];
    for(int i=0;i<K1;++i)
        scanf("%d",&A1[i]);
    scanf("%d",&K2);
    A1[K1]==INT_MAX;//保证扫描过程中，不会出现一个序列已经扫描完但是还没有得到结果的情况下数组访问越界的问题
    int i=0,j=1,a,result;//i,j分别作为两个序列的索引，a存储第二个序列的当前处理的数字，result储存最后结果
    scanf("%d",&a);//读取第二序列第一个数
    for(int k=0;k<(K1+K2+1)/2;++k)//给result赋值为两个序列当前位置的数中较小的数，并将指向较小的数的索引右移一位，重复该操作直至找到两个数组第(K1+k2+1)/2个数即为最后结果
        if(A1[i]<a)//第一个序列数字比第二个序列数字小
            result=A1[i++];//赋值为第一个序列的数字
        else{//第一个序列数字比第二个序列数字大
            result=a;//赋值为第二个序列的数字
            a=INT_MAX;//第二个序列的当前数字赋值为最大值
            if(j<K2)//第二个序列数据还未读取完
                scanf("%d",&a);//读取下一个数据
            ++j;//递增第二个序列的索引
        }
    printf("%d",result);
    return 0;
}
