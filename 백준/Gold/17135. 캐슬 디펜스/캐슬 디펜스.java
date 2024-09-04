import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int N, M, D;
    static int[][] map;
    static int[] archerPositions = new int[3];
    static List<Enemy> initialEnemies = new ArrayList<>();
    static int maxKills;

    static class Enemy implements Comparable<Enemy> {
        int x, y, distanceToArcher;

        public Enemy(int y, int x) {
            this.y = y;
            this.x = x;
        }

        @Override
        public int compareTo(Enemy other) {
            if (this.distanceToArcher == other.distanceToArcher) {
                return this.x - other.x; // 왼쪽에 있는 적을 우선
            }
            return this.distanceToArcher - other.distanceToArcher; // 거리 우선
        }
    }

    public static void simulate() {
        List<Enemy> enemies = new ArrayList<>();
        for (Enemy enemy : initialEnemies) {
            enemies.add(new Enemy(enemy.y, enemy.x));
        }

        int currentKills = 0;

        while (!enemies.isEmpty()) {
            Set<Enemy> enemiesToRemove = new HashSet<>();

            for (int archerX : archerPositions) {
                PriorityQueue<Enemy> targetQueue = new PriorityQueue<>();
                for (Enemy enemy : enemies) {
                    enemy.distanceToArcher = getDistance(N, archerX, enemy.y, enemy.x);
                    if (enemy.distanceToArcher <= D) {
                        targetQueue.offer(enemy);
                    }
                }

                if (!targetQueue.isEmpty()) {
                    enemiesToRemove.add(targetQueue.poll());
                }
            }

            currentKills += enemiesToRemove.size();
            enemies.removeAll(enemiesToRemove);

            for (Iterator<Enemy> it = enemies.iterator(); it.hasNext();) {
                Enemy enemy = it.next();
                enemy.y++;
                if (enemy.y >= N) {
                    it.remove(); // 성에 도달한 적 제거
                }
            }
        }

        maxKills = Math.max(maxKills, currentKills);
    }

    public static void dfs(int count, int start) {
        if (count == 3) {
            simulate();
            return;
        }

        for (int i = start; i < M; i++) {
            archerPositions[count] = i;
            dfs(count + 1, i + 1);
        }
    }

    public static int getDistance(int archerY, int archerX, int enemyY, int enemyX) {
        return Math.abs(archerX - enemyX) + Math.abs(archerY - enemyY);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        D = Integer.parseInt(st.nextToken());

        map = new int[N][M];
        for (int y = 0; y < N; y++) {
            st = new StringTokenizer(br.readLine());
            for (int x = 0; x < M; x++) {
                map[y][x] = Integer.parseInt(st.nextToken());
                if (map[y][x] == 1) {
                    initialEnemies.add(new Enemy(y, x));
                }
            }
        }

        maxKills = 0;
        dfs(0, 0);
        System.out.println(maxKills);
    }
}
