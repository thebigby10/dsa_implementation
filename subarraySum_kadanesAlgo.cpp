#include<bits/stdc++.h>
using namespace std;

int maxSubarraySum(int arr[], int n){
  int current_sum = 0, max_sum = 0;
  for(int i=0;i<n;i++){
    if(current_sum+arr[i]>=0) current_sum+=arr[i];
    else current_sum = 0;
    max_sum = max(current_sum, max_sum);
  }
  return max_sum;
}

int main(){
  int arr[] = {-2,3,4,-1,5,-12,6,1,3};
  int n = sizeof(arr)/sizeof(int);
  cout<<maxSubarraySum(arr,n);
  return 0;
}
