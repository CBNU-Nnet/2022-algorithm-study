#include <iostream> 
#include <algorithm> 

using namespace std; 

int main(void) { 
	ios_base::sync_with_stdio(0);
	
	cin.tie(0); 
	
	int n, m;

	cin >> n >> m; //n�� m �Է�

	int result = m; 
	int sum = m; 
	
	for (int i = 0; i < n; i++) { 
		int incar, outcar; //�� ������ ��, ���� ������ ��
		
		cin >> incar >> outcar; 

		sum += (incar - outcar); //���� �� �ͳ� �� ������ ��

		if (sum < 0) { //, �ͳ� �ȿ� �ִ� ������ ���� 0���� ���� ��� 0�� ����Ѵ�.
			cout << 0 << "\n"; 

			return 0;
		}
		result = max(result, sum); //incar-outcar�� ���� �ͳ� �� ������ �� ���ϱ�
	}
	cout << result << "\n";//���

	return 0; 
}

