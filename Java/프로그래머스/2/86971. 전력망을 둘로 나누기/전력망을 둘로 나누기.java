import java.util.*;

class Solution {
    Map<Integer, List<Integer>> map = new HashMap<>();
    boolean[] visited = new boolean[101];
    int total = 0;
    int min = 100;
    public int getchild(int n){
        int count = 1;
        for(int c: map.getOrDefault(n, new ArrayList<>())){
            if(!visited[c]){
                visited[c]=true;
                count+=getchild(c);
            }
        }
        min = Math.min(min,Math.abs((total - count) -count));
        return count;
    }
    public int solution(int n, int[][] wires) {
        int answer = n;
    
        for(int[] wire: wires){
            map.computeIfAbsent(wire[0], k->new ArrayList<>()).add(wire[1]);
            map.computeIfAbsent(wire[1], k->new ArrayList<>()).add(wire[0]);
        }
        total = n;
                
        visited[1]=true;
        getchild(1);

        return min;
    }
}