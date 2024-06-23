#include<bits/stdc++.h>
using namespace std;

int maxsubarraySum(int arr[],int n){
//calculate prefix sum O(n) 
  int prefixSum[n] = {arr[0]};
  for(int i=1;i<n;i++){
    prefixSum[i] = prefixSum[i-1]+arr[i];
  }
//calculate prefix sum
//determine the maximum subarray sum O(n^2)
  int maxSum = -1;
  for(int i=0;i<n;i++){
    for(int j=i;j<n;j++){
      int tempSum = i>0 ? prefixSum[j]-prefixSum[i-1] : prefixSum[j];
      maxSum = max(maxSum, tempSum);
    }
  }  
//determine the maximum subarray sum
  return maxSum;
  return 0;
}

int main(){
  int arr[] = {-2,3,4,-1,5,-12,6,1,3};
  int n = sizeof(arr)/ sizeof(int);
  cout<<maxsubarraySum(arr,n);
  return 0;
}
