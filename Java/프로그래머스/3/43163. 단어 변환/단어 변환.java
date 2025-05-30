import java.util.*;

class Solution {
   
    public int diffNum(String begin, String target){
        int count = 0;
        for(int i=0;i<begin.length(); i++){
            if(begin.charAt(i)!=target.charAt(i)){
                count++;
            }
        }
        return count;
    }
    public class Node{
        String str;
        int cnt;
        
        Node(String str, int cnt){
            this.str = str;
            this.cnt = cnt;
        }
    }
    public int solution(String begin, String target, String[] words) {
        int answer = 0;
        
        Deque<Node> deque = new ArrayDeque<>();
        Map<String, Boolean> visited = new HashMap<>();
        
        deque.addLast(new Node(begin, 0));
        visited.put(begin, true);
        
        while(!deque.isEmpty()){
            Node cur = deque.removeFirst();
            
            if(cur.str.equals(target)){
                answer = cur.cnt;
                break;
            }
            
            for(String word: words){
                if(!visited.getOrDefault(word, false)
                    && diffNum(cur.str, word)==1){
                    deque.addLast(new Node(word, cur.cnt + 1));
                    visited.put(word, true);
                }
            }
        }
        
        return answer;
    }
}