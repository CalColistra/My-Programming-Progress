/**Cal Colistra
Project 2
Airline Seats
**/

import java.util.Arrays;
import java.util.Scanner;
public class projectTwo{
   /**make scanner input for class**/
   Scanner input= new Scanner(System.in);
   public static void main(String [] args){
   /**make scanner input for main**/
   Scanner input= new Scanner(System.in);
   /**initialize an int for seat counter**/
   int seatCounter=28;
   /**Make a 2d array**/
   char[][] seats= new char [7][5];
   /**int to keep track of row number**/
   int rowNum=1;
   
   /**nested loop to initialize the array[][] of airplane seats**/
   for (int row=0;row<7;row++){
      for (int col=0;col<5;col++){
         if (col==0){
            if (rowNum==1)
               seats[row][col]='1';
            else if (rowNum==2)
               seats[row][col]='2'; 
            else if (rowNum==3)
               seats[row][col]='3'; 
            else if (rowNum==4)
               seats[row][col]='4';
            else if (rowNum==5)
               seats[row][col]='5';
            else if (rowNum==6)
               seats[row][col]='6';
            else if (rowNum==7)
               seats[row][col]='7';                                            
            }
         else if (col==1){
            seats[row][col]='A';
            }
         else if (col==2)
            seats[row][col]='B';
         else if (col==3)
            seats[row][col]='C';
         else if (col==4)
            seats[row][col]='D';
            }
            rowNum++;
         }

   System.out.println("Enter 'y' if you want to pick a plane seat");
   String s=input.nextLine();
while (s.equals("y")||s.equals("Y")){
   print(seats);
   remove(seats);
   print(seats);
   System.out.println("Enter 'y' if you want to pick another plane seat");
   s=input.nextLine();
}
   }//end main
   
   /**method to print 2d array
   @param Array[][]**/
   public static void print(char [][]a){
      System.out.println("Row");
      for (int i=0;i<a.length;i++){
         for(int j=0;j<a[0].length;j++){
            System.out.print(a[i][j]+"\t");
            }
            System.out.println();
         }
      }  
   /**method to ask take the users input and remove their seat
   @param Array[][]**/ 
   public static void remove(char [][]a){
   Scanner input= new Scanner(System.in);
      System.out.println("Please enter the row number and seat letter to choose a seat.\nFor example, to choose seat B in row 3 you would enter: '3B'");
      String choice=input.nextLine();
      char r=choice.charAt(0);
      char s=choice.charAt(1);
      int rInt=0;
      int sInt=0;
      if (r=='1')
         rInt=0;
      else if (r=='2')
         rInt=1;
      else if (r=='3')
         rInt=2;
      else if (r=='4')
         rInt=3;
      else if (r=='5')
         rInt=4;
      else if (r=='6')
         rInt=5;
      else if (r=='7')
         rInt=6;
      if (s=='A')
         sInt=1;
      else if (s=='B')
         sInt=2;
      else if (s=='C')
         sInt=3;
      else if (s=='D')
         sInt=4;
      
      if (a[rInt][sInt]=='X')
         System.out.println("The seat you have chosen is not available, please pick a new seat");
      else
         a[rInt][sInt]='X';
      }
}