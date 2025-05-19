import java.io.*;
import java.util.*;

//https://www.acmicpc.net/problem/2529
public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int num =Integer.parseInt(br.readLine());
        String[] array = br.readLine().split(" ");
        int[] indegree = new int[num+1];
        int[] indegree2 = new int[num+1];

        int[] min = new int[num+1];
        int[] max = new int[num+1];

        for(int i=0; i<array.length; i++){
            if(array[i].equals("<")){
                indegree[i+1]++;
                indegree2[i]++;
            }else if(array[i].equals(">")){
                indegree[i]++;
                indegree2[i+1]++;
            }
        }

        for(int i=9; i>=9-num; i--){
            for(int j=0; j<=num; j++){
               if( indegree2[j]==0){
                   max[j] = i;
                   if(j>0 && indegree2[j-1]>0){
                       indegree2[j-1]--;
                   }
                   indegree2[j]--;
                   if(j<num&&indegree2[j+1]>0) {
                       indegree2[j + 1]--;
                   }
                   break;
               }
            }
        }

        for(int i=0; i<=num; i++){
            for(int j=0; j<=num; j++){
                if( indegree[j]==0){
                    min[j] = i;
                    if(j>0 && indegree[j-1]>0){
                        indegree[j-1]--;
                    }
                    indegree[j]--;
                    if(j<num&&indegree[j+1]>0) {
                        indegree[j + 1]--;
                    }
                    break;
                }
            }
        }

        for(int i=0;i<=num;i++){
            System.out.print(max[i]);
        }System.out.println();
        for(int i=0;i<=num;i++){
            System.out.print(min[i]);
        }

    }
}
