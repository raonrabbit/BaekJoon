using System;

public class Solution {
    
    // 시작 위치 찾기
    public int[] FindStartPoint(string[] park){
        int[] startPoint = new int[2];
        
        for(int y = 0; y < park.Length; y++){
            for(int x = 0; x < park[0].Length; x++){
                if(park[y][x] == 'S'){
                    startPoint[1] = x;
                    startPoint[0] = y;
                    break;
                }
            }
        }
        return startPoint;
    }
    
    // 움직임 가능 판단
    public bool CanMove(string[] park, int[] currentPoint, int ymove, int xmove){
        int x = currentPoint[1];
        int y = currentPoint[0];
        int movedX = x + xmove;
        int movedY = y + ymove;
        
        // 경계를 넘은 경우
        if(movedX < 0 || movedY < 0) return false;
        if(park[0].Length <= movedX || park.Length <= movedY) return false;
        
        // 장애물에 막힌 경우
        if(ymove < 0){
            for(int i = y; i >= movedY; i--){
                if(park[i][x] == 'X') return false;
            }
        }
        else if(ymove > 0){
            for(int i = y; i <= movedY; i++){
                if(park[i][x] == 'X') return false;
            }
        }
        if(xmove < 0){
            for(int i = x; i >= movedX; i--){
                if(park[y][i] == 'X') return false;
            }
        }
        else if(xmove > 0){
            for(int i = x; i <= movedX; i++){
                if(park[y][i] == 'X') return false;
            }
        }
        
        return true;
    }
    
    // 로봇 강아지 AI 기능
    public int[] MoveRobotDog(int[] startPoint, string[] park, string[] routes){
        int[] currentPoint = startPoint;
        string[] moveInfo;
        string moveDirection;
        int moveAmount;
        
        // 경로 탐색 및 이동
        foreach(string route in routes){
            moveInfo = route.Split(' ');
            moveDirection = moveInfo[0];
            moveAmount = Int32.Parse(moveInfo[1]);
            
            switch(moveDirection){
                case "N":
                    if(CanMove(park, currentPoint, -moveAmount, 0))
                        currentPoint[0] -= moveAmount;
                    break;
                case "S":
                    if(CanMove(park, currentPoint, moveAmount, 0))
                        currentPoint[0] += moveAmount;
                    break;
                case "W":
                    if(CanMove(park, currentPoint, 0, -moveAmount))
                        currentPoint[1] -= moveAmount;
                    break;
                case "E":
                    if(CanMove(park, currentPoint, 0, moveAmount))
                        currentPoint[1] += moveAmount;
                    break;
            }
        }
        
        return currentPoint;
    }
    
    
    public int[] solution(string[] park, string[] routes) {
        int[] answer = new int[] {};
        int[] startPoint;
        startPoint = FindStartPoint(park);
        answer = MoveRobotDog(startPoint, park, routes);
        return answer;
    }
}