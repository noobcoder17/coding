#include<bits/stdc++.h>
using namespace std;

void printSet(int v[],int size){
    for(int i=0;i<size;i++){
        cout << v[i] << " ";
    }
    cout << "\n";
}

void subset(int set[],int v[],int size,int t_size,int sum,int nodes,int const target){
    if(sum == target){
        printSet(v,t_size);
        if(nodes + 1 < size && sum - v[nodes] + v[nodes+1] <= target){
            subset(set,v,size,t_size-1,sum-set[nodes],nodes+1,target);
        }
        return;
    }else{
        if(nodes < size && sum + set[nodes] <= target){
            for(int i=nodes;i<size;i++){
                v[t_size] = set[i];
                if(sum+set[i]<=target){
                    subset(set,v,size,t_size+1,sum+set[i],i+1,target);
                }
            }
        }
    }
}

void subSetSum(int set[],int size,int target){
    int t[8];
    sort(set,set+size);
    int total = 0;
    for(int i=0;i<size;i++){
        total += set[i];
    }
    if(set[0] <= target && target <= total){
        subset(set,t,size,0,0,0,target);
    }
}

int main() {
    int set[] = {15, 22, 14, 26, 32, 9, 16, 8};
    int size = sizeof(set)/sizeof(int);

    int target = 53;
    subSetSum(set,size,target);
    return 0;
}