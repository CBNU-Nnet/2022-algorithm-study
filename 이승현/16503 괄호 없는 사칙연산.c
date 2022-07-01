#include <stdio.h>

int calculator(int a, int b, int op)
{
	int ans;
	switch (op)
	{
	case '+':
		ans = a + b;
		break;
	case '-':
		ans = a - b;
		break;
	case '*':
		ans = a * b;
		break;
	case '/':
		ans = a / b;
		break;
	}
	return ans;
}
int main()
{
	int k1, k2, k3;
	char o1, o2;
	int ans1 = 0, ans2 = 0;
	scanf("%d %c %d %c %d", &k1, &o1, &k2, &o2, &k3);
	ans1 = calculator(k1, k2, o1);
	ans1 = calculator(ans1, k3, o2);
	ans2 = calculator(k2, k3, o2);
	ans2 = calculator(k1, ans2, o1);
	if (ans1 < ans2)
		printf("%d\n%d", ans1, ans2);
	else
		printf("%d\n%d", ans2, ans1);
	return 0;
}