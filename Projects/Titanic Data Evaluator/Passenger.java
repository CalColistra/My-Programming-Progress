/**
@Author Cal Colistra
Project 3
3/19/21
**/
public class Passenger{
/**instacne variables**/
private int status;
private boolean child;
private String sex;
private boolean survivor;
/**constructor
@param int, boolean, String, boolean**/
public Passenger(int s, boolean c, String sx, boolean su){
   this.status=s;
   this.child=c;
   this.sex=sx;
   this.survivor=su;
   try{
   if (this.status<1||this.status>4)
      throw new OutOfRangeException("Out of range");
   else if (!((this.sex.equals("male")||this.sex.equals("female"))))
      throw new OutOfRangeException("Out of range");
      }
   catch (OutOfRangeException e){
      System.out.println(e.getMessage());
      }
   }
/**accessors**/
public void setStatus(int s){
   this.status=s;
   }
public void setChild(boolean c){
   this.child=c;
   }
public void setSex(String s){
   this.sex=s;
   }
public void setSurvivor(boolean s){
   this.survivor=s;
   }
public int getStatus(){
   return this.status;
   }
public boolean getChild(){
   return this.child;
   }
public String getSex(){
   return this.sex;
   }
public boolean getSurvivor(){
   return this.survivor;
   }
/**to String**/
public String toString(){
   String s="";
   if (this.status==1)
      s="1st Class";
   else if (this.status==2)
      s="2nd Class";
   else if (this.status==3)
      s="3rd Class";
   else if (this.status==4)
      s="Crew";
   return "This passenger is "+s+"\nThis passenger is a child: "+this.getChild()+"\nSex: "+this.getSex()+"\nDid this passenger survive: "+this.getSurvivor();
   }
}//end class