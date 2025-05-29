import java.util.*;

class Solution {
    public int diffNum(String begin, String target){
        int count = 0;
        for(int i=0;i<begin.length();i++){
            if(begin.charAt(i)!=target.charAt(i)){
                count++;
            }
        }
        return count;
    }
    public class Node{
        public String word;
        public int depth;
        
        Node(String word, int depth){
            this.word = word;
            this.depth = depth;
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
            if(cur.word.equals(target)){
                answer = cur.depth;
            }
            for(String w: words){
                if(diffNum(cur.word, w)==1 && !visited.getOrDefault(w, false)){
                    deque.addLast(new Node(w, cur.depth+1));
                    visited.put(w, true);
                }
            }
        }
        
        return answer;
    }
}