class Solution {
    public String solution(String new_id) {
        String answer = "";
        
        //1. 소문자 변환
        new_id = new_id.toLowerCase();
        
        //2. 가능한 문자만으로 변경
        for(int i=0;i<new_id.length();i++){
            char tmp = new_id.charAt(i);
            if(tmp >= 'a' && tmp <= 'z'){
                answer+=tmp;
            }
            if(tmp >= '0' && tmp <= '9'){
                answer+=tmp;
            }
            if(tmp == '-'||tmp=='_'||tmp=='.'){
                answer+=tmp;
            }
        }
        
        //3. 마침표 2번 이상인 부분 치환
        answer = answer.replaceAll("\\.+", ".");
        
        //4.
        answer = answer.replaceAll("^\\.+", ""); 
        answer = answer.replaceAll("\\.+$", "");  
        
        //5. 
        if(answer.length()<=0){
            answer = "a";
        }
        
        //6
        if(answer.length()>15){
            answer = answer.substring(0, 15);
            answer = answer.replaceAll("\\.+$", "");  
        }
        
        //7
        while(answer.length()<3){
            answer+=answer.charAt(answer.length()-1);
        }
        return answer;
    }
}