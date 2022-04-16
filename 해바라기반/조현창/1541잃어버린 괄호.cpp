#include <iostream>
#include <vector>
#include <deque>
#include <string>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  string input;
  int a, res = 0, tmp = 0, minus = 0, sum = 0, sub = 0;
  vector<int> A;
  vector<char> op;

  cin >> input;
  for (int i = 0; i < input.length(); i++)
  {
    if (input[i] >= '0' && input[i] <= '9')
    {
      while (input[i] >= '0' && input[i] <= '9')
      {
        tmp *= 10;
        tmp += input[i] - '0';
        i++;
      }
    }
    A.push_back(tmp);
    tmp = 0;
    if (i < input.length())
      op.push_back(input[i]);
  }
  for (int i = 0; i < A.size(); i++)
  {
    if (minus)
    {
      sub += A[i];
    }
    else
    {
      res += A[i];
    }
    if (i < op.size())
    {
      if (op[i] == '-')
      {
        minus = 1;
      }
    }
  }
  cout << res - sub;
}