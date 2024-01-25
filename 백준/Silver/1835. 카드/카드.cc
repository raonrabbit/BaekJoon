#include<stdio.h>
#include<deque>

using namespace std;

int main() {
	int fuckingNumber;
	deque<int> fuckingResult;
	scanf("%d", &fuckingNumber);

	int count = 1;
	fuckingResult.push_front(fuckingNumber);
	while(count != fuckingNumber){
		fuckingResult.push_front(fuckingNumber - count);
		for (int i = fuckingNumber; i > count; i--) {
			fuckingResult.push_front(fuckingResult.back());
			fuckingResult.pop_back();
		}
		count++;
	}

	while (fuckingResult.size() != 0) {
		printf("%d ", fuckingResult.front());
		fuckingResult.pop_front();
	}
}