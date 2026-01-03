import java.util.*;

class Solution {
    public int[] solution(int[] progresses, int[] speeds) {
        
        int n =progresses.length;
        int[] day = new int[n];
        for(int i=0;i<n;i++){
            day[i] = ((100 - progresses[i]) + speeds[i] -1)/speeds[i];
        }
        
        List<Integer> list = new ArrayList<>();
        int bday = day[0];
        int num = 1;
        for(int i=1;i<n;i++){
            if(bday>=day[i]){
                num++;
            }else{
                list.add(num);
                bday = day[i]; 
                num = 1;
            }
        }
        list.add(num);
        
        int[] answer = new int[list.size()];
        int a =0;
        for(int l: list){
            answer[a] = l;
            a++;
        }
        
        return answer;
    }
}