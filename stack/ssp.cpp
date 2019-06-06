//Stock span problem
#include <bits/stdc++.h>
using namespace std;

void ssp(vector<int> v,int n){
    stack<int> stk;
    int *s = (int*)malloc(sizeof(int)*n);
    s[0] = 1;
    stk.push(0);
    for(int i=1;i<n;i++){
        while(!stk.empty() && v[stk.top()] <= v[i]){
            stk.pop();
        }
        s[i] = (stk.empty()) ? i+1 : i - stk.top();
        stk.push(i);
    }
    for(int i=0;i<n;i++){
        cout << s[i] << " ";
    }
    cout << "\n";
}

int main() {
	int t,n,temp;
	cin >> t;
	while(t--){
	    cin >> n;
	    vector<int> v;
	    for(int i=0;i<n;i++){
	        cin >> temp;
	        v.push_back(temp);
	    }
	    ssp(v,n);
	}
}