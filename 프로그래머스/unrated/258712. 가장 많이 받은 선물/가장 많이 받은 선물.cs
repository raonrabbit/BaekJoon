using System;
using System.Collections.Generic;

public class User{
    public Dictionary<string, int> _presentLog = new Dictionary<string, int>();
    int _PresentCount = 0;
    
    public User(string self, string[] friends){
        foreach(string friend in friends){
            if(friend == self) continue;
            _presentLog.Add(friend, 0);
        }
    }
    
    public int GetPresentIndex(){
       return _PresentCount;
    }
    
    public void GivePresent(string friendName){
        _PresentCount++;
        _presentLog[friendName]++;
    }
    
    public void ReceivePresent(string friendName){
        _PresentCount--;
        _presentLog[friendName]--;
    }
}

public class Solution {
    public int solution(string[] friends, string[] gifts) {
        int answer = 0;
        Dictionary<string, User> users = new Dictionary<string, User>();
        foreach(string self in friends){
            users.Add(self, new User(self, friends));
        }
        
        foreach(string gift in gifts){
            string[] split_data = gift.Split(' ');
            users[split_data[0]].GivePresent(split_data[1]);
            users[split_data[1]].ReceivePresent(split_data[0]);
        }
        
        int presentCount;
        foreach(KeyValuePair<string, User> user in users){
            presentCount = 0;
            foreach(KeyValuePair<string, int> present in user.Value._presentLog){
                if(present.Value > 0) presentCount++;
                else if(present.Value == 0){
                    if(user.Value.GetPresentIndex() > users[present.Key].GetPresentIndex()){
                        presentCount++;
                    }
                }
            }
            if(answer < presentCount) answer = presentCount;
        }
        return answer;
    }
}