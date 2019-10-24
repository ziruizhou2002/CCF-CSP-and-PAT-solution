#include<bits/stdc++.h>
using namespace std;
int main(){
  int M,N,A,B,P;
  scanf("%d%d%d%d%d",&M,&N,&A,&B,&P);
  int K[M][N];
  for(int i=0;i<M;++i)
    for(int j=0;j<N;++j){
      scanf("%d",&K[i][j]);
      if(K[i][j]>=A&&K[i][j]<=B)
        K[i][j]=P;
    }
  for(int i=0;i<M;++i){
    for(int j=0;j<N;++j)
      printf("%s%03d",j>0?" ":"",K[i][j]);
    printf("\n");
  }
  return 0;
} 
