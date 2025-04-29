import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int N;
    static String[] names;

    public static class Node{
        public int count;
        public HashMap<Character, Node> child;

        public Node(){
            this.count = 0;
            child = new HashMap<>();
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();

        N = Integer.parseInt(st.nextToken());
        names = new String[N];

        for(int i = 0; i < N; i++){
            names[i] = br.readLine();
        }

        Node head = new Node();
        for(String s : names){
            Node cur = head;
            boolean nameGood = false;
            for(char c : s.toCharArray()){
                if(!cur.child.containsKey(c)){
                    if(!nameGood) {
                        sb.append(c).append('\n');
                        nameGood = true;
                    }
                    Node child = new Node();
                    cur.child.put(c, child);
                    cur = child;
                } else {
                    if (!nameGood) sb.append(c);
                    cur = cur.child.get(c);
                }
            }
            cur.count++;
            if (!nameGood) {
                if (cur.count >= 2) {
                    sb.append(cur.count);
                }
                sb.append('\n');
            }
        }

        System.out.print(sb);
    }
}
