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
		Y += cost[i] / 30 + 1; //통화와 동시에 1초 경과
		M += cost[i] / 60 + 1;
	}

	Y *= 10;
	M *= 15;

	if (Y == M) //요금이 같으면
		printf("Y M %d", Y);

	else if (Y > M) //M요금제가 쌀 때
		printf("M %d", M);

	else //Y요금제가 쌀 때
		printf("Y %d", Y);
}