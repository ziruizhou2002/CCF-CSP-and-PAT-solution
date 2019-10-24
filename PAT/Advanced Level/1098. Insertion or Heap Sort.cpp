# include<bits/stdc++.h>
using namespace std;
int N,A[105],initial[105],target[105];
void down(int index,int n){//下滤算法
    int t=A[index];
    while(2*index+1<n){//有儿子结点
        int child=2*index+1;
        if(child+1<n&&A[child]<A[child+1])//找到值比较大的儿子结点
            ++child;
        if(A[child]>t){//如果儿子结点的值大于父亲结点的值
            A[index]=A[child];//儿子结点的值移动到父亲结点
            index=child;
        }else
            break;
    }
    A[index]=t;
}
int main(){
    scanf("%d",&N);
    for(int i=0;i<N;++i)//读取原始序列
        scanf("%d",&initial[i]);
    for(int i=0;i<N;++i)//读取中间序列
        scanf("%d",&target[i]);
    memcpy(A,initial,sizeof(initial));//将原始序列拷贝给A数组
    bool f=false;
    for(int i=1;i<N;++i){//进行插入排序
        sort(A,A+i+1);//第一趟排序应该是排序前两个数，第i趟排序分别排序前i+1个数
        if(equal(A,A+N,target)){//equal是C++标准库中函数，如果两个序列对应位置上的元素都相等，则返回true
            f=true;
            printf("Insertion Sort\n");
            sort(A,A+i+2);//进行下一趟排序
            break;
        }
    }
    if(!f){//不是插入排序
        printf("Heap Sort\n");
        memcpy(A,initial,sizeof(initial));
        for(int i=N/2;i>=0;--i)//将前一半元素进行下滤
            down(i,N);
        for(int i=N-1;i>0;--i){//N-1趟排序，每次排序得到一个第N-i大的值放到相应位置
            swap(A[i],A[0]);
            down(0,i);
            if(equal(A,A+N,target)){
                swap(A[i-1],A[0]);//进行下一趟排序
                down(0,i-1);//进行下一趟排序
                break;
            }
        }
    }
    for(int i=0;i<N;++i)//输出下一趟排序结果
        printf("%s%d",i>0?" ":"",A[i]);
    return 0;
}
