public class Q4MergyArray {

       public static void main(String[] args) {

             int[] arrayA = {1,3,5,7,9};

             int[] arrayB = {11,13,15,17,19};
             
             int[] arrayC = new int[arrayA.length + arrayB.length];
            		 
         
             for (int i=0; i<arrayA.length + arrayB.length; i++) {
            
            	 if(i<arrayB.length){ 
            		 arrayC[i] = arrayA[i];   
            	 }
            
            	 else if(i>arrayA.length-1) {
            		 arrayC[i] = arrayB[i-arrayA.length];
            	 }
         
            }
         
         

            for (int i=0; i<arrayA.length + arrayB.length; i++){
       
                    System.out.print(arrayC[i]+"  ");

             }

       }

}
