/*longest valid substring */
#include<bits/stdc++.h>
using namespace std;

int lvs(string str){
    int len = str.length();
    stack<int> s;
    s.push(-1);
    int result = 0;
    for(int i=0;i<len;i++){
        if(str[i] == '('){
            s.push(i);
        }else{
            if(!s.empty()){
                s.pop();
                result = max(result,i-s.top());
            }
            else {
                s.push(i);
            }
        }
    }
    return result;
}

int main() {
    string str = "()()";
    cout << lvs(str) << endl;
    return 0;
}