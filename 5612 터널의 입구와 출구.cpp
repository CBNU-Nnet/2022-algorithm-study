#include <iostream> 
#include <algorithm> 

using namespace std; 

int main(void) { 
	ios_base::sync_with_stdio(0);
	
	cin.tie(0); 
	
	int n, m;

	cin >> n >> m; //n과 m 입력

	int result = m; 
	int sum = m; 
	
	for (int i = 0; i < n; i++) { 
		int incar, outcar; //들어간 차량의 수, 나온 차량의 수
		
		cin >> incar >> outcar; 

		sum += (incar - outcar); //다음 줄 터널 안 차량의 수

		if (sum < 0) { //, 터널 안에 있는 차량의 수가 0보다 작은 경우 0을 출력한다.
			cout << 0 << "\n"; 

			return 0;
		}
		result = max(result, sum); //incar-outcar에 현재 터널 안 차량의 수 더하기
	}
	cout << result << "\n";//출력

	return 0; 
}

