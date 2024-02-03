#include<iostream>
#include<string>
#include<vector>
#include<set>

using namespace std;

char foundWinner(set<char> RSP) {
	if (RSP.size() == 3) return 'T';
	if (RSP.find('R') != RSP.end() && RSP.find('S') != RSP.end()) return 'R';
	if (RSP.find('S') != RSP.end() && RSP.find('P') != RSP.end()) return 'S';
	if (RSP.find('P') != RSP.end() && RSP.find('R') != RSP.end()) return 'P';
	return 'T';
}

int main() {
	int testcase;
	vector<int> result;
	cin >> testcase;

	for (int i = 0; i < testcase; i++) {

		int robotCount = 0;
		vector<string> RSPs;
		set<int> survivors;
		set<char> RSP;

		cin >> robotCount;
		for (int j = 0; j < robotCount; j++) {
			string currentRSP;
			cin >> currentRSP;
			RSPs.push_back(currentRSP);
			survivors.insert(j);
		}

		for(int j = 0; j < RSPs[0].length(); j++){
			RSP.clear();
			if (survivors.size() == 1) break;

			for (auto survivor : survivors) {
				RSP.insert(RSPs[survivor][j]);
			}

			char winRSP = foundWinner(RSP);
			if (winRSP == 'T') continue;

			auto itr = survivors.begin();
			while(itr != survivors.end()) {
				if (RSPs[*itr][j] != winRSP) survivors.erase(itr++);
				else ++itr;
			}
		}

		if (survivors.size() > 1) result.push_back(0);
		else result.push_back(*survivors.begin() + 1);
	}

	for (int i = 0; i < testcase; i++) {
		cout << result[i] << endl;
	}
}