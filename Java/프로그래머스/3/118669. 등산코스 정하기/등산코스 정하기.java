import java.util.*;

class Solution {
    public int[] solution(int n, int[][] paths, int[] gates, int[] summits) {
        int[] answer = new int[]{10000001, 10000001};
        int[] values = new int[n+1];
        Arrays.fill(values, 10000001);
        boolean[] top = new boolean[n+1];
        Map<Integer, List<int[]>> map = new HashMap<>();
        PriorityQueue<int[]> pq = new PriorityQueue<>(
            (a,b)->{ 
                    return a[1]-b[1];}
           
        );
        // 도착점, 기중치 
        
        for(int[] path: paths){
            // 지점 검색 시 연결된 지점 & 가중치 반환할 수 있도록 
            map.computeIfAbsent(path[0], k -> new ArrayList<>()).add(new int[]{path[1], path[2]});
            map.computeIfAbsent(path[1], k -> new ArrayList<>()).add(new int[]{path[0], path[2]});
        }
        
        for(int gate: gates){
            // 출발점  추가
            pq.add(new int[]{gate, 0});
            values[gate] = 0;
            //마지막 값: 출발점 저장
        }
        
        for(int summit:summits){
            //도착지 확인을 위한 초기화 작업
            top[summit] = true;
        }
        
        while(!pq.isEmpty()){
            int[] cur = pq.remove(); 
            if (cur[1] > values[cur[0]]) continue;
            //도착점이면 
            if(top[cur[0]]){
                  if(values[cur[0]]<=answer[1]){
                    answer[0] = Math.min(answer[0], cur[0]);
                }
                 answer[1] = Math.min(answer[1], values[cur[0]]);
                //값 작은 걸로
                continue;
            }   
          
            //연결된 지점들에 대해서
            for(int[] next : map.getOrDefault(cur[0], new ArrayList<>())){
                // 다음 지점의 값보다 현재 가는 것이 작을 때
                if(values[next[0]] > Math.max(values[cur[0]], next[1])){
                    //현재 값으로 업데이트
                    values[next[0]]=Math.max(values[cur[0]], next[1]);
                    // 다음 지점, 가중치, 출발점
                    pq.add(new int[]{next[0], values[next[0]]});
                }
            }
            
        }

 
        return answer;
    }
}