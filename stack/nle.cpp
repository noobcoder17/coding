//Next larger element
#include <bits/stdc++.h>
using namespace std;

void nle(int nums[],int n){
    stack<pair<int,int>> stk;
    stk.push(make_pair(nums[0],0));
    int i;
    int *s = (int*)malloc(sizeof(int)*n);
    for(i=1;i<n;i++){
        if(stk.empty()){
            stk.push(make_pair(nums[i],i));
        }else {
            while(!stk.empty() && stk.top().first < nums[i]){
                s[stk.top().second] = nums[i];
                stk.pop();
            }
            stk.push(make_pair(nums[i],i));
        }
    }
    while(!stk.empty()){
        s[stk.top().second] = -1;
        stk.pop();
    }
    
    for(i=0;i<n;i++){
        cout << s[i] << " ";
    }
    cout << "\n";
}

int main() {
	int t,i,temp,n;
	cin >> t;
	while(t--){
	    cin >> n;
	    int *nums = (int*)malloc(sizeof(int)*n);
	    for(i=0;i<n;i++){
	        cin >> nums[i];
	    }
	    nle(nums,n);
	}
}