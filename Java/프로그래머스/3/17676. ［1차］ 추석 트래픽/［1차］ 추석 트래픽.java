import java.util.*;

class Solution {
    PriorityQueue<Long> start = new  PriorityQueue<>();
    PriorityQueue<Long> end = new  PriorityQueue<>();
    
    public Long S2D(String time){
        String[] t = time.split(":");
        Double hour = Double.parseDouble(t[0]) * 60 * 60;
        Double minute = Double.parseDouble(t[1]) * 60;
        Double second = Double.parseDouble(t[2]);
        
        return (long)((hour + minute + second) * 1000);

    }
    public int solution(String[] lines) {
        int answer = 0;
        
        int now = 0;
        
        for(String l:lines){
            // 날짜 시간 소요시간 분리
            String[] str = l.split(" "); 
            Long time = S2D(str[1]);
            Long e = time;
            Long s = time -
                (long)(Double.parseDouble(str[2].substring(0, str[2].length()-1))*1000);
            
            end.add(e);
            start.add(s + 1);
        }
        
        // 현재 보는 시간
        Long sl = start.peek();
        Long el = sl + +999;
        
        //초기 1초 요청 전부 추가
         while(!start.isEmpty() && start.peek()<=el){
            now++;
            answer++; 
            start.remove();
        }
        System.out.println(sl+"~"+el+": "+now);
        
         while(!start.isEmpty()){
            Long st = start.peek();
            Long et = end.peek();     
             
            if(et<st){
                sl = et;
                el = sl + +999; 
            }else{
                sl = st;
                el = sl + +999; 
            }
             
            // 현재 기간 내 시작 시간 전부 더하기
            while(!start.isEmpty() && start.peek()<=el){
                now++; 
                start.remove();
            }
 
            // 지나간 요청 제거 
            while(!end.isEmpty() && end.peek()<sl){
                now--; 
                end.remove();
            }          
            System.out.println(sl+"~"+el+": "+now);
            answer = Math.max(answer, now);
            while(!end.isEmpty() && end.peek()<=sl){
                now--; 
                end.remove();
            }   
        }
        
        return answer;
    }
} 