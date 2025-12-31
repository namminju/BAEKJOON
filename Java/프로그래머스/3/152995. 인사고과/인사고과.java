import java.util.*;
class Solution {
    public int solution(int[][] scores) { 
        int wonho = scores[0][0] + scores[0][1];
        
        Deque<int[]> compare = new ArrayDeque<>(); 
        
        for(int[] score: scores){
            compare.add(score);
        }
        
        int top = 1;

        for(int[] score: scores){
            Deque<int[]> tmp = new ArrayDeque<>(); 
            boolean contain = true;
            while(!compare.isEmpty()){
                int[] cur = compare.remove();
                if(score[0]<cur[0] && score[1]<cur[1]){
                    contain = false;
                }
                if(score[0]>=cur[0] && score[1]>=cur[1]){
                    
                }else{
                    tmp.add(cur);
                }
            }
            tmp.add(score);
            compare = tmp; 
            if(contain && score[0]+score[1] > wonho){ 
                top++;
            }
        }
        
        while(!compare.isEmpty()){
            int[] cur = compare.remove();
            if(scores[0][0]<cur[0] && scores[0][1]<cur[1]){
                return -1;
            } 
        } 
        
        return top;
    }
}