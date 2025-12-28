import java.util.*;

class Solution {
    Map<Integer, List<Integer>> map = new HashMap<>();
    public int[] solution(int n, int[][] roads, int[] sources, int destination) {
        int[] answer = new int[sources.length]; 
        
        // 길 정보 저장
        for(int[] r:roads){
            map.computeIfAbsent(r[0], k->new ArrayList<>()).add(r[1]);
            map.computeIfAbsent(r[1], k->new ArrayList<>()).add(r[0]);
        }
        
        //이동 횟수
        int[] move = new int[n+1];

        //방문 여부
        boolean[] visited = new boolean[n+1];

        // 위치, 이동 거리
        Deque<int[]> dp = new ArrayDeque<>();

        //시작점 넣기
        visited[destination] = true;
        dp.addLast(new int[]{destination, 0});

        for(int i=0;i<=n;i++){
            move[i] = -1;
        }
        
        while(!dp.isEmpty()){
            int[] cur = dp.removeFirst();

            if(move[cur[0]] == -1 ) move[cur[0]] = cur[1];
            move[cur[0]] = Math.min(move[cur[0]], cur[1]);
            
            for(int next: map.getOrDefault(cur[0], new ArrayList<>())){
                if(visited[next]) continue;
                visited[next] = true;
                dp.addLast(new int[]{next, cur[1]+1});
            }
        }  
        
        for(int s = 0;s<sources.length;s++){
            answer[s] = move[sources[s]];
        }
        
        return answer;
    }
}