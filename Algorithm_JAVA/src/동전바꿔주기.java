import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 동전바꿔주기 {

    static class Pair {
        int money;
        int number;

        Pair(int money, int number) {
            this.money = money;
            this.number = number;
        }
    }
    class Main {
        static int t,k;
        static long dp[][];
        static Pair arr[];
        public static void main(String[] args) throws IOException {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            StringTokenizer st = new StringTokenizer(br.readLine());
            t = Integer.parseInt(st.nextToken());
            st = new StringTokenizer(br.readLine());
            k = Integer.parseInt(st.nextToken());
            dp = new long[k+1][t+1];
            arr = new Pair[k+1];

            for(int i=1; i<=k; i++) {
                st = new StringTokenizer(br.readLine());
                int p = Integer.parseInt(st.nextToken());
                int n = Integer.parseInt(st.nextToken());
                arr[i] = new Pair(p, n);
            }

            for(int i=0; i<=arr[1].number; i++) {
                if (arr[1].money*i <= t) {
                    dp[1][arr[1].money*i] = 1;
                }
            }
            for(int i=2; i<=k; i++) {
                for(int j=0; j<=t; j++) {
                    if(dp[i-1][j] > 0) {
                        for(int a = 0; a<=arr[i].number; a++) {
                            if(j + a*arr[i].money <= t) {
                                dp[i][j+a*arr[i].money] += dp[i-1][j];
                            }
                        }
                    }
                }
            }
            System.out.println(dp[k][t]);
        }
    }
}
