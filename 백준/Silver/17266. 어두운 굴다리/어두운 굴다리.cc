#include<stdio.h>

int main() {
	int underpassLength, lightCount, lightPosition;
	int lightHeight = 1;
	int right = 0, left;

	scanf("%d", &underpassLength);
	scanf("%d", &lightCount);

	for (int i = 0; i < lightCount; i++) {
		scanf("%d", &lightPosition);
		left = lightPosition - lightHeight;
		if (i == 0)
		{
			lightHeight = lightPosition;
			right = lightPosition + lightHeight;
		}
		else if (right < left)
		{
			lightHeight += (left - right) / 2 + (left - right) % 2;
		}

		if (i == lightCount - 1 && lightPosition + lightHeight < underpassLength)
		{
			lightHeight += underpassLength - (lightPosition + lightHeight);
		}

		right = lightPosition + lightHeight;
	}

	printf("%d", lightHeight);
}