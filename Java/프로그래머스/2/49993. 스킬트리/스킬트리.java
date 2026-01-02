import java.util.*;

class Solution {
    public boolean isPossible(String skill_tree, Map<Character, Character> pre, Map<Character, Integer> deg){
        for(int i=0;i<skill_tree.length();i++){
            char cur = skill_tree.charAt(i);
            if(deg.getOrDefault(cur, 0)==0){
                if(pre.getOrDefault(cur, null) != null){  
                    deg.put(pre.get(cur), 0);
                }
            }else{
                return false;
            }
        }
        
        return true;
    }
    
    public int solution(String skill, String[] skill_trees) {
        Map<Character, Character> pre= new HashMap<>();
        Map<Character, Integer> deg = new HashMap<>();
        
        int answer = 0;
        for(int i=1;i<skill.length();i++){
            Character cur = skill.charAt(i);
            deg.put(cur, 1);
            pre.put(skill.charAt(i-1), cur);
        }
        
        for(String skill_tree: skill_trees){
            if(isPossible(skill_tree, new HashMap<>(pre), new HashMap<>(deg))){
                answer++;
            }    
        }
        
        return answer;
    }
}