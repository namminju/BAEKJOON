import java.util.*;

class Solution {
    Map<Integer, List<Integer>> map = new HashMap<>();
    public int solution(int n, int[][] computers) {
        int answer = 0;
        boolean[] visited = new boolean[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){ 
                if(computers[i][j] == 1){ 
                    map.computeIfAbsent(j, k-> new ArrayList<>()).add(i);
                    map.computeIfAbsent(i, k-> new ArrayList<>()).add(j);
                }
            }
        }
        
        for(int i=0;i<n;i++){
            if(visited[i]) continue;
            answer++;
            
            Deque<Integer> dq = new ArrayDeque<>(); 
            dq.add(i);
            visited[i] = true;
             
            while(!dq.isEmpty()){
                int cur = dq.remove(); 
                for(int next: map.getOrDefault(cur, new ArrayList<>())){
                    if(!visited[next]){
                        dq.add(next);
                        visited[next] = true;
                        System.out.println(next);
                    }
                }
            }
        }
        
        return answer;
    }
}