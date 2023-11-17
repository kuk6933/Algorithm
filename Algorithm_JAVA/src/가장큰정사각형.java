import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class 가장큰정사각형 {

    static int n,m,ans;
    static int dp[][];
    static int board[][];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        dp = new int[n+1][m+1];
        board = new int[n+1][m+1];

        for(int i=0; i<n; i++) {
            String input = br.readLine();
            for(int j=0; j<m; j++) {
                board[i][j] = dp[i][j] = input.charAt(j) -'0';
                if(board[i][j] == 1) {
                    ans = 1;
                }
            }
        }

        for(int i=1; i<n; i++) {
            for(int j=1; j<m; j++) {
                if(board[i][j] == 1) {
                    dp[i][j] = Math.min(dp[i-1][j-1], Math.min(dp[i-1][j], dp[i][j-1]))+1;
                }
                if(dp[i][j] > ans ) {
                    ans = dp[i][j];
                }
            }
        }
        System.out.println(ans*ans);
    }
}
