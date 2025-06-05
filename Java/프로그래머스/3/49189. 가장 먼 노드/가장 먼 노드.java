import java.util.*;

class Solution {
    public int solution(int n, int[][] edge) {
        int answer = 0;
        
        Map<Integer, List<Integer>> map = new HashMap<>();
        boolean[] visited = new boolean[n+1];
        
        for(int[] e:edge){
            List<Integer> list = map.getOrDefault(e[0], new ArrayList<>());
            list.add(e[1]);
            map.put(e[0], list);
            
            list = map.getOrDefault(e[1], new ArrayList<>());
            list.add(e[0]);
            map.put(e[1], list);
        }
        
        Deque<int[]> deque = new ArrayDeque<>();
        deque.add(new int[]{1, 1});
        visited[1]=true;
        
        int max = 0;
        while(!deque.isEmpty()){
            int[] cur = deque.removeFirst();
            if(cur[1]>max){
                answer=0;
                max = cur[1];
            }
            if(cur[1]==max){
                answer++;
            }
            
            for(int i: map.getOrDefault(cur[0], new ArrayList<>())){
                if(!visited[i]){
                    deque.add(new int[]{i, cur[1]+1});
                    visited[i]=true;
                }
                
            }
        }
        return answer;
    }
}