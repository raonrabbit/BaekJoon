import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static int[][] map;
    public static int white;
    public static int blue;
    public static void DFS(int startX, int startY, int length){
        int n = map[startY][startX];
        boolean isAllSame = true;
        for(int y = startY; y < startY + length; y++){
            for(int x = startX; x < startX + length; x++){
                if(map[y][x] != n){
                    isAllSame = false;
                    break;
                }
            }
        }

        if(isAllSame){
            if(n == 1) blue++;
            else white++;
            return;
        }

        length /= 2;
        int ny = startY + length;
        int nx = startX + length;

        DFS(startX, startY, length);
        DFS(nx, startY, length);
        DFS(startX, ny, length);
        DFS(nx, ny, length);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        white = 0;
        blue = 0;
        int N = Integer.parseInt(br.readLine());
        map = new int[N][N];

        for(int y = 0; y < N; y++){
            st = new StringTokenizer(br.readLine());
            for(int x = 0; x < N; x++){
                map[y][x] = Integer.parseInt(st.nextToken());
            }
        }

        DFS(0, 0, N);
        System.out.println(white);
        System.out.println(blue);
    }
}
