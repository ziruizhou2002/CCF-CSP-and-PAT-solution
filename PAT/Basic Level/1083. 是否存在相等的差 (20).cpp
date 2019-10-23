#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;
    scanf("%d",&N);
    map<int,int,greater<int>>m;//按键从大到小排序
    for(int i=1;i<=N;++i){
        int a;
        scanf("%d",&a);
        ++m[abs(i-a)];
    }
    for(auto i=m.cbegin();i!=m.cend();++i)
        if(i->second!=1)//有相等的差时才输出
            printf("%d %d\n",i->first,i->second);
    return 0;
}
