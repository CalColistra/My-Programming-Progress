import java.util.Scanner;

public class Q5PrintStructure {

       public static void main(String[] args) {

             Scanner sc = new Scanner(System.in);

             System.out.println("Enter an interger, which is no less than 2: ");

             int n = sc.nextInt();

             if (n>=2){

                    printStructure(n);

             } else {

                    System.out.println("Invalid value!");

             }

       }

       public static void printStructure(int m){
    	   int rows = 2*m-1;
    	   int count = 0;
    	   int star = 0;
    	   int dStar = m-1;
    	 

         for(int i=1; i<=rows; i++) {//rows
        	 System.out.println("");
        
        	 if(count<m) {
        		 for(int j=0; j<=star; j++) {//print star
        			 System.out.print("*");
        		 }
        	  count++;
              star++;
        	 } //end if
        	 else if(count>=m && count<m*2-1) {
        		 for(int j=dStar; j>0; j--) {
        			 System.out.print("*");
        		 }
        		 dStar--;
        	 }//end else if
    	 }//rows
	
       }//end printStructure()
       
}//end class

