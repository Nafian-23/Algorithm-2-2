#include<iostream>
using namespace std;

int findcrossing(vector<int>&arr,int start,int mid,int end){
  int left_sum = INT_MIN;
  int sum = 0;
  for (int i = mid; i >= start; i--)
  {
    /* code */
    sum += arr[i];
    left_sum = max(left_sum,sum);
  }
  int right_sum = INT_MIN;
   sum = 0;
  for (int i = mid + 1; i <= end; i++)
  {
    /* code */
    sum += arr[i];
    right_sum = max(right_sum,sum);
  }
  return left_sum + right_sum;
}
int solve(vector<int>&arr,int start,int end){
  if(start == end){
    return arr[start];
  }
  int mid = (start + end)/2;
  int left_max = solve(arr,start,mid);
  int right_max = solve(arr,mid+1,end);
  int cross_max = findcrossing(arr,start,mid,end);
  return max(left_max,max(right_max,cross_max));
}
int main(){
  int n;
  cin >> n;
  vector<int>arr(n);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  cout << solve(arr,0,n-1) << endl;
}