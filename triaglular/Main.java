public class Main {
    public static void main(String[] args) {
        int n = 10;
        int fullWidth = 2*n-1;
        boolean flag = true;
        int startPoint;
        for(int i = 1; i <= n; i++) {
            flag = true;
            int levelLength = 2*i-1;
            startPoint = (fullWidth - levelLength) / 2;
            for(int j=1; j <= fullWidth; j++) {
                if(j <= startPoint || j > startPoint+levelLength) {
                    System.out.print(" ");
                }else {
                    if (flag) {
                        System.out.print("*");
                        flag = false;
                    }else {
                        System.out.print(" ");
                        flag = true;
                    }
                }
            }
            System.out.println();
        }
    }
}