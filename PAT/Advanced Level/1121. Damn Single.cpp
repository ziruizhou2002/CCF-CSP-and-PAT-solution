#include<bits/stdc++.h>
using namespace std;
const int INF=1e5;
int hashTable[INF];//辅助数组
int main() {
    int N;
    scanf("%d",&N);
    memset(hashTable,-1,sizeof(hashTable));//将hashTable初始化为-1
    while(N--){
        int a,b;
        scanf("%d%d",&a,&b);
        hashTable[a]=b;
        hashTable[b]=a;
    }
    scanf("%d",&N);
    set<int>s;
    while(N--){
        int a;
        scanf("%d",&a);
        if(hashTable[a]==-1)//如果该客人没有配偶
            s.insert(a);//直接将ID号加入set中
        else{
            auto i=s.find(hashTable[a]);//在set中查找是否包含其配偶的ID
            if(i==s.cend())//不包含其配偶的ID
                s.insert(a);//直接将ID号加入set中
            else//包含其配偶的ID
                s.erase(i);//在set中删除其配偶的ID
        }
    }
    //输出
    printf("%d\n",s.size());
    for(auto i=s.cbegin();i!=s.cend();++i)
        printf("%s%05d",i==s.cbegin()?"":" ",*i);
    return 0;
}
