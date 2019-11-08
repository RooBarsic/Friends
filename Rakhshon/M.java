import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        for(int i = 1; i <= t; i++){
            int ans = solveProblem(scanner);
            System.out.println(ans);
        }
    }

    public static int solveProblem(Scanner scanner){
        int n = scanner.nextInt();
        int[] arr = new int[2010];
        Map<Integer, Integer> kol = new HashMap<>();
        for(int i = 1; i <= n; i++){
            arr[i] = scanner.nextInt();
            kol.put(arr[i], kol.getOrDefault(arr[i], 0) + 1);
        }

        int ans = 0;
        for(int i = 1; i <= n; i++){
            kol.put(arr[i], kol.get(arr[i]) - 1);
            for(int j = i + 1; j < n; j++){
                kol.put(arr[j], kol.get(arr[j]) - 1);
                int x = 2 * arr[j] - arr[i];
                ans += kol.getOrDefault(x, 0);
            }
            for(int j = i + 1; j < n; j++){
                kol.put(arr[j], kol.get(arr[j]) + 1);
            }
        }
        return ans;
    }
}
