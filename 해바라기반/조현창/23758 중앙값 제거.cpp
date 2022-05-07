#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int n, res = 0;
  cin >> n;
  priority_queue<int, vector<int>, greater<int>> nums;
  for (int i = 0; i < n; i++){
    int input;
    cin >> input;
    nums.push(input);
  }
  for (int i = 0; i < (n + 1) / 2; i++){
    int num = nums.top();
    while(num > 1){
      num >>= 1;
      res++;
    }
    nums.pop();
  }
  cout << res + 1;
}