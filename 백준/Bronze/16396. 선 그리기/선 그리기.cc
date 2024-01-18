#include<stdio.h>
#include<map>

using namespace std;

int main() {
	int lineCount;
	map<int, int> projection;
	int start, end;
	int prevStart = -1, prevEnd;
	int length = 0;
	scanf("%d", &lineCount);

	for (int i = 0; i < lineCount; i++) {
		scanf("%d%d", &start, &end);
		projection.insert({ start, end });
	}

	prevStart = projection.begin()->first;
	prevEnd = projection.begin()->second;

	for (auto itr = projection.begin(); itr != projection.end(); itr++) {
		if (prevEnd < itr->first) {
			length += prevEnd - prevStart;
			prevStart = itr->first;
		}
		
		if(prevEnd < itr->second) {
			prevEnd = itr->second;
		}
	}
	length += prevEnd - prevStart;

	printf("%d", length);
}