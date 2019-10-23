#include<bits/stdc++.h>
using namespace std;
struct Mooncake{
    double store,price,pricePerStore;
};
int main(){
    int N,D;
    scanf("%d%d",&N,&D);
    Mooncake mooncake[N];
    for(int i=0;i<N;++i)
        scanf("%lf",&mooncake[i].store);
    for(int i=0;i<N;++i)
        scanf("%lf",&mooncake[i].price);
    for(int i=0;i<N;++i)
        mooncake[i].pricePerStore=mooncake[i].price/mooncake[i].store;//计算单价
    sort(mooncake,mooncake+N,[](const Mooncake&m1,const Mooncake&m2){
        return m1.pricePerStore>m2.pricePerStore;
    });//按单价排序
    double sumPrice=0.0;//卖的最大收益
    for(int i=0;i<N;++i)
        if(D>mooncake[i].store){//D比当前的月饼的库存量大
            sumPrice+=mooncake[i].price;//将当前月饼都卖出去
            D-=mooncake[i].store;//更新D
        }else{//D比当前的月饼的库存量小
            sumPrice+=D*mooncake[i].pricePerStore;//卖出库存为D的当前月饼
            break;//跳出循环
        }
    printf("%.2f",sumPrice);
    return 0;
}
