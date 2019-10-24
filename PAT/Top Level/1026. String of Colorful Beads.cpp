#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    int value[n+1],beads[n];
    for(int i=1;i<=n;++i)
        scanf("%d",&value[i]);
    for(int i=0;i<n;++i)
        scanf("%d",&beads[i]);
    unordered_set<int>s;
    int temp=0,ans=0,left=-1,right=-1;
    for(int i=0,j=0;i<n;++i){//不断更新左界
        for(;j<=n;++j){//更新右界
            if(j==n||s.find(beads[j])!=s.end()){//j到达序列末尾或者珠子颜色重复
                if(j-i>right-left+1||(j-i==right-left+1&&temp>ans)){//当前子序列长度更长或总价值更大
                    ans=temp;
                    left=i;
                    right=j-1;
                }
                break;//跳出for循环
            }
            s.insert(beads[j]);//将当前珠子颜色插入到s中
            temp+=value[beads[j]];//更新当前子序列总价值
        }
        s.erase(beads[i]);//删除左界珠子颜色
        temp-=value[beads[i]];//减去左界珠子价值
    }
    printf("%d %d %d",ans,left,right);
    return 0;
}
