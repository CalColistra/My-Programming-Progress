/**
@Author Cal Colistra
Lab 10 
4/26/21
**/
import java.util.Scanner;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.FileOutputStream;
import java.util.HashMap;
import java.util.Collections;

public class lab10{
   public static void main(String [ ] args) {
        Scanner inputStream=null;
        PrintWriter outputStream=null;
         try {
          inputStream= new Scanner ( new FileInputStream("cities")); //java looks for file "cities.txt"
          outputStream = new PrintWriter( new FileOutputStream("output"));
       }
       catch (FileNotFoundException e) {
          System.out.println("Problem opening files");                  //if the file isn't found then we catch it here
          System.exit(0);
       }
   HashMap <String, Double> cities = new HashMap<String,Double>();
   String s;
   Double d;
   while (inputStream.hasNextLine()){
      s=inputStream.next();
      d=inputStream.nextDouble();
      cities.put(s,d);
      }
   
   double sum=0;
   for(String city :cities.keySet()){
      String key=city;
      double value=cities.get(key);
      sum=sum+value;
      }
   System.out.println("population sum= "+sum);
   
   Scanner input= new Scanner(System.in);
   String c="";
   while(cities.containsKey(c)==false){
      System.out.println("Enter a city");
      c=input.next();
      }
   System.out.println("The population for "+c+" is: "+cities.get(c));
   
   HashMap <String, Double> newCities = new HashMap<String,Double>();
   for(String city :cities.keySet()){
      String key=city;
      double value=cities.get(key);
      value=value+(value*.1);
      newCities.put(key,value);
      }
   System.out.println("New populations: \nPhiladelphia: "+newCities.get("Philadelphia")+"\nDallas: "+newCities.get("Dallas")+"\nSanAntonio: "+newCities.get("SanAntonio"));
   }//end main
}//end class