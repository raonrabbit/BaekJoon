import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
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

            map = new int[N][N];
            int totalHouses = 0;
            for(int y = 0; y < N; y++) {
                st = new StringTokenizer(br.readLine());
                for(int x = 0; x < N; x++) {
                    map[y][x] = Integer.parseInt(st.nextToken());
                    if(map[y][x] == 1) totalHouses++;
                }
            }

            max = 1;
            for(int k = 2; k <= N + 1; k++) {
                int operationCost = k * k + (k - 1) * (k - 1);

                for(int y = 0; y < N; y++) {
                    for(int x = 0; x < N; x++) {
                        int houseCount = 0;

                        for(int dy = -k + 1; dy < k; dy++) {
                            int dist = k - Math.abs(dy);
                            for(int dx = -dist + 1; dx < dist; dx++) {
                                int ny = y + dy;
                                int nx = x + dx;
                                if(ny >= 0 && ny < N && nx >= 0 && nx < N && map[ny][nx] == 1) {
                                    houseCount++;
                                }
                            }
                        }

                        if(M * houseCount - operationCost >= 0) {
                            max = Math.max(max, houseCount);
                        }
                    }
                }
            }

            sb.append('#').append(t).append(' ').append(max).append('\n');
        }
        System.out.println(sb);
    }
}
