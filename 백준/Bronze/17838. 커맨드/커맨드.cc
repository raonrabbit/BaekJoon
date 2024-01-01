#include<stdio.h>
#include<string.h>
#include<vector>

using namespace std;

bool isRightCommand(char* command, char* favoriteCommand);

int main() {
	int testcaseCount;
	char command[10001];
	char favoriteCommand[] = "AABBABB";
	vector<int> results;

	scanf("%d", &testcaseCount);

	for (int i = 0; i < testcaseCount; i++) {
		scanf("%s", command);

		if (strlen(command) != strlen(favoriteCommand)) {
			results.push_back(0);
			continue;
		}

		if (isRightCommand(command, favoriteCommand)) results.push_back(1);
		else results.push_back(0);
	}

	for (int result : results)
		printf("%d\n", result);
}

bool isRightCommand(char* command, char* favoriteCommand) {
	char commandA = '\0';
	char commandB = '\0';

	commandA = command[0];

	for (int i = 1; i < strlen(favoriteCommand); i++) {
		if (command[i] == commandA) {
			if(favoriteCommand[i] == 'A') continue;
			return false;
		}

		if (command[i] == commandB) {
			if (favoriteCommand[i] == 'B') continue;
			return false;
		}

		if (commandB == '\0') {
			commandB = command[i];
			if (favoriteCommand[i] == 'B') {
				continue;
			}
			return false;
		}

		return false;
	}

	return true;
}