import java.util.*;

class Solution {
    public int solution(int[] bandage, int health, int[][] attacks) {
        int answer = 0;

        int cur = health;
        int time = 0;
        int index = 0;
        int seq = 0;
        
        while(index<attacks.length){
            time++;
            if(time == attacks[index][0]){
                seq = 0;
                cur -= attacks[index][1];
                if(cur<=0){
                    return -1;
                }
                index++;
            }else{
                seq++;
                if(seq % bandage[0]==0){
                   cur += bandage[2];
                }
                cur += bandage[1];
                
                if(cur>health){
                    cur = health;
                }
            }
        }
        
        
        return cur;
    }
}