#include <vector>
#include <iostream>
#include <string>

using namespace std;

inline bool isUpper(char c){
  return c >= 'A' && c <= 'Z';
}

inline bool isLower(char c){
  return c >= 'a' && c <= 'z';
}

inline int getAlpInd(char c){
  if(isUpper(c))
    return c - 'A';
  return c - 'a';
}

void print(string& input, vector<bool>& check, int index){
  for (int i = 0; i < input.length();i++){
    if(i == index)
      cout << '[' << input[i] << ']';
    else
      cout << input[i];
  }
  cout << '\n';
  check[getAlpInd(input[index])] = true;
}

int main(){
  int N;
  vector<bool> check(26, false);
  cin >> N;
  cin.get();
  while(N--)
  {
    string input;
    bool isStart = true;
    int startIndex = -1, midIndex = -1;
    getline(cin, input);
    for (int i = 0; i < input.length(); i ++){
      if(input[i] != ' ' && !check[getAlpInd(input[i])]){
        if(isStart && startIndex == -1){
          startIndex = i;
          break;
        }else if(!isStart && midIndex == -1){
          midIndex = i;
        }
      }
      if(input[i] == ' ')
        isStart = true;
      else
        isStart = false;
    }
    if(startIndex >= 0){
      print(input, check, startIndex);
    }else if(midIndex >= 0){
      print(input, check, midIndex);
    }else
      cout << input << '\n';
  }
}