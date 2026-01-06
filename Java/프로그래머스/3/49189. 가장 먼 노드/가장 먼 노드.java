import java.util.*;

class Solution {
    Deque<int[]> dq = new ArrayDeque<>();
    Map<Integer, List<Integer>> map = new HashMap<>();
    public int solution(int n, int[][] edge) {
        int answer = 0;
        int max = 0;
        boolean[] visited = new boolean[n+1];
        
        for(int[] e: edge){
            map.computeIfAbsent(e[0], k-> new ArrayList<>()).add(e[1]);
            map.computeIfAbsent(e[1], k-> new ArrayList<>()).add(e[0]);
        }
        
        //시작점 추가
        visited[1] = true;
        dq.add(new int[]{1, 0});
        
        while(!dq.isEmpty()){
            int[] cur = dq.remove();
            if(cur[1]>max){
                max = cur[1];
                answer = 0;
            }
            if(cur[1] == max){
                answer++;
            }
            
            for(int next: map.getOrDefault(cur[0], new ArrayList<>())){
                if(visited[next]) continue;
                visited[next] = true;
                dq.add(new int[]{next, cur[1]+1});
            }
        }
        return answer;
    }
}