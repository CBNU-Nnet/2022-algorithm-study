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
  int res = 0, sign = 1;
  cin >> input;
  for (int i = 0; i < input.length(); i++)
  {
    int tmp = 0;
    if (input[i] >= '0' && input[i] <= '9')
    {
      while (input[i] >= '0' && input[i] <= '9')
      {
        tmp *= 10;
        tmp += input[i] - '0';
        i++;
      }
    }
    res += tmp * sign;
    if (i < input.length() && input[i] == '-')
      sign = -1;
  }
  cout << res;
}