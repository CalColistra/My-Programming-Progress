

public class test2 extends Interpreter{

	public static void main(String[] args) {
		int  m2[] = { 
					//index
	    		 5,	//0
                -5,	//1
                11,	//2
                13,	//3
                CLR,        //"program" starts here
                ADDI,  1,
                ADDI,   2,
                ADDM,   0,
                ADDM,   3,
                CLR,
                HALT
	       				};
  interpret( m2, 4 );

	}

}
