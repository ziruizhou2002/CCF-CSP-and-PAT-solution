#include<bits/stdc++.h>
using namespace std;
int main() {
    int N;
    scanf("%d",&N);
    set<int>s;
    while(N--){
        int k,sum=0;
        scanf("%d",&k);
        //求出各位数字之和
        do{
            sum+=k%10;
            k/=10;
        }while(k!=0);
        s.insert(sum);
    }
    printf("%d\n",s.size());
    for(auto i=s.cbegin();i!=s.cend();++i)
        printf("%s%d",i==s.cbegin()?"":" ",*i);
    return 0;
}
