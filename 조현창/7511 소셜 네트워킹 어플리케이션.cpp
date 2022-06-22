#include<iostream>
#include<vector>

using namespace std;

int Find(vector<int>& Union, int x)
{
	if (Union[x] == x) return x;
	return Union[x] = Find(Union, Union[x]);
}

void doUnion(vector<int>& Union, int x, int y)
{
	x = Find(Union, x);
	y = Find(Union, y);
	if (x != y)
	{
		if (x < y)
			Union[y] = x;
		else
			Union[x] = y;
	}
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  cout.tie(NULL);
  int t, n, k, m;
  cin >> t;
  for (int i = 1; i <= t; i++){
    cin >> n;
    vector<int> Union(n);
    for (int i = 0; i < n; i++)
      Union[i] = i;
    cin >> k;
    while(k--){
      int a, b;
      cin >> a >> b;
      doUnion(Union, a, b);
    }
    cin >> m;
    printf("Scenario %d:\n", i);
    while(m--){
      int a, b;
      cin >> a >> b;
      printf("%d\n", Find(Union, a) == Find(Union,b));
    }
    printf("\n");
  }
}