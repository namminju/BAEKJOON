import java.util.*;

class Solution {
    Deque<int[]> dq = new ArrayDeque<>();
    
    public int[] solution(int[] prices) {
        
        int n = prices.length;
        int[] answer = new int[n];
        
        for(int i=0;i<n;i++){
            if(dq.isEmpty() || dq.peek()[0] <= prices[i]){
                dq.addFirst(new int[]{prices[i], i});
            }else{ 
                while(!dq.isEmpty() && dq.peek()[0] > prices[i]){
                    int[] cur = dq.removeFirst(); 
                    answer[cur[1]] = i - cur[1];
                }
                dq.addFirst(new int[]{prices[i], i});
            }
        }
        
        while(!dq.isEmpty()){
            int[] cur = dq.removeFirst();
            
            answer[cur[1]] = n - cur[1] -1;
        }
        
        return answer;
    }
}