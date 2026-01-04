import java.util.*;

class Solution {
    class Word{
        String wrd;
        int cnt;
        
        Word(String wrd, int cnt){
            this.wrd = wrd;
            this.cnt = cnt;
        }
    }
    public boolean difOne(String origin, String dif){
        int cnt = 0;
        for(int i=0;i<origin.length();i++){
            if(cnt>1) return false;
            if(origin.charAt(i)!=dif.charAt(i)) cnt++;
        } 

        return cnt == 1;
    }
    
    Deque<Word> dq= new ArrayDeque<>();
    
    public int solution(String begin, String target, String[] words) {
        int answer = 0;
        boolean[] visited = new boolean[words.length];
        dq.add(new Word(begin, 0));
        
        while(!dq.isEmpty()){
            Word cur = dq.removeFirst();
            //System.out.println(cur.wrd+", "+cur.cnt);
            if(cur.wrd.equals(target)){
                answer = cur.cnt;
                break;
            }
            for(int i=0;i<words.length;i++){
                String word = words[i];
                if(!visited[i] && difOne(cur.wrd, word)){
                    visited[i] = true;
                    dq.addLast(new Word(word, cur.cnt+1));
                }
            } 
        }
        
        return answer;
    }
}