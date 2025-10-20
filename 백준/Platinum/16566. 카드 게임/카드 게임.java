import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    static int N, M, K;

    public static int binarySearch(int[] arr, int target){
        int start = 0;
        int end = M - 1;
        int mid = (start + end) / 2;

        while (start < end) {

            if (arr[mid] == 0) {
                int i = mid + 1;
                while (i < M && arr[i] == 0) i++;
                if (i >= M) {
                    i = M - 1;
                }
                start = i;
                mid = (start + end) / 2;
                continue;
            }

            if (arr[mid] < 0) {
                int temp = mid + arr[mid];
                if (temp < start) {
                    int i = mid + 1;
                    while (i < M && arr[i] <= 0) i++;
                    return i < M ? i : M - 1;
                }
                mid = temp;
                continue;
            }

            if (arr[mid] > target) {
                end = mid;
                mid = (start + end) / 2;
                continue;
            }

            start = mid + 1;
            mid = (start + end) / 2;
        }

        return start;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        int[] minsu = new int[M];
        st = new StringTokenizer(br.readLine());

        for(int i = 0; i < M; i++){
            minsu[i] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(minsu);

        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < K; i++){
            int chulsu = Integer.parseInt(st.nextToken());

            int result = binarySearch(minsu, chulsu);
            if (result >= M) result = M - 1;
            sb.append(minsu[result]).append('\n');

            if (result == 0 || minsu[result - 1] == 0) {
                minsu[result] = 0;
                int r = result + 1;
                while (r < M && minsu[r] < 0) {
                    minsu[r++] = 0;
                }
                continue;
            }

            if (minsu[result - 1] < 0) {
                int temp = minsu[result - 1];
                temp -= 1;
                minsu[result] = temp;
                int r = result + 1;
                while (r < M && minsu[r] < 0) {
                    minsu[r] = --temp;
                    r++;
                }
                continue;
            }

            int temp = -1;
            minsu[result] = temp;
            int r = result + 1;
            while (r < M && minsu[r] < 0) {
                minsu[r] = --temp;
                r++;
            }
        }

        System.out.print(sb);
    }
}
