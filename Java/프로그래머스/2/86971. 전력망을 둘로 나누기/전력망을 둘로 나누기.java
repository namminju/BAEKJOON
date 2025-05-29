import java.util.*;

class Solution {

    public Map<Integer, List<Integer>> map = new HashMap<>();
    public boolean[] visited;
    public int[] child;
    
    public int childNum(int n){
        int count = 1; //본인
        visited[n] = true;
        for(int c: map.getOrDefault(n, new ArrayList<>())){//자식의 자식 개수 더하기
            if(!visited[c]){
                count += childNum(c);
            }
        }
        child[n] = count;
        return count;
    }
    public int solution(int n, int[][] wires) {
        int answer = n;
        visited = new boolean[n+1];
        child = new int[n+1];
        
        for(int[] wire: wires){
            List<Integer> list = map.getOrDefault(wire[0], new ArrayList<>());
            list.add(wire[1]);
            map.put(wire[0], list);
            
            list = map.getOrDefault(wire[1], new ArrayList<>());
            list.add(wire[0]);
            map.put(wire[1], list);
        }
        childNum(1);
        
        for(int c: child){
            answer = Math.min(answer, Math.abs((n-c)-c));
        }
        return answer;
    }
}