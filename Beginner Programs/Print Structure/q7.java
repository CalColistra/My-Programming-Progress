import java.util.Scanner;

public class q7 {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);

		System.out.println("Enter an integer n in which n>=1: ");

        int n = sc.nextInt();
        
        String a = "1";
        int c = 1;
        int rowc = n-1;

		for(int i=1; i<=n; i++) {
			for(int j=1; j<=rowc; j++){
				System.out.print(" ");
			}
			if (a.equals("1")) {
			System.out.println(a);
			}
			else {
				System.out.println(a);
			}
			c++;
			a = c+a+c;
			rowc--;
			
			
		}	
		
		
	}

}
