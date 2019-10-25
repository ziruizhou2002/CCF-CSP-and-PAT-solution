#include<bits/stdc++.h>
using namespace std;
int main() {
    int N;
    scanf("%d",&N);
    unordered_map<int,int>um;
    while(N--){
        int a,b;
        scanf("%d%d",&a,&b);
        um[a]=b;
        um[b]=a;
    }
    scanf("%d",&N);
    set<int>s;
    while(N--){
        int a;
        scanf("%d",&a);
        if(um.find(a)==um.end())//如果该客人没有配偶
            s.insert(a);//直接将ID号加入set中
        else{
            auto i=s.find(um[a]);//在set中查找是否包含其配偶的ID
            if(i==s.cend())//不包含其配偶的ID
                s.insert(a);//直接将ID号加入set中
            else//包含其配偶的ID
                s.erase(i);//在set中删除其配偶的ID
        }
    }
    printf("%d\n",s.size());
    for(auto i=s.cbegin();i!=s.cend();++i)
        printf("%s%05d",i==s.cbegin()?"":" ",*i);
    return 0;
}
