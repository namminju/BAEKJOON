import java.util.*;
class Solution {
    int[] childNum;
    boolean[] visited;
    Map<Integer, List<Integer>> map = new HashMap<>();
    public int getChildNum(int n){
        int count = 1;
        visited[n]=true;
        for(int c: map.getOrDefault(n, new ArrayList<>())){
            if(!visited[c]){                
                count += getChildNum(c);
            }
        }
        childNum[n] = count;
        return count;
    }
    public int solution(int n, int[][] wires) {
        int answer = n;
        childNum = new int[n+1];
        visited = new boolean[n+1];
        for(int w[]: wires){
            List<Integer> list = map.getOrDefault(w[0], new ArrayList<>());
            list.add(w[1]);
            map.put(w[0], list);
            
            list = map.getOrDefault(w[1], new ArrayList<>());
            list.add(w[0]);
            map.put(w[1], list);
        }
        getChildNum(1);
   
        for(int i: childNum){
            int value = Math.abs((n-i) - i);
            answer = Math.min(answer, value);
        }
        return answer;
    }
}