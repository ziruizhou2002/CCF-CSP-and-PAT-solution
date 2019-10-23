#include <bits/stdc++.h>
using namespace std;
int main(){
    int RGB[3];
    char trans[13];
    scanf("%d%d%d",&RGB[0],&RGB[1],&RGB[2]);
    for(int i=0;i<13;++i)
        trans[i]=i<10?i+'0':i-10+'A';
    printf("#");
    for(int i=0;i<3;++i)
        printf("%c%c",trans[RGB[i]/13],trans[RGB[i]%13]);
    return 0;
}
