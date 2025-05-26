import java.util.*;
class Solution {
    public Map<Integer, List<Integer>> tree = new HashMap<>();
    int[] child;
    boolean[] visited;
    
    public int dfs(int n){
        int count = 1;
        visited[n]=true;
        
        for(int num : tree.get(n)){
            if(!visited[num]){
                count+=dfs(num);
            }
           
        }
        child[n] = count; 
        return count;
    }
    
    public int solution(int n, int[][] wires) {
        int answer = n;
        
        child = new int[n+1];
        visited = new boolean[n+1];
        
        for(int i=0;i<wires.length;i++){
            List<Integer> list = tree.getOrDefault(wires[i][0], new ArrayList<>());
            list.add(wires[i][1]);
            tree.put(wires[i][0], list);
            
            list = tree.getOrDefault(wires[i][1], new ArrayList<>());
            list.add(wires[i][0]);
            tree.put(wires[i][1], list);
        }
        
        dfs(1);
        
        
        for(int i=2;i<child.length;i++){
            int a = child[1]-child[i];
            int b = child[i];
            answer = Math.min(answer, Math.abs(a-b));
        }
        return answer;
    }
}