import java.io.*;
import java.util.Arrays;

public class Main {
    public static int[] nums;
    public static void union(int a, int b) {
        int rootA = findRoot(a);
        int rootB = findRoot(b);
        if (rootA != rootB) {
            nums[rootB] = rootA; // 혹은 rootA = rootB
        }
    }
    public static int findRoot(int a) {
        if (nums[a] != a) {
            nums[a] = findRoot(nums[a]); // 경로 압축
        }
        return nums[a];
    }

    public static boolean isSameSet(int a, int b) {
        return findRoot(a) == findRoot(b);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int[] input = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();

        nums = new int[input[0]+1];

        for(int i = 0; i <= input[0]; i++) {
            nums[i] =i;
        }

        for(int i = 0; i < input[1]; i++) {
            int[] tmp = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
            if(tmp[0]==0){
                   union(tmp[1], tmp[2]);
            } else if(tmp[0]==1){
                if(isSameSet(tmp[1], tmp[2])){
                    bw.write("YES\n");
                }else{
                    bw.write("NO\n");
                }
            }
        }
        bw.flush();
        bw.close();

    }
}