#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include <climits>
using namespace std;

int main(){
    int n,temp;
    cin>>n;
    vector<int> arr;
    arr.resize(n);
    
    for(int i=0;i<n;i++){
        cin>>temp;
        arr[i]=temp;
    }
    
    int K,D;
    cin>>K>>D;
    
    long long int res=LLONG_MIN;
    long long int fm[10][50]={0},fn[10][50]={0};
    
    for (int i=0;i<n;i++){
        fm[0][i]=arr[i];
        fn[0][i]=arr[i];
    }
    
    
    for (int i=0;i<n;i++){
        for(int k=1;k<K;k++){
            for(int j=i-1;j>=0 && i-j<=D;--j){
                fm[k][i]=max(fm[k][i],max(fm[k-1][j]*arr[i],fn[k-1][j]*arr[i]));
                fn[k][i]=min(fn[k][i],min(fm[k-1][j]*arr[i],fn[k-1][j]*arr[i]));
            }
        }
        res=max(res,fm[K-1][i]);
    }
    cout<<res;
    return 0;
}