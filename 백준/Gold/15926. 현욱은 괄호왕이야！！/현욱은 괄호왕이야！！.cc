#include<stdio.h>
#include<vector>
#include<stack>
#include<math.h>

using namespace std;

int main() {
	int n;
	char s[200001];
	stack<int> c;
	scanf("%d", &n);
	scanf("%s", &s);
	c.push(s[0] == '(' ? -1 : 0);
	int maxSize = 0, size = 0;
	for (int i = 1; i < n; i++) {
		if (!c.empty() && c.top() > 0 && s[i] == ')') {
			size = c.top();
			c.pop();
		}
		else size = 0;
		if (!c.empty() && c.top() == -1 && s[i] == ')') {
			size += 2;
			c.pop();
			if (!c.empty() && c.top() > 0) {
				size += c.top();
				c.pop();
			}
			c.push(size);
			maxSize = max(maxSize, size);
			size = 0;
		}
		else {
			c.push(s[i] == '(' ? -1 : 0);
		}
	}
	maxSize = max(maxSize, size);
	printf("%d", maxSize);
}