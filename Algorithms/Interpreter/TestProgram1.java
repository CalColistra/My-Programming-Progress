
public class TestProgram1 extends Interpreter{

	public static void main(String[] args) {
		int  m2[] = {  9,
                -5,
                12,
                15,
                3,
                CLR,    0,
                LDI,   45,
                ADDI,   2,
                ST,     1,
                LDI,    1,
                LDM,    1,
                CLR,    0,
                HALT,   0
  };
  interpret( m2, 5 );

	}

}
