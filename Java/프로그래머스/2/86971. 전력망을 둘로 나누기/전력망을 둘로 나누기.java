import java.util.*;

class Solution {
    Map<Integer, List<Integer>> map = new HashMap<>();
    boolean[] visited;
    int[] num;
    public int getChild(int n){
        int count = 1;
        visited[n]=true;
        
        List<Integer> child = map.getOrDefault(n, new ArrayList<>());
        for(int c: child){
            if(!visited[c]){
                count+=getChild(c);
            }            
        }
        num[n] = count;
        return count;
    }
    public int solution(int n, int[][] wires) {
        int answer = n;
        num = new int[n+1];
        visited = new boolean[n+1];
        
        for(int[] wire : wires){
            List<Integer> list = map.getOrDefault(wire[0], new ArrayList<>());
            list.add(wire[1]);
            map.put(wire[0], list);
            
            list = map.getOrDefault(wire[1], new ArrayList<>());
            list.add(wire[0]);
            map.put(wire[1], list);
        }
        
        getChild(1);
        
        for(int i: num){
            answer = Math.min(answer, Math.abs(n-i*2));
        }
        return answer;
    }
}