#include<bits/stdc++.h>
using namespace std;
int cmp(char a,char b){//得出甲乙谁胜谁负，甲胜返回1，乙胜返回-1，平局返回0
    if(a==b)
        return 0;
    else if((a=='B'&&b=='C')||(a=='C'&&b=='J')||(a=='J'&&b=='B'))
        return 1;
    else
        return -1;
}
char maxSheng(map<char,int>&sheng){//获取获胜最多的手势
    char maxChar='B';
    for(auto i=sheng.cbegin();i!=sheng.cend();++i)
        if(i->second>sheng[maxChar])
            maxChar=i->first;
    return maxChar;
}
int main(){
    int N;
    scanf("%d",&N);
    map<char,int>Asheng,Bsheng;//记录甲乙获胜的各手势次数
    int A[3]={0};//记录甲的胜平负次数
    for(int i=0;i<N;++i){
        char a,b;
        scanf("\n%c %c",&a,&b);
        int temp=cmp(a,b);
        if(temp==1){
            ++A[0];
            ++Asheng[a];
        }else if(temp==-1){
            ++A[2];
            ++Bsheng[b];
        }else
            ++A[1];
    }
    for(int i=0;i<3;++i)
        printf("%s%d",i>0?" ":"",A[i]);
    printf("\n");
    for(int i=2;i>=0;--i)
        printf("%s%d",i<2?" ":"",A[i]);
    printf("\n%c %c",maxSheng(Asheng),maxSheng(Bsheng));
    return 0;
}
