#include<bits/stdc++.h>
using namespace std;
int main(){
    string input;
    cin>>input;
    for(int i=0;i<input.size();++i)
        for(int ii=0;ii<input[i]-'0';++ii)
            if(i==input.size()-3)
                printf("B");
            else if(i==input.size()-2)
                printf("S");
            else if(i==input.size()-1)
                printf("%d",ii+1);
    return 0;
}
