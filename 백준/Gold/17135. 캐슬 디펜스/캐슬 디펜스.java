import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int N, M, D;
    static int[][] map;
    static int[] ArcherPosition;
    static List<Enemy> EnemyPosition;
    static int max;

    static class Enemy implements Comparable<Enemy> {
        public int x, y;
        public int DistanceWithArcher;

        public Enemy(int y, int x) {
            this.y = y;
            this.x = x;
        }

        @Override
        public int compareTo(Enemy o) {
            if(this.DistanceWithArcher == o.DistanceWithArcher) return this.x - o.x;
            return this.DistanceWithArcher - o.DistanceWithArcher;
        }
    }

    public static void Simulation() {
        List<Enemy> enemies = new LinkedList<>();
        for(Enemy e : EnemyPosition){
            enemies.add(new Enemy(e.y, e.x));
        }
        int killEnemyCount = 0;
        while(!enemies.isEmpty()) {
            Set<Enemy> removeEnemyList = new HashSet<>();
            for (int archerXPos : ArcherPosition) {
                PriorityQueue<Enemy> pq = new PriorityQueue<>();
                for (Enemy enemy : enemies) {
                    enemy.DistanceWithArcher = GetDistance(N, archerXPos, enemy.y, enemy.x);
                    if(enemy.DistanceWithArcher <= D) {
                        pq.add(enemy);
                    }
                }

                if(!pq.isEmpty()) {
                    removeEnemyList.add(pq.poll());
                }
            }

            for (Enemy enemy : removeEnemyList) {
                enemies.remove(enemy);
                killEnemyCount++;
            }

            List<Enemy> movedEnemies = new LinkedList<>();
            for (Enemy enemy : enemies) {
                enemy.y += 1;
                if (enemy.y < N) movedEnemies.add(enemy);
            }
            enemies = movedEnemies;
        }
        max = Math.max(max, killEnemyCount);
    }

    public static void DFS(int count, int start) {
        if (count == 3) {
            Simulation();
            return;
        }

        for (int i = start; i < M; i++) {
            ArcherPosition[count] = i;
            DFS(count + 1, i + 1);
        }
    }

    public static int GetDistance(int archerY, int archerX, int enemyY, int enemyX) {
        return Math.abs(archerX - enemyX) + Math.abs(archerY - enemyY);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        D = Integer.parseInt(st.nextToken());

        map = new int[N + 1][M];
        ArcherPosition = new int[3];
        EnemyPosition = new LinkedList<>();

        for(int n = 0; n < N; n++) {
            st = new StringTokenizer(br.readLine());
            for(int m = 0; m < M; m++) {
                map[n][m] = Integer.parseInt(st.nextToken());
                if(map[n][m] == 1) EnemyPosition.add(new Enemy(n, m));
            }
        }

        max = 0;
        DFS(0, 0);
        System.out.print(max);
    }
}
