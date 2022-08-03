
public class TestProgramV3 extends Interpreter{

	public static void main(String[] args) {

			int m2[] = {15,
						8,
						2,
						DBG,	0,	0,
						CLR,	r1,	0,
						LDI,	r1,	10,
						LDM,	r2, 0,
						ADDR,	r1,	r2,
						ADDR,	r4,	r1,
						ST,		2,	r0,
						ADDM,	r3,	2,
						ADDI,	r3,	2,
						NODBG,	0,	0,
						CLR,	r1, 0,
						HALT,	0,	0
   };
   interpret( m2, 3 );
	}

}
