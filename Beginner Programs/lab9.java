/**
@Author Cal Colistra
Lab 9
3/29/21
Recursive methods
**/
public class lab9{

/**recursive method to calculate interest
@param double amount, double interest(enter in decimal form), int numYears
@return double amount **/
   public static double investment(double amount, double interest, int numYears){
      //base case
      if (numYears==0)
         return amount;
      //recuursive case:
      numYears--;
      return investment((amount+(amount*interest)), interest, numYears);
      }
      
/**method to change letters pi to 3.14
@param String s
@return String**/
   public static String changePi(String s, int index){
      //base case:
      if (s==null||index>s.length()-1)
         return s;
      //recursive case:
      if (s.charAt(index)=='p' && s.charAt(index+1)=='i'){
         s=s.substring(0,index)+"3.14"+s.substring(index+2,s.length());
         index++;
         return changePi(s, index);
            }
      else {
      index++; 
      return changePi(s, index);
      }
      }
      
/**method to compute number of pins depending on the number of rows
@param int rows, int pins
@return int pins**/
   public static int numPins(int rows, int pins){
      //base case:
      if (rows<1)
         return pins;
      else{  //recursive case:
         pins=pins+rows;
         rows=rows-1;
         return numPins(rows, pins);
         }
      } 
      
/**method to compute amount of handshakes
@param int numPpl, int numHS
@return numHS**/
   public static int handshake(int numPpl, int numHS){
      //base case:
      if (numPpl==1)
         return numHS;
      else{  //recursive case:
         numHS=numHS+(numPpl-1);
         numPpl=numPpl-1;
         return handshake(numPpl, numHS);
         }
      }

/**method to convert number to binary
@param int n
void**/
   public static void binary(int n){
      //base case:
      if (n==0){
         System.out.print("");
         }
      else {
         binary(n/2);
         System.out.print(n%2);
         }
      }
      
   public static void main(String [] args){
      System.out.println(investment(1000, .10, 3));
      System.out.println(changePi("asdpidj", 0));
      System.out.println("3 rows has "+numPins(3,0)+" pins");
      System.out.println("4 rows has "+numPins(4,0)+" pins");
      System.out.println("5 rows has "+numPins(5,0)+" pins");
      System.out.println("8 rows has "+numPins(8,0)+" pins");  
      System.out.println("4 people = "+handshake(4,0)+" total handshakes");
      System.out.println("6 people = "+handshake(6,0)+" total handshakes");  
      System.out.println("2 people = "+handshake(2,0)+" total handshakes");      
      System.out.print("23 converted to binary= ");
      binary(23);
   }
}//end class