#include <bits/stdc++.h>
using namespace std;
int M,N,tree[1005];
int judge(){//判断大顶堆（返回1）、小顶堆（返回-1）、不是顶堆（返回0）
    if(tree[1]>tree[2]){
        for(int i=1;i<=N;++i)
            if((2*i<=N&&tree[i]<tree[i*2])||(2*i+1<=N&&tree[i]<tree[i*2+1]))
                return 0;
        return 1;
    }else{
        for(int i=1;i<=N;++i)
            if((2*i<=N&&tree[i]>tree[i*2])||(2*i+1<=N&&tree[i]>tree[i*2+1]))
                return 0;
        return -1;
    }
}
void postOrder(int root,bool&space){//后根遍历
    if(root<=N){
        postOrder(2*root,space);
        postOrder(2*root+1,space);
        printf("%s%d",space?" ":"",tree[root]);
        space=true;
    }
}
int main(){
    scanf("%d%d",&M,&N);
    while(M--){
        for(int i=1;i<N+1;++i)
            scanf("%d",&tree[i]);
        int k=judge();
        printf("%s\n",k>0?"Max Heap":k<0?"Min Heap":"Not Heap");
        bool space=false;
        postOrder(1,space);
        printf("\n");
    }
    return 0;
}
