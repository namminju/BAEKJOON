import java.io.*;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.StringTokenizer;

public class Main {
    static Map<Character, Node> left = new HashMap<>();
    static Map<Character, Node> right = new HashMap<>();

    public static class Node {
        char ch;
        Node left;
        Node right;

        public Node(char ch) {
            this.ch = ch;
        }
    }

    public static void makeTree(Node node) {
        if (left.containsKey(node.ch)) {
            node.left = left.get(node.ch);
            makeTree(node.left);
        }
        if (right.containsKey(node.ch)) {
            node.right = right.get(node.ch);
            makeTree(node.right);
        }
    }

    public static void PreOrder(Node root) {
        if (root == null) {
            return;
        }
        System.out.print(root.ch);
        PreOrder(root.left);
        PreOrder(root.right);
    }

    public static void Order(Node root) {
        if (root == null) {
            return;
        }

        Order(root.left);
        System.out.print(root.ch);
        Order(root.right);
    }

    public static void LastOrder(Node root) {
        if (root == null) {
            return;
        }

        LastOrder(root.left);
        LastOrder(root.right);
        System.out.print(root.ch);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        Node Root = new Node('A');

        int n = Integer.parseInt(br.readLine());
        for (int i = 0; i < n; i++) {
            String[] str = br.readLine().split(" ");
            if (!str[1].equals(".")) {
                left.put(str[0].charAt(0), new Node(str[1].charAt(0)));
            }
            if (!str[2].equals(".")) {
                right.put(str[0].charAt(0), new Node(str[2].charAt(0)));
            }
        }
        makeTree(Root);

        PreOrder(Root);     System.out.println();
        Order(Root);     System.out.println();
        LastOrder(Root);

        bw.flush();
        bw.close();
        br.close();
    }
}
