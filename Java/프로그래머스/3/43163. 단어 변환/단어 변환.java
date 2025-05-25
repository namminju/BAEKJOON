import java.util.*;

class Solution {
    public int diffNum(String begin, String target){
        int num = 0;
 
        for(int i=0;i<begin.length();i++){
            
            if(begin.charAt(i)!=target.charAt(i)){
                num++;
            } 
        }
        return num;
    }
    public class Node{
        String word;
        int num;
        
        Node(String word, int num){
            this.word = word;
            this.num = num;
        }
    }
    public int solution(String begin, String target, String[] words) {
        int answer = 0;
        
        Map<String, Boolean> visited = new HashMap<>();
        Deque<Node> deque = new ArrayDeque<>();
        
        deque.addLast(new Node(begin, 0));
        visited.put(begin, true);
        
        while(!deque.isEmpty()){
            Node cur = deque.removeFirst();
            
            
            if(target.equals(cur.word)){
                answer = cur.num;
                break;
            }
            for(String word :words){
                if(diffNum(cur.word, word) == 1 && !visited.getOrDefault(word, false)){
    
                    deque.addLast(new Node(word, cur.num + 1));
                    visited.put(word, true);
                }
            }
        }
        
        return answer;
    }
}