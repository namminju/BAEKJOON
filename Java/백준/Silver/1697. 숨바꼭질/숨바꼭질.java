import java.io.*;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Deque;
import java.util.Scanner;

public class Main {
    public static final int MAX = 200000;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        Deque<int[]> queue = new ArrayDeque<>();
        boolean[] visited = new boolean[MAX];
        int[] input = Arrays.stream(br.readLine().split(" "))
                .mapToInt(Integer::parseInt)
                .toArray();
        queue.add(new int[]{input[0], 0});

        while(!queue.isEmpty()){
            int[] current = queue.poll();
            int[] next = new int[]{current[0]+1, current[0]-1, current[0]*2 };
            if(current[0]==input[1]){
                bw.write(current[1]+" ");
                break;
            }

            for(int n : next){
                if(
                        n >= 0
                                && n < MAX
                                &&  !visited[n]
                ){    
                    visited[n] = true;
                    queue.add(new int[]{n, current[1]+1});
                }
            }

        }

        bw.flush();
        bw.close();
    }
}
