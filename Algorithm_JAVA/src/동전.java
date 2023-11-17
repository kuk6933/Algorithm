import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 동전 {
    static int t,n,m;
    static int[] arr;
    static int[][] dp;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        t = Integer.parseInt(st.nextToken());
        for(int T=0; T <t; T++) {
            st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken());
            arr = new int[n+1];
            st = new StringTokenizer(br.readLine());
            for(int i=1; i<=n; i++) {
                arr[i] = Integer.parseInt(st.nextToken());
            }
            st = new StringTokenizer(br.readLine());
            m = Integer.parseInt(st.nextToken());
            dp = new int[n+1][m+1];

            for(int i=0; i<=m; i++) {
                if(arr[1]*i <= m) {
                    dp[1][arr[1]*i] = 1;
                } else {
                    break;
                }
            }

            for(int i=2; i<=n; i++) {
                for(int j=0; j<=m; j++) {
                    if(dp[i-1][j] > 0) {
                        for(int k=0; k<=m; k++) {
                            if(j + arr[i]*k<= m) {
                                dp[i][j+ arr[i]*k] += dp[i-1][j];
                            } else {
                                break;
                            }
                        }
                    }
                }
            }
            System.out.println(dp[n][m]);
        }
    }
}
