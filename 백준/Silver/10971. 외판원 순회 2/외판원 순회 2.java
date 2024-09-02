import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int min;
    static int[][] map;
    static boolean[] visited;
    static int N, start;

    public static void DFS(int count, int from, int n){
        if(n >= min) return;
        if(count == N - 1){
            for(int i = 0; i < N; i++){
                if(!visited[i]) return;
            }
            if(map[from][start] == 0) return;
            n += map[from][start];
            min = Math.min(n, min);
            return;
        }

        for(int i = 0; i < N; i++){
            if(visited[i]) continue;
            if(map[from][i] == 0) continue;
            visited[i] = true;
            DFS(count + 1, i, n + map[from][i]);
            visited[i] = false;
        }
    } 

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        N = Integer.parseInt(br.readLine());
        map = new int[N][N];
        for(int i = 0; i < N; i++){
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < N; j++){
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        min = Integer.MAX_VALUE;
        for(int i = 0; i < N; i++){
            start = i;
            visited = new boolean[N];
            visited[i] = true;
            DFS(0, i, 0);
        }

        System.out.print(min);
    }
}