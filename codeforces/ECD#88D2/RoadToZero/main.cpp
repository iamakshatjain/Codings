#include <bits/stdc++.h>
using namespace std;
int min(int a, int b){
	return a<b?a:b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
    	int x, y;
    	cin>>x>>y;
    	int a, b;
    	cin>>a>>b;
    	int m = min(x,y);
    	cout<<min((x+y)*a, (m*b) + ((x+y-(2*m))*a))<<endl;
    }
    return 0;
}