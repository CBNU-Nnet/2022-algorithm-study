#include<stdio.h>

int main() {
	int N;
	int i;
	int cost[20];
	int Y = 0;
	int M = 0;

	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		scanf("%d", &cost[i]);
		Y += cost[i] / 30 + 1; //��ȭ�� ���ÿ� 1�� ���
		M += cost[i] / 60 + 1;
	}

	Y *= 10;
	M *= 15;

	if (Y == M) //����� ������
		printf("Y M %d", Y);

	else if (Y > M) //M������� �� ��
		printf("M %d", M);

	else //Y������� �� ��
		printf("Y %d", Y);
}