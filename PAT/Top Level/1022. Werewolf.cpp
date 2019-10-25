#include<bits/stdc++.h>
using namespace std;
int n,m,l,a[105];
set<int>ans;//存储狼人玩家编号
void DFS(int index,bool&f){//深度优先搜索,f标记是否有满足题设条件的情况
    if(index==0||ans.size()==m){//枚举到0号玩家或m个狼人玩家枚举完毕
        if(ans.size()==m){//m个狼人玩家枚举完毕
            int liars=0,wereliars=0;//撒谎的人的数量，狼人中撒谎的人的数量
            for(int i=1;i<=n;++i)//遍历a数组
                if((a[i]>0)^(ans.find(abs(a[i]))==ans.end())){//当前遍历到的玩家在撒谎
                    ++liars;//递增撒谎人的数量
                    if(ans.find(i)!=ans.end())//撒谎的人是狼人
                        ++wereliars;//递增狼人中撒谎的人的数量
                }
            if(liars==l&&wereliars>0&&wereliars<n)//满足题设条件，f设为true
                f=true;
        }
        return;//返回上层函数
    }
    ans.insert(index);//当前玩家是狼
    DFS(index-1,f);//继续枚举下一玩家
    if(f)//找到了符合题设条件的情况
        return;//返回上层函数
    ans.erase(index);//当前玩家不是狼
    DFS(index-1,f);//继续枚举下一玩家
}
int main(){
    scanf("%d%d%d",&n,&m,&l);
    for(int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    bool f=false;
    DFS(n,f);
    if(f)
        for(auto i=ans.rbegin();i!=ans.rend();++i)//倒序输出
            printf("%s%d",i==ans.rbegin()?"":" ",*i);
    else
        puts("No Solution");
    return 0;
}
