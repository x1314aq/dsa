//
// 1393 0和1相等串
//

#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;

const int Len=1000005;
int a[2000005];

int main() {
    string str;
    int ans = 0;
	ios::sync_with_stdio(false);
	cin >> str;
	for(int i=1,t=0;i<=str.size();++i)
	{
		t=(str[i-1]=='1')?t+1:t-1;
		if(!t)	ans=i;
		if(!a[t+Len])	a[t+Len]=i;
		else	ans=max(ans,i-a[t+Len]);
	}
	cout<<ans<<endl;
	return 0;
}
