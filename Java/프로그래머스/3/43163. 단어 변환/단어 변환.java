import java.util.*;

class Solution {
    public class Word{
        public String word;
        public int deg;
        
        public Word(String word, int deg){
            this.word = word;
            this.deg = deg;
        }
    }
    public int diff(String word, String target){
        int count = 0;
        for(int i=0;i<word.length();i++){
            if(word.charAt(i)!=target.charAt(i)){
                count++;
            }
        }
        return count;
    }
    public int solution(String begin, String target, String[] words) {
        int answer = 0;
        
        Map<String, Boolean> map = new HashMap<>();
        Deque<Word> deque = new ArrayDeque<>();
        
        deque.add(new Word(begin, 0));
        map.put(begin, true);
        
        while(!deque.isEmpty()){
            Word cur = deque.removeFirst();
            
 
            if(cur.word.equals(target)){
                answer = cur.deg;
                break;
            }
            
            for(String word : words){
                if(!map.getOrDefault(word, false) && diff(cur.word, word) == 1){
                    deque.addLast(new Word(word, cur.deg+1));
                    map.put(word, true);
                }
            }
        }
        
        
        return answer;
    }
}