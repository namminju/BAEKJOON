import java.util.*;

class Solution {
    public boolean solution(String[] phone_book) {
        boolean answer = true;
        
        Map<String, Boolean> map = new HashMap<>();
        for(String pb:phone_book){
           map.put(pb,true);
        }
        
        for(String pb:phone_book){
            for(int i=0;i<pb.length();i++){
                String str = pb.substring(0, i);
                if(map.getOrDefault(str, false)){
                    return false;
                }
            }
        }
        
        return answer;
    }
}