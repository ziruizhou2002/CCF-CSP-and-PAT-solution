#include<bits/stdc++.h>
using namespace std;
bool cmp(const string&s1,const string&s2) {//比较函数 
	return s1+s2<s2+s1;
}
int main() {
	int N;
	scanf("%d",&N);
	string str[N],s="";//定义字符串数组
	for(int i=0; i<N; ++i)
		cin>>str[i];
	sort(str,str+N,cmp);//排序
	for(int i=0; i<N; ++i)//将排序后的所有字符串合并成一个字符串 
		s+=str[i];
	int i=0;//不能输出前导0 
	while(i<s.size()&&s[i]=='0')
		++i;
	if(i==s.size())//如果字符串都是0，输出0 
		cout<<"0";
	else//否则输出剩余字符 
		while(i<s.size())
			cout<<s[i++];
	return 0;
}
