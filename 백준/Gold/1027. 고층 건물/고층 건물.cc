#include<stdio.h>
#include<vector>

using namespace std;
int main() {
	int buildingCount;
	scanf("%d", &buildingCount);
	vector<int> v;
	for (int i = 0; i < buildingCount; i++) {
		int b;
		scanf("%d", &b);
		v.push_back(b);
	}

	int r, l, count, max = 0;
	double a, b;
	for (int i = 0; i < buildingCount; i++) {
		r = i + 1, l = i - 1, count = 0;
		bool cansee;
		while (r < buildingCount) {
			cansee = true;
			a = (double)(v[i] - v[r]) / (double)(i - r);
			b = (double)v[i] - (a * i);
			for (int j = i + 1; j < r; j++) {
				if (a * j + b <= v[j]) cansee = false;
			}
			if (cansee) count++;
			r++;
		}

		while (0 <= l) {
			cansee = true;
			a = (double)(v[i] - v[l]) / (double)(i - l);
			b = (double)v[i] - (a * i);
			for (int j = l + 1; j < i; j++) {
				if (a * j + b <= v[j]) cansee = false;
			}
			if (cansee) count++;
			l--;
		}
		if (max < count) max = count;
	}
	printf("%d", max);
}