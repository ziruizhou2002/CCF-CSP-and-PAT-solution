#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;
    scanf("%d",&N);
    unordered_set<int>s;
    for(int i=1;i<=N;++i)
        s.insert(i/2+i/3+i/5);
    printf("%d",s.size());
    return 0;
}
