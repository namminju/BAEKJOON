import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        List<Integer> answer = new ArrayList<>();
        Map<Integer, List<Integer>> map = new HashMap<>();
        int[] num = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        int[] singers = new int[num[0] + 1];

        for (int i = 0; i < num[1]; i++) {

            int[] order = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
            for (int j = 2; j < order.length; j++) {
                singers[order[j]]++;
                List<Integer> list = map.getOrDefault(order[j-1], new ArrayList<>());
                list.add(order[j]);
                map.put(order[j-1], list);
            }
        }

        for(int i = 1; i <= singers.length; i++) {
            for(int j = 1; j < singers.length; j++) {
                if(singers[j] == 0){
                    answer.add(j);
                    singers[j]--;
                    for(int n : map.getOrDefault(j, new ArrayList<>())) {
                            singers[n]--;
                    }
                    break;
                }
            }
        }

        if(answer.size() < num[0]){
            bw.write("0");
        }
        else {
            for(int i = 0; i < answer.size(); i++) {
                bw.write(answer.get(i)+"\n");
            }
        }
        bw.flush();
        br.close();
        bw.close();
    }
}
