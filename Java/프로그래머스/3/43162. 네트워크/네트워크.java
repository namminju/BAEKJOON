import java.util.*;

class Solution {
    public boolean[] visited = new boolean[201];
    public Map<Integer, List<Integer>> map = new HashMap<>();
    public int solution(int n, int[][] computers) {
        int answer = 0;
        for(int i=0; i<n;i++){
             for(int j=i; j<n;j++){
                 if(computers[i][j]==1){
                     map.computeIfAbsent(i, k->new ArrayList<>()).add(j);
                     map.computeIfAbsent(j, k->new ArrayList<>()).add(i);
                 }
             }
        }
        
        for(int i=0; i<n;i++){
            if(!visited[i]){
                 visited[i]=true;
                answer++;
                Deque<Integer> deque = new ArrayDeque<>();
                deque.add(i);
                
                while(!deque.isEmpty()){
                    int cur = deque.remove();
                 
                    for(int v: map.getOrDefault(cur, new ArrayList<>())){
                        if(visited[v]){
                            continue;
                        }
                        visited[v]=true;
                        deque.add(v);
                    }
                }
            }
        }
        return answer;
    }
}