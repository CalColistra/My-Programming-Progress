import java.util.*;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.FileOutputStream;
import java.math.RoundingMode;
import java.text.DecimalFormat;

public class fileStreamtest_Titanic {
    public static void main(String [ ] args) {
    DecimalFormat df = new DecimalFormat("#.00");
       //need to declare input and output outside the try/catch block
        Scanner inputStream=null;
        PrintWriter outputStream=null;
        ArrayList<Passenger> group= new ArrayList<Passenger>();
       try {
          inputStream= new Scanner ( new FileInputStream("titanic_data.txt.txt")); //java looks for file "titanic_data.txt"
          outputStream = new PrintWriter( new FileOutputStream("Titanic output"));
       }
       catch (FileNotFoundException e) {
          System.out.println("Problem opening files");       //if the file isn't found then we catch it here
          System.exit(0);
       }
       //Here you declare and initialize the varibales you need in loop
       boolean ch, su;
       int st;
       String sx;
       while (inputStream.hasNextLine( ) ) {  //keeps running until there is no more in the file
            st=inputStream.nextInt();
            ch=inputStream.nextBoolean();
            sx=inputStream.next();
            su=inputStream.nextBoolean();
            group.add(new Passenger(st, ch, sx, su));
       }
       outputStream.println(df.format(childP(group))+"% of passengers are children");
       outputStream.println(df.format(adultP(group))+"% of passengers are adults");
       outputStream.println(df.format(maleP(group))+"% of passengers are male");
       outputStream.println(df.format(femaleP(group))+"% of passengers are female"); 
       outputStream.println(df.format(surviveP(group))+"% of passengers are survived");     

       inputStream.close( );
       outputStream.close ( );
       }
/**method to calculate the % children
@param ArrayList of Passenger
@return double**/
public static double childP(ArrayList<Passenger> array){
   double p;
   double sum=0;
   double ch=0;
   for (int i=0;i<array.size();i++){
      sum++;
      if (array.get(i).getChild()==true)
         ch++;
      }
      p=(ch/sum)*100;
   return p;
   }
/**method to calculate the % adult
@param ArrayList of Passenger
@return double**/
public static double adultP(ArrayList<Passenger> array){
   double p;
   double sum=0;
   double ch=0;
   for (int i=0;i<array.size();i++){
      sum++;
      if (array.get(i).getChild()==false)
         ch++;
      }
      p=(ch/sum)*100;
   return p;
   }
/**method to calculate the % male
@param ArrayList of Passenger
@return double**/
public static double maleP(ArrayList<Passenger> array){
   double p;
   double sum=0;
   double ch=0;
   for (int i=0;i<array.size();i++){
      sum++;
      if (array.get(i).getSex().equals("male"))
         ch++;
      }
      p=(ch/sum)*100;
   return p;
   }
/**method to calculate the % female
@param ArrayList of Passenger
@return double**/
public static double femaleP(ArrayList<Passenger> array){
   double p;
   double sum=0;
   double ch=0;
   for (int i=0;i<array.size();i++){
      sum++;
      if (array.get(i).getSex().equals("female"))
         ch++;
      }
      p=(ch/sum)*100;
   return p;
   }
/**method to calculate the % survivors
@param ArrayList of Passenger
@return double**/
public static double surviveP(ArrayList<Passenger> array){
   double p;
   double sum=0;
   double ch=0;
   for (int i=0;i<array.size();i++){
      sum++;
      if (array.get(i).getSurvivor()==true)
         ch++;
      }
      p=(ch/sum)*100;
   return p;
   }
}
