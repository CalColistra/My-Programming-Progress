
public class TestProgram2 extends Interpreter{

	public static void main(String[] args) {
		int  m2[] = {  2,
                CLR,    0,
                ADDM,   0,
                ADDI,  12,
                LDI,    3,
                ADDI,   2,
                ST,     0,
                LDI,    1,
                LDM,    0,
                CLR,    0,
                HALT,   0
  };
  interpret( m2, 1 );
	}

}
