import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Solution {
    static int N, M;
    static int[][] map;
    static int max;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();

        int T = Integer.parseInt(br.readLine());

        for(int t = 1; t <= T; t++) {
            st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            M = Integer.parseInt(st.nextToken());

            int count = 0;
            map = new int[N][N];
            for(int y = 0; y < N; y++) {
                st = new StringTokenizer(br.readLine());
                for(int x = 0; x < N; x++) {
                    map[y][x] = Integer.parseInt(st.nextToken());
                    if(map[y][x] == 1) count++;
                }
            }
            if(count == N * N){
                sb.append('#').append(t).append(' ').append(count).append('\n');
                continue;
            }
            max = 1;

            for(int k = 2; k <= N; k++) {
                for(int y = 0; y < N; y++) {
                    for(int x = 0; x < N; x++) {
                        int ny, nx;
                        int houseCount = 0;
                        for(ny = k - 1, nx = 0; ny > 0; ny--, nx++) {
                            for(int nnx = x - nx; nnx <= x + nx; nnx++) {
                                if(IsOutOfMap(y - ny, nnx)) continue;
                                if(map[y - ny][nnx] == 1) houseCount++;
                            }
                            for(int nnx = x - nx; nnx <= x + nx; nnx++) {
                                if(IsOutOfMap(y + ny, nnx)) continue;
                                if(map[y + ny][nnx] == 1) houseCount++;
                            }
                        }

                        for(int nnx = x - (k - 1); nnx <= x + (k - 1); nnx++) {
                            if(IsOutOfMap(y, nnx)) continue;
                            if(map[y][nnx] == 1) houseCount++;
                        }

                        if(M * houseCount - (k * k + (k - 1) * (k - 1)) >= 0) {
                            max = Math.max(max, houseCount);
                        }
                    }
                }
            }

            sb.append('#').append(t).append(' ').append(max).append('\n');
        }
        System.out.println(sb);
    }

    public static boolean IsOutOfMap(int y, int x) {
        return y < 0 || y >= N || x < 0 || x >= N;
    }

}
