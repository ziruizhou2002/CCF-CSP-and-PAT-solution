#include<bits/stdc++.h>
using namespace std;
struct Temp{
    int id,x,y;
    Temp(int iid,int xx,int yy):id(iid),x(xx),y(yy){}
    bool operator <(const Temp&t)const{//重载小于运算符
        return this->x*this->x+this->y*this->y<t.x*t.x+t.y*t.y;
    }
};
int main(){
    int N;
    scanf("%d",&N);
    Temp t(0,0,0),Max(0,0,0),Min(0,101,101);
    for(int i=0;i<N;++i){
        scanf("%d%d%d",&t.id,&t.x,&t.y);
        Min=min(Min,t);
        Max=max(Max,t);
    }
    printf("%04d %04d",Min.id,Max.id);
    return 0;
}
