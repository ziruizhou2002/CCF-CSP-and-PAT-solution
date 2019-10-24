#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,ans=0;//ans存储最终结果peak number的下标
    scanf("%d",&n);
    int A[n+1],dpleft[n+1]={0},dpRight[n+1]={0};//将dpleft、dpRight均初始化为0
    for(int i=1;i<=n;++i)
        scanf("%d",&A[i]);
    for(int i=1;i<=n;++i)//求解dpLeft
        for(int j=1;j<i;++j)
            if(A[i]>A[j])
                dpleft[i]=max(dpleft[i],dpleft[j]+1);
    for(int i=n;i>=1;--i)//求解dpRight
        for(int j=n;j>i;--j)
            if(A[i]>A[j])
                dpRight[i]=max(dpRight[i],dpRight[j]+1);
    for(int i=1;i<=n;++i)//求解ans
        if(dpleft[i]>0&&dpRight[i]>0&&(dpleft[i]+dpRight[i]>dpleft[ans]+dpRight[ans]||
           (dpleft[i]+dpRight[i]==dpleft[ans]+dpRight[ans]
            &&abs(dpleft[i]-dpRight[i])<abs(dpleft[ans]-dpRight[ans]))))
            ans=i;
    if(ans==0)
        puts("No peak shape");
    else
        printf("%d %d %d",dpleft[ans]+dpRight[ans]+1,ans,A[ans]);
    return 0;
}
