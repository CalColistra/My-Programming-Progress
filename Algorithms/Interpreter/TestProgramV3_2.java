
public class TestProgramV3_2 extends Interpreter{

	public static void main(String[] args) {
		int m2[] = {15,
				8,
				2,
				11,
				DBG,	0,	0,
				CLR,	r1,	0,
				ADDI,	r2,	4,
				LDM,	r4, 3,
				LDI,	r1,	10,
				ADDR,	r4,	r2,
				ADDR,	r2,	r1,
				ST,		2,	r0,
				ADDM,	r3,	2,
				ADDI,	r4,	2,
				NODBG,	0,	0,
				HALT,	0,	0
};
interpret( m2, 4 );

	}

}
