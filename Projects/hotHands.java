/**Project 4- hot hands
@author Cal Colistra
4/10/21**/
import java.util.Random;


public class hotHands{
Random rand = new Random();

/**method to flip a coin
@return String h or t**/
public static String coinFlip(){
      Random rand = new Random();
      String ans="";
      int a=rand.nextInt(2);
      if (a==0) 
         ans="h";
      else if (a==1)
         ans="t";
      return ans;
   }
/**method to run a trial
@return String [] Array that contains 100 flips**/
public static String[] trial(){
   String [] a=new String [100];
   for (int i=0;i<100;i++){
      a[i]=coinFlip();
      }
   return a;
   }


public static void main(String [] args){


double ratioSum=0;
double avg=0;
/**loop to do 5000 trials**/
for (int i=0;i<5001;i++){
   System.out.println("Trial #"+i+":");
   String [] a=trial();
   int h4=0;
   int h5=0;
   /**loop to do 1 trial (of 100 coin flips) and check for consectuive h's**/
   for (int j=0;j<a.length-4;j++){
      /**if statement to check for 4 consecutive h's**/
      if (a[j].equals("h")&&a[j+1].equals("h")&&a[j+2].equals("h")&&a[j+3].equals("h")&&j<a.length-4){
         /**if statement to check if there is a 5th h
         if so, increment variables and add 4 to the index to avoid counting twice**/
         if (a[j+4].equals("h")&&j<a.length-4){
            h4++;
            h5++;
            j=j+4;
            }
         /**else if to check if the flip following the 4th h is a t
         if so, increment variable and add 3 to index to avoid counting twice**/
         else if (a[j+4].equals("t")&&j<a.length-4){
            j=j+3;
            h4++;
            }
         }
      }
      /**print number of hhhh or hhhhh for each trial**/
      System.out.println("# of hhhh: "+h4);
      System.out.println("# of hhhhh: "+h5); 
      /**calculate and print ratio for each trail**/     
      double ratio=0;
      if (h4==0)
         ratio=0;
      else
         ratio=(double)h5/h4;
      System.out.println("Ratio: "+ratio+"\n");
      /**add each trial's ratio to find total**/
      ratioSum=ratioSum+ratio;
      /**check for last trial & divide ratio total by 5000 & print the avg ratio**/
      if (i==5000){
         avg=(ratioSum)/(double)5000;
         System.out.println("Average ratio over 5000 trials: "+avg);   
         }      
   }
   
   }//end main
}//end class