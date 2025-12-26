import java.util.*;

class Solution {
    public Map<String, Integer> income = new HashMap<>();
    public Map<String, String> ref = new HashMap<>();
    
    public void plus(String name, int amount){
        int mine = (int) Math.ceil(amount * 0.9);
        income.put(name, income.getOrDefault(name, 0) + mine);
        if(!ref.get(name).equals("-")){
            if((int)(amount * 0.1)==0) return;
            plus(ref.get(name), (int)(amount * 0.1));
        }
    }
    
    public int[] solution(String[] enroll, String[] referral, String[] seller, int[] amount) {
        int[] answer = new int[enroll.length];

        for(int i=0; i<enroll.length; i++){
            ref.put(enroll[i], referral[i]);
        }
        
        for(int i=0; i<seller.length; i++){
            plus(seller[i], amount[i] * 100);
        }
        
        for(int i=0; i<enroll.length; i++){
            answer[i] = income.getOrDefault(enroll[i], 0);
        }
        
        return answer;
    }
}