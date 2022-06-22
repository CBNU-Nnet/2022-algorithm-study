#include <iostream>
#include <stack>
#include<string>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  stack<char> cstack;
  int res = 0, sign = 1, sub = 0;
  char input;
  while((input = cin.get()) != '\n'){
    cstack.push(input);
  }
  while(cstack.size()){
    char top = cstack.top();
    if(cstack.top() == '-'){
      sub += res;
      res = 0;
      cstack.pop();
    }
    else if(cstack.top() >='0' && cstack.top() <= '9'){
      string tmp = "";
      while(cstack.size() && cstack.top() >='0' && cstack.top() <= '9'){
        tmp = string(1,cstack.top()) + tmp;
        cstack.pop();
      }
      res += stoi(tmp);
    }
    else cstack.pop();
  }
  cout << res-sub;
}