/******
Cal Colistra
Project 1: Math game
2-4-21
***********/
import java.util.Random;
import java.util.Scanner;
import java.util.ArrayList;
public class Game{//begin class
      Random randgen= new Random();
      Scanner input= new Scanner(System.in);
/**static variable to subtract the user points if they get a question wrong**/
public static int points=5;
/**method to generate a random number between 50 and 100**/
public static int numberGen(){
   int min = 50;
   int max = 100;
   int num = (int)(Math.random() * (max - min + 1) + min);
   return num;
   }
/**method to generate a random sign (either + or -)**/
public static String signGen(int a){
   String sign;
      if (a==0)
         sign="+";
      else
         sign="-";
   return sign;
   }
/**Method to check if the answer is correct**/
public static boolean check(int a, int b){
   boolean r;
   if (b!=a)
      r=false;
   else
      r=true;
   return r;
   }
/**method to tell the user if they are correct**/
public static String displayResult(boolean a){
   String result;
   if (a==true)
      result="Correct!";
   else
      result="Incorrect :(";
   return result;
   }
  
   public static void main(String [] args){//begin main
      Random randgen= new Random();
      Scanner input= new Scanner(System.in);
   /**Asks the user their name**/
   System.out.println("Welcome to Cal's math game, please enter your name:");
   String userName=input.nextLine();
   /**Explaining the rules of the game to the user**/
   System.out.println("Hi, "+userName+"!"+" Here are the rules:\nIn this game you will need to answer math questions as quick as possible!\nIf you get a question wrong, it will reset your time and give you one more attempt with new numbers.\nAt the end, you will see how many questions you got correct \nand how long it took you to answer each question on average.");
   /**Asking the user if they are ready**/
   System.out.println("Type 'yes' if you are ready to play!");
   String ready=input.nextLine();
   /**Nested loops to create 4 questions**/
   if (ready.equals("yes")||ready.equals("Yes")){
      /**initialize a long that will be used to add up each of the response times**/
      long all=0;
      /**initialize a counter for amount of questions the user answered**/
      int qCount=0;
      for (int i=0;i<5;i++){
      /**initializing random numbers and symbols for generating questions**/
         int j=randgen.nextInt(2);
         int f=randgen.nextInt(2);
         String symbol1=signGen(j);
         String symbol2=signGen(f);
         int num1=numberGen();
         int num2=numberGen();
         int num3=numberGen();
         int bNum1=numberGen();
         int bNum2=numberGen();
         int bNum3=numberGen();         
         int correctAns=0;
         System.out.println("Question "+(i+1)+":");
         System.out.println(num1+symbol1+num2+symbol2+num3+"= ");
         if (symbol1.equals("+")&&symbol2.equals("+"))
            correctAns=num1+num2+num3;
         else if (symbol1.equals("+")&&symbol2.equals("-"))
            correctAns=num1+num2-num3;
         else if (symbol1.equals("-")&&symbol2.equals("-"))
            correctAns=num1-num2-num3; 
         else
            correctAns=num1-num2+num3;
         /**start timer**/
         long startTime=System.currentTimeMillis();
   
         int ans=input.nextInt();
         qCount++;
         boolean result=check(correctAns, ans);
         String dR=displayResult(result);
         long endTime;
            if (dR.equals("Incorrect :(")){
            startTime=System.currentTimeMillis();
               System.out.println(dR+" try again:\n"+bNum1+symbol1+bNum2+symbol2+bNum3+"= ");
                  if (symbol1.equals("+")&&symbol2.equals("+"))
                     correctAns=bNum1+bNum2+bNum3;
                  else if (symbol1.equals("+")&&symbol2.equals("-"))
                     correctAns=bNum1+bNum2-bNum3;
                  else if (symbol1.equals("-")&&symbol2.equals("-"))
                     correctAns=bNum1-bNum2-bNum3; 
                  else
                     correctAns=bNum1-bNum2+bNum3;                 
               int ans2=input.nextInt();
               qCount++;
               endTime=System.currentTimeMillis();
               boolean result2=check(correctAns, ans2);
               dR=displayResult(result2);
                  if (dR.equals("Incorrect :(")){
                     points=points-1;
                     System.out.println(dR+"\n");
                     }
                  else
                     System.out.println(dR);
               }
            else 
               System.out.println(dR);
               endTime=System.currentTimeMillis();
               
               
                 
            long time=endTime-startTime; 
            all=all+time;
            
         
     
            }
         long timeAvg=(all/qCount);
         double conv=timeAvg*(.001);
         System.out.println("You got "+points+" questions correct!\nOn average, it took you "+conv+" seconds to answer each question.");
         System.out.println("Thank you for playing....Have a Great Day!");
         } 
      
   }//end main
}//end class