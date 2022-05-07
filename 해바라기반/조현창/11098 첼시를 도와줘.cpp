#include<iostream>
#include<string>
using namespace std;

int main(){
  int n;
  cin >> n;
  while(n--){
    int p, max = 0;
    string answer;
    cin >> p;
    while(p--){
      int input;
      string name;
      cin >> input >> name;
      if(input > max){
        answer = name;
        max = input;
      }
        
    }
    cout << answer << '\n';
  }
}