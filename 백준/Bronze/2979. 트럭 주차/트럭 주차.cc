#include<iostream>
using namespace std;

int main()
{
	int oneCarCost, twoCarCost, threeCarCost;
	int parkingRecord[3][2];
	int firstCarExists, secondCarExists, thirdCarExists;
	int result = 0;

	scanf("%d %d %d", &oneCarCost, &twoCarCost, &threeCarCost);

	for (int i = 0; i < 3; i++)
	{
		scanf("%d %d", &parkingRecord[i][0], &parkingRecord[i][1]);
	}


	for (int i = 0; i < 100; i++)
	{
		if (i >= parkingRecord[0][0] && i < parkingRecord[0][1]) firstCarExists = 1;
		else firstCarExists = 0;

		if (i >= parkingRecord[1][0] && i < parkingRecord[1][1]) secondCarExists = 1;
		else secondCarExists = 0;

		if (i >= parkingRecord[2][0] && i < parkingRecord[2][1]) thirdCarExists = 1;
		else thirdCarExists = 0;

		int currentCarCount = firstCarExists + secondCarExists + thirdCarExists;

		if (currentCarCount == 1) result += oneCarCost;
		else if (currentCarCount == 2) result += twoCarCost * currentCarCount;
		else if (currentCarCount == 3) result += threeCarCost * currentCarCount;
	}

	printf("%d", result);
}