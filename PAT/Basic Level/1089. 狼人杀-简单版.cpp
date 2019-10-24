#include<bits/stdc++.h>
using namespace std;
int main(){
    int N,A[105];//数组A存储每个玩家的说法
    scanf("%d",&N);
    for(int i=1;i<=N;++i)
        scanf("%d",&A[i]);
    for(int i=1;i<=N;++i)//枚举i号玩家是狼人
        for(int j=i+1;j<=N;++j){//枚举j号玩家是狼人
            int lier=0,wolfLier=0;//lier表示说谎的玩家个数，wolfLier表示说谎的狼人个数
            for(int k=1;k<=N;++k)//枚举N个玩家，判断其是否说谎
                if((abs(A[k])==i||abs(A[k])==j)^A[k]<0){//满足表达式是为说谎
                    ++lier;//递增说谎玩家人数
                    if(k==i||k==j)//说谎的玩家是狼
                        ++wolfLier;//递增说谎的狼人个数
                }
            if(lier==2&&wolfLier==1){//有2个说谎的玩家，1个说谎的狼人
                printf("%d %d",i,j);//输出
                return 0;
            }
        }
    puts("No Solution");//无解输出No Solution
    
}
