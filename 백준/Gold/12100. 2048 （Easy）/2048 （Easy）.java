import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;
// BOJ12100
public class Main {
    static int N;
    static int[][] map;
    static int max;

    public static void push(int dir) {
        int count;
        boolean b = false;
        switch(dir) {
            case 0:
                for(int x = 0; x < N; x++) {
                    count = -1;
                    for(int y = 0; y < N; y++) {
                        if(map[y][x] == 0) continue;
                        if(count != -1 && !b && map[y][x] == map[count][x]) {
                            b = true;
                            map[count][x] *= 2;
                            map[y][x] = 0;
                            continue;
                        }
                        int n = map[y][x];
                        map[y][x] = 0;

                        map[++count][x] = n;
                        b = false;
                    }
                }
                break;

            case 1:
                for(int x = 0; x < N; x++) {
                    count = -1;
                    for(int y = N - 1; y >= 0; y--) {
                        if(map[y][x] == 0) continue;
                        if(count != -1 && !b && map[y][x] == map[N - 1 - count][x]) {
                            b = true;
                            map[N - 1 - count][x] *= 2;
                            map[y][x] = 0;
                            continue;
                        }
                        int n = map[y][x];
                        map[y][x] = 0;

                        map[N - 1 - ++count][x] = n;
                        b = false;
                    }
                }
                break;
            case 2:
                for(int y = 0; y < N; y++) {
                    count = -1;
                    for(int x = 0; x < N; x++) {
                        if(map[y][x] == 0) continue;
                        if(count != -1 && !b && map[y][x] == map[y][count]) {
                            b = true;
                            map[y][count] *= 2;
                            map[y][x] = 0;
                            continue;
                        }

                        int n = map[y][x];
                        map[y][x] = 0;

                        map[y][++count] = n;
                        b = false;
                    }
                }
                break;
            case 3:
                for(int y = 0; y < N; y++) {
                    count = -1;
                    for(int x = N - 1; x >= 0; x--) {
                        if(map[y][x] == 0) continue;
                        if(count != -1 && !b && map[y][x] == map[y][N - 1 - count]) {
                            b = true;
                            map[y][N - 1 - count] *= 2;
                            map[y][x] = 0;
                            continue;
                        }

                        int n = map[y][x];
                        map[y][x] = 0;
                        map[y][N - 1 - ++count] = n;
                        b = false;
                    }
                }
                break;
        }
    }

    public static void DFS(int depth) {
        if (depth == 5) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    max = Math.max(max, map[i][j]);
                }
            }
            return;
        }

        int[][] newArr = new int[N][N];
        for(int i = 0; i < N; i++){
            newArr[i] = map[i].clone();
        }

        for(int dir = 0; dir < 4; dir++){
            push(dir);
            DFS(depth + 1);
            for(int i = 0; i < N; i++){
                map[i] = newArr[i].clone();
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        N = Integer.parseInt(br.readLine());
        max = 0;
        map = new int[N][N];

        for(int y = 0; y < N; y++){
            st = new StringTokenizer(br.readLine());
            for(int x = 0; x < N; x++){
                map[y][x] = Integer.parseInt(st.nextToken());
            }
        }

        DFS(0);

        System.out.print(max);

    }
}
