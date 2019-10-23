#include <bits/stdc++.h>
using namespace std;
int main(){
    int N,a;
    scanf("%d",&N);
    unordered_set<int>s;
    while(N--){
        scanf("%d",&a);
        s.insert(a);
    }
    for(int i=1;true;++i)
        if(s.find(i)==s.cend()){
            printf("%d",i);
            break;
        }
    return 0;
}
