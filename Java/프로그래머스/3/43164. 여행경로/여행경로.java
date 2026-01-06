import java.util.*;

class Solution {
    boolean fin = false;
    Map<String, Integer> visited = new HashMap<>();
    Map<String, List<String>> map = new HashMap<>();
    List<String> result = new ArrayList<>();
    int n=0;
    void dfs(String st, int cnt, List<String> track){
        if(fin) return;
       
        if(cnt  == n){
            result = track;  
            fin = true;
        }
        for(String next: map.getOrDefault(st, new ArrayList<>())){
            if(visited.getOrDefault(st+"->"+next, 0) == 0) continue;
            String key = st + "->" + next;
            visited.put(key, visited.get(key) - 1); 
            track.add(next);
            dfs(next, cnt+1, track);
            if(fin) return;
            track.remove(track.size()-1);
            visited.put(key, visited.get(key)+1); 
        }
        
    }    
    public String[] solution(String[][] tickets) {
        n = tickets.length+1;
        String[] answer = new String[n];
        
        for(String[] t: tickets){
            map.computeIfAbsent(t[0], k-> new ArrayList<>()).add(t[1]);
            visited.put(t[0]+"->"+t[1], visited.getOrDefault(t[0]+"->"+t[1], 0)+1); 
        }
        for(String k: map.keySet()){
           Collections.sort(map.get(k));
        }
        
        List<String> init = new ArrayList<>();
        init.add("ICN");
            
        dfs("ICN", 1, init);
        
        int i=0;
        for(String t: result){
            answer[i] = t; i++; 
        }
        return answer;
    }
}