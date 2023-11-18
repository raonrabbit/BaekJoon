#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    vector<string> babble_words = {"aya", "ye", "woo", "ma"};
    
    for(int i = 0; i < babbling.size(); i++){
        string s = babbling[i];
        
        for(int j = 0; j < babble_words.size(); j++)
        {
            int index = s.find(babble_words[j]);
            if(index == -1) continue;
            s.replace(s.find(babble_words[j]), babble_words[j].length(), "-");
        }
        
        bool isAnswer = true;
        for(int j = 0; j < s.size(); j++){
            if(s[j] != '-'){isAnswer = false; break;}
        }
        if(isAnswer) answer++;
    }
    return answer;
}