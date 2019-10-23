#include<bits/stdc++.h>
using namespace std;
int N,K,P,sum=0;
vector<int>result,temp,powValue;
void initPow(){//对不超过N的n^P进行打表，并把结果存储到powValue中
    powValue.push_back(0);
    while(powValue.back()*P<N)
        powValue.push_back(pow(powValue.size()*1.0,P*1.0));
}
void DFS(int num,int nowK,int nowSum,int nowPowSum){//DFS递归
    if(nowK>=K||nowPowSum>=N){
        if(nowK==K&&nowPowSum==N&&nowSum>sum){//当前序列的和比result的和大，更新相关信息
            result=temp;
            sum=nowSum;
        }
        return;
    }
    if(num>=1){
        temp.push_back(num);
        DFS(num,nowK+1,nowSum+num,nowPowSum+powValue[num]);//选择当前的数
        temp.pop_back();
        DFS(num-1,nowK,nowSum,nowPowSum);//没有选择当前的数，向更小的数进行选择
    }
}
int main(){
    scanf("%d%d%d",&N,&K,&P);
    initPow();
    DFS(powValue.size()-1,0,0,0);//从大到小进行选择
    if(result.size()==K){
        printf("%d =",N);
        for(int i=0;i<result.size();++i)
            printf(" %d^%d%s",result[i],P,i<result.size()-1?" +":"");
    }else
        printf("Impossible");
    return 0;
}
