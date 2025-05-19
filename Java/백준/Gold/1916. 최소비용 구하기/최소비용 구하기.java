import java.io.*;
import java.util.*;
 
public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        Map<Integer, List<int[]>> map = new HashMap<>();

        int N = Integer.parseInt(br.readLine());
        int M = Integer.parseInt(br.readLine());

        int[] min = new int[N + 1];
        for(int i = 1; i <= N; i++) {
            min[i] = Integer.MAX_VALUE;
        }
        for (int i = 0; i < M; i++) {
            int[] arr = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
            List<int[]> tmp = map.getOrDefault(arr[0], new ArrayList<>());
            tmp.add(new int[]{arr[1], arr[2]});
            map.put(arr[0],  tmp);
        }
        int[] startEnd = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();

        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparing(a -> a[1]));
        pq.add(new int[]{startEnd[0], 0});
        min[startEnd[0]]=0;
        while (!pq.isEmpty()) {
            int[] cur = pq.remove();            
            if (min[cur[0]] < cur[1]) continue;
            List<int[]> tmp =map.getOrDefault(cur[0], new ArrayList<>());
            for (int[] arr : tmp) {
                if (arr[1]+min[cur[0]] < min[arr[0]]) {
                    min[arr[0]]=arr[1]+min[cur[0]] ;
                    pq.add(new int[]{arr[0], min[arr[0]]});
                }
            }
        }

        bw.write(String.valueOf(min[startEnd[1]]));
        br.close();
        bw.flush();
        bw.close();
    }
}
