/**
@Author Cal Colistra
Lab 10 part 2
4/26/21
**/
import java.util.Scanner;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.FileOutputStream;
import java.util.Collections;

public class lab10part2{
   public static void main(String [ ] args) {
       /**initialize scanner & print writer**/
       Scanner inputStream=null;
       PrintWriter outputStream=null;
       /**try and catch to set up inputStream and outputStream**/
       try {
          inputStream= new Scanner ( new FileInputStream("Tarzan.txt")); 
          outputStream = new PrintWriter( new FileOutputStream("output2"));
       }
       catch (FileNotFoundException e) {
          System.out.println("Problem opening files");                  //if the file isn't found then we catch it here
          System.exit(0);
       }
/**set up scanner for user input**/
Scanner input= new Scanner(System.in);     
/**while loop to go through the text file**/
String word="";
String clue="";
String choice="";
int count=0;
   while (inputStream.hasNextLine()){
      word=inputStream.next();
      /**if statement to check for '<'**/
      if (word.charAt(0)=='<'){
         clue=word.substring(1, word.length()-1);
         System.out.println("enter a "+clue);
         choice=input.next();
         outputStream.print(choice+" ");
         count++;
         /**if statement to go to next line after 15 words**/
         if (count>14){
            outputStream.print("\n");
            count=0;
            }
         }
      else{
         outputStream.print(word+" ");
         count++;
         /**if statement to go to next line after 15 words**/
         if (count>14){
            outputStream.print("\n");
            count=0;
            }         
         }
      }
inputStream.close( );
outputStream.close ( );
       
   }//end main
}//end class