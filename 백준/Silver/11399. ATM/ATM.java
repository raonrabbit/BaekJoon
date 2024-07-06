import java.util.Scanner;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int[] people = new int[N];
		int result = 0;
		
		for(int i = 0; i < N; i++) {
			people[i] = sc.nextInt();
		}
		
		for(int i = 1; i < N; i++) {
			for(int j = 0; j < N - i; j++) {
				if(people[j] > people[j + 1]) {
					int temp = people[j];
					people[j] = people[j + 1];
					people[j + 1] = temp;
				}
			}
		}
		
		int temps = 0;
		for(int n : people){
			result += temps + n;
			temps += n;
		}
		
		System.out.printf("%d", result);
	}

}