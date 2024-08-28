import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;


public class Solution {
    static int N, M;
    static int[] parent;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();

        int T = Integer.parseInt(br.readLine());

        for(int t = 1; t <= T; t++){
            st = new StringTokenizer(br.readLine());

            N = Integer.parseInt(st.nextToken());
            M = Integer.parseInt(st.nextToken());

            parent = new int[N + 1];

            for(int i = 0; i <= N; i++){
                parent[i] = i;
            }

            int a, b, aParent, bParent, result = N;
            for(int m = 0; m < M; m++){
                st = new StringTokenizer(br.readLine());

                a = Integer.parseInt(st.nextToken());

                if(st.hasMoreTokens()) {
                    b = Integer.parseInt(st.nextToken());
                }

                else continue;
                aParent = GetParent(a);
                bParent = GetParent(b);

                if(aParent == bParent) continue;
                result--;
                parent[aParent] = b;
            }

            sb.append('#').append(t).append(' ').append(result).append('\n');
        }

        System.out.print(sb);
    }

    public static int GetParent(int n){
        if(parent[n] != n) parent[n] = GetParent(parent[n]);
        return parent[n];
    }
}