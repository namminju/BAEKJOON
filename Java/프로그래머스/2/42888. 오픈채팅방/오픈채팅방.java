import java.util.*;

class Solution {
    Map<String, String> map = new HashMap<>();
    List<String> last = new ArrayList<>();
    List<String> uuid = new ArrayList<>();
    public String[] solution(String[] record) {
     
        
        for(String r: record){
            String[] str = r.split(" ");
            
            if(str[0].equals("Enter")){
                uuid.add(str[1]);
                map.put(str[1], str[2]);
                last.add("님이 들어왔습니다.");
            }else if(str[0].equals("Leave")){
                uuid.add(str[1]);
                last.add("님이 나갔습니다.");
            }else if(str[0].equals("Change")){ 
                map.put(str[1], str[2]);
            }
        }
        String[] answer = new String[last.size()];
        
        for(int i=0;i<last.size();i++){
            answer[i] = map.get(uuid.get(i))+last.get(i);
            //System.out.println(answer[i]);
        }
        
        return answer;
    }
}