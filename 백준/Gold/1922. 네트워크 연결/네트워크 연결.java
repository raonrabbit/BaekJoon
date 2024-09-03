import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.io.BufferedReader;

public class Main {
    static int N, M;
    static int[][] map;
    static int[] parent;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        
        N = Integer.parseInt(br.readLine());
        M = Integer.parseInt(br.readLine());

        parent = new int[N + 1];
        map = new int[M][3];
        for(int i = 0; i <= N; i++){
            parent[i] = i;
        }

        for(int i = 0; i < M; i++){
            st = new StringTokenizer(br.readLine());
            map[i][0] = Integer.parseInt(st.nextToken());
            map[i][1] = Integer.parseInt(st.nextToken());
            map[i][2] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(map, (o1, o2) -> o1[2] - o2[2]);

        int a, b, result = 0;
        for(int[] node : map){
            if(GetParent(node[0]) != GetParent(node[1])){
                a = GetParent(node[0]);
                b = GetParent(node[1]);

                parent[a] = b;
                result += node[2];
            }
        }

        System.out.print(result);
    }

    public static int GetParent(int x) {
        if(parent[x] != x){
            parent[x] = GetParent(parent[x]);
        }
        return parent[x];
    }
}