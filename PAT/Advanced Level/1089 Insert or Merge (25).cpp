#include<bits/stdc++.h>
using namespace std;
int N,A[105],initial[105],target[105];
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
        printf("Merge Sort\n");
        memcpy(A,initial,sizeof(initial));
        for(int i=2;i<N;i*=2){//将每i个元素归并为一个非递减序列
            for(int j=0;j<N;j+=i)
                sort(A+j,j+i<N?A+j+i:A+N);
            if(equal(A,A+N,target)){
                for(int j=0;j<N;j+=i*2)//进行下一趟排序
                    sort(A+j,j+i*2<N?A+j+i*2:A+N);
                break;
            }
        }
    }
    for(int i=0;i<N;++i)//输出下一趟排序结果
        printf("%s%d",i>0?" ":"",A[i]);
    return 0;
}
