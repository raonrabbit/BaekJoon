import java.io.*;
import java.util.*;

public class Main {
    static int N, M, K;
    static long[] arr;
    static long[] tree;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        arr = new long[N + 1];
        tree = new long[4 * N + 1];

        for(int i = 1; i < N + 1; i++){
            arr[i] = Long.parseLong(br.readLine());
        }

        build(1, 1, N);

        for(int i = 0; i < M + K; i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            long b = Long.parseLong(st.nextToken());
            long c = Long.parseLong(st.nextToken());


            if(a == 1){
                Update(1, 1, N, b, c);
            } else {
                System.out.println(query(1, 1, N, b, c));
            }
        }
    }

    public static void build(int cur, int start, int end){
        if(start == end){
            tree[cur] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(2 * cur, start, mid);
            build(2 * cur + 1, mid + 1, end);
            tree[cur] = tree[2 * cur] + tree[2 * cur + 1];
        }
    }

    public static long query(int cur, int start, int end, long L, long R){
        if(R < start || end < L) return 0;

        if(L <= start && end <= R){
            return tree[cur];
        }

        int mid = (start + end) / 2;
        long leftSum = query(2 * cur, start, mid, L, R);
        long rightSum = query(2 * cur + 1, mid + 1, end, L, R);
        return leftSum + rightSum;
    }

    public static void Update(int cur, int start, int end, long target, long val){
        if(start == end){
            tree[cur] = val;
        } else {
            int mid = (start + end) / 2;
            if(start <= target && target <= mid){
                Update(2 * cur, start, mid, target, val);
            } else {
                Update(2 * cur + 1, mid + 1, end, target, val);
            }

            tree[cur] = tree[2 * cur] + tree[2 * cur + 1];
        }
    }
}
