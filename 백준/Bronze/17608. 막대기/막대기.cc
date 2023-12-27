#include<iostream>
#include<stack>

using namespace std;

int main() {
	int stickNum;
	int currentStickHeight;
	stack<int> stickStack;
	int result = 0;

	scanf("%d", &stickNum);
	for (int i = 0; i < stickNum; i++) {
		scanf("%d", &currentStickHeight);
		while (stickStack.size() != 0 && stickStack.top() <= currentStickHeight) {
			stickStack.pop();
		}
		stickStack.push(currentStickHeight);
	}
	printf("%d", stickStack.size());
}