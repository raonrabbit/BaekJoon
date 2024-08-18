import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static int[][] map;
    public static int white;
    public static int blue;
    public static void DFS(int startX, int startY, int endX, int endY){
        int n = map[startY][startX];
        if(endX - startX <= 1){
            if(n == 1) blue++;
            else white++;
            return;
        }
        boolean isAllSame = true;
        for(int y = startY; y < endY; y++){
            for(int x = startX; x < endX; x++){
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

        int ny = startY + (endY - startY) / 2;
        int nx = startX + (endX - startX) / 2;

        DFS(startX, startY, nx, ny);
        DFS(nx, startY, endX, ny);
        DFS(startX, ny, nx, endY);
        DFS(nx, ny, endX, endY);
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

        DFS(0, 0, N, N);
        System.out.println(white);
        System.out.println(blue);
    }
}
