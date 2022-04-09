#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	char input[51];
	int totalSum = 0, plusSum = 0;
	int num = 0, tenth = 0;
	scanf("%s", input);

	for (int i = strlen(input) - 1; i >= 0; i--)
	{
		if ('0' <= input[i] && input[i] <= '9')
		{
			num += pow(10, tenth++) * (input[i] - '0');
			if (i == 0)
				totalSum += num + plusSum;
		}
		else
		{
			if (input[i] == '-')
			{
				totalSum -= (num + plusSum);
				plusSum = 0;
			}
			else if (input[i] == '+')
				plusSum += num;
			tenth = 0;
			num = 0;
		}
	}

	printf("%d\n", totalSum);
	return 0;
}