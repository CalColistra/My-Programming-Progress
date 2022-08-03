

public class test1 extends Interpreter{

	public static void main(String[] args) {
		int  m2[] = {  9,
                -5,
                CLR,    0,
                ADDI,  17,
                ADDI,   2,
                ST,     0,
                ADDM,   0,
                ADDM,   1,
                CLR,    0,
                HALT,   0
  };
  interpret( m2, 2 );

	}

}
