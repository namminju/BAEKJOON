import java.util.*;

class Solution {
    PriorityQueue<Integer> a_pq = new PriorityQueue<>((a, b)->{return Integer.compare(b,a);});
    PriorityQueue<Integer> b_pq = new PriorityQueue<>((a, b)->{return Integer.compare(b,a);});
    public int solution(int[] A, int[] B) {
        int answer = 0;
        for(int i=0;i<A.length;i++){
            a_pq.add(A[i]);
            b_pq.add(B[i]);
        }
        
        while(!a_pq.isEmpty() && !b_pq.isEmpty()){
            int a = a_pq.poll();
            int b = b_pq.poll();
            
            if(b>a){ 
                answer++;  
            }
            else{
                while(!a_pq.isEmpty()){
                    a = a_pq.poll();
                    if(b>a){
                        answer++; 
                        break;
                    }
                }
            }
        }
        
        return answer;
    }
}