import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int M;
    static int N;

    public static boolean IsOutOfChest(int x, int y){
        return x < 0 || x > M - 1 || y < 0 || y > N - 1;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        Queue<Integer> q = new LinkedList<>();
        Set<Integer> set = new HashSet<>();
        StringTokenizer st = new StringTokenizer(bf.readLine());
        M = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());
        int[][] chest = new int[N][M];
        int tomatoCount = 0;
        int goodTomatoCount = 0;
        int date = 0;

        for(int y = 0; y < N; y++){
            String s = bf.readLine();
            st = new StringTokenizer(s);

            for(int x = 0; x < M; x++){
                int a = Integer.parseInt(st.nextToken());
                chest[y][x] = a;
                if(a == 1) {
                    q.add(y * M + x);
                    set.add(y * M + x);
                }
                if(a != -1) tomatoCount++;
            }
        }

        while(!q.isEmpty()){
            if(goodTomatoCount == tomatoCount) break;
            int qSize = q.size();
            date++;
            for(int i = 0; i < qSize; i++){
                int t = q.remove();
                int x = t % M;
                int y = t / M;

                chest[y][x] = 1;
                goodTomatoCount++;

                if(!IsOutOfChest(x + 1, y) && !set.contains(y * M + (x + 1)) && chest[y][x + 1] == 0) {
                    q.add(y * M + (x + 1));
                    set.add(y * M + (x + 1));
                }
                if(!IsOutOfChest(x - 1, y) && !set.contains(y * M + (x - 1)) && chest[y][x - 1] == 0) {
                    q.add(y * M + (x - 1));
                    set.add(y * M + (x - 1));
                }
                if(!IsOutOfChest(x, y + 1) && !set.contains((y + 1) * M + x) && chest[y + 1][x] == 0) {
                    q.add((y + 1) * M + x);
                    set.add((y + 1) * M + x);
                }
                if(!IsOutOfChest(x, y - 1) && !set.contains((y - 1) * M + x) && chest[y - 1][x] == 0) {
                    q.add((y - 1) * M + x);
                    set.add((y - 1) * M + x);
                }
            }
        }
        if(goodTomatoCount != tomatoCount)System.out.print(-1);
        else System.out.printf("%d", date - 1);
    }
}
