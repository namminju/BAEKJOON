import java.io.*;
import java.util.*;

public class Main {
    static class Edge {
        int from, to, weight;
        Edge(int from, int to, int weight) {
            this.from = from;
            this.to = to;
            this.weight = weight;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken()); // 정점 수
        int M = Integer.parseInt(st.nextToken()); // 간선 수

        List<Edge> edges = new ArrayList<>();
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());
            int weight = Integer.parseInt(st.nextToken());
            edges.add(new Edge(from, to, weight));
        }

        long[] dist = new long[N + 1];
        Arrays.fill(dist, Long.MAX_VALUE);
        dist[1] = 0;

        boolean hasNegativeCycle = false;
        for (int i = 1; i <= N; i++) {
            for (Edge e : edges) {
                if (dist[e.from] != Long.MAX_VALUE && dist[e.to] > dist[e.from] + e.weight) {
                    dist[e.to] = dist[e.from] + e.weight;
                    if (i == N) {
                        hasNegativeCycle = true;
                    }
                }
            }
        }

        if (hasNegativeCycle) {
            bw.write("-1\n");
        } else {
            for (int i = 2; i <= N; i++) {
                bw.write((dist[i] == Long.MAX_VALUE ? "-1" : dist[i]) + "\n");
            }
        }

        bw.flush();
        br.close();
        bw.close();
    }
}
