import java.util.Random;

//----------------------------------------------------------------------
/*
  file  : Interpreter.java
  date  : 10/19/21
  author: Cal Colistra
  description: Interpreter V3
*/
//----------------------------------------------------------------------
public class Interpreter {

	static Random rand = new Random();			//initialize random umber generator
	
    static int PC;         						//program counter holds address of next instr
    
    static int r0v;								//declare 5 int var's to hold the value of each register
    static int r1v;	
    static int r2v;
    static int r3v;
    static int r4v;
    
    static boolean run_bit = true;  			//a bit that can be turned off to halt the machine
    static int  instr;       					//a var to hold the current instruction
    static int data;							//a var to hold the current data
    static int debug = 0;						//variable for debug(when active it prints Registers & PC)
    static final int rNum = 25; 				//variable to set the range of numbers for the random number generator
    
    static final int r0 = 2000;					//constants initialized for each register
    static final int r1 = 2001;
    static final int r2 = 2002;
    static final int r3 = 2003;
    static final int r4 = 2004;
    
    static final int CLR = 1000;				//instr to clear a register
    static final int ADDI = 1001;				//instr to add a value to a register
    static final int ADDM = 1002;				//instr to add a value from a memory location to a register
    static final int ADDR = 1012;				//instr to add the value in 2 registers and stores the value in the 1st register
    static final int LDI = 1101;				//instr to load a register with a value
    static final int LDM = 1110;				//instr to load a register with a value from a memory location
    static final int ST = 1011;					//instr to store a value from a register in a memory location
    static final int DBG = 1112;				//instr to turn on debugger
    static final int NODBG = 1122;				//instr to turn off debugger
    static final int HALT = 1111;				//instr to stop the processor
    
    
    //------------------------------------------------------------------

    public static void interpret ( int memory[], int starting_address ) {
    	initialize();
    	PC = starting_address;					//initialize PC to the specified starting address
        run_bit = true;							//start the processor
        while (run_bit) {						//check to make sure processor should be running
            instr = memory[PC];  				//fetch instruction into instr
            data = find_data(memory, instr);	//find data needed for specific instruction
            if (debug==1)System.out.println("instr= " +instr + " PC= " +PC+ ", DATA= "+data+",	 r0= " +r0v+ ", r1= " +r1v+
            		", r2= " +r2v+ ", r3= " +r3v+ ", r4= " +r4v);	//print for debugging
            execute(instr, memory, data);  		//execute instruction
            
        }
    }
    
    //--------------------------------------------------------------------
    
    public static void initialize () {
    	r0v = rand.nextInt(rNum);				//function to give all registers a unique random number
    	r1v = rand.nextInt(rNum);
    	while (r0v==r1v) r1v = rand.nextInt(rNum);
    	r2v = rand.nextInt(rNum);
    	while (r2v==r0v||r2v==r1v) r2v = rand.nextInt(rNum);
    	r3v = rand.nextInt(rNum);
    	while (r3v==r0v||r3v==r1v||r3v==r2v) r3v = rand.nextInt(rNum);
    	r4v = rand.nextInt(rNum);
    	while (r4v==r0v||r4v==r1v||r4v==r2v||r4v==r3v) r4v = rand.nextInt(rNum);
    	if (debug==1) System.out.println("INITIALIZE:  r0v= "+ r0v + ", r1v= "+r1v+", r2v= "+ r2v+ ", r3v= "+r3v+", r4v= "+r4v);
    }
    //--------------------------------------------------------------------
     
     
    private static int find_data ( int memory[], int instr ) {	//function that returns the data needed
    	if (instr==ADDI||instr==LDI) data=memory[PC+2];			// for a specific instruction
    	else if (instr==ADDM||instr==LDM) {						//check for which instruction
    		data=memory[PC+2];									//initialize data
    		data = memory[data];
    	}
    	else if (instr==ADDR||instr==ST) {						//check for instruction
    		if (memory[PC+2]==r0) data = r0v;					//initialize data according to specific register
    		else if (memory[PC+2]==r1) data = r1v;
    		else if (memory[PC+2]==r2) data = r2v;
    		else if (memory[PC+2]==r3) data = r3v;
    		else if (memory[PC+2]==r4) data = r4v;
    	}
    	return data;
    }
    //--------------------------------------------------------------------
    
    private static void execute ( int instr, int memory[], int data ) {
    															//function to execute instructions
    	if (instr==CLR) {										//check for which instruction
    		if (memory[PC+1]==r0) r0v=0;						//check which register to be modified
    		else if (memory[PC+1]==r1) r1v=0;					//and modify it
    		else if (memory[PC+1]==r2) r2v=0;
    		else if (memory[PC+1]==r3) r3v=0;
    		else if (memory[PC+1]==r4) r4v=0;
    	}
    	else if (instr==HALT) run_bit=false;					//set run bit to false
    	else if (instr==DBG) debug=1;							//turn on debugger
    	else if (instr==NODBG) debug=0;							//turn off debugger
    	
    	else if (instr==ADDI||instr==ADDR) {					//check for which instruction
    		if (memory[PC+1]==r0) r0v=r0v+data;					//check which register to be modified
    		else if (memory[PC+1]==r1) r1v=r1v+data;			//and modify it
    		else if (memory[PC+1]==r2) r2v=r2v+data;
    		else if (memory[PC+1]==r3) r3v=r3v+data;
    		else if (memory[PC+1]==r4) r4v=r4v+data;
    	}
    	
    	else if (instr==ADDM) {									//check for which instruction
    		if (memory[PC+1]==r0) r0v=r0v+data;					//check which register to be modified
    		else if (memory[PC+1]==r1) r1v=r1v+data;			//and modify it
    		else if (memory[PC+1]==r2) r2v=r2v+data;
    		else if (memory[PC+1]==r3) r3v=r3v+data;
    		else if (memory[PC+1]==r4) r4v=r4v+data;
    	}
    	
    	else if (instr==LDI) {									//check for which instruction
    		if (memory[PC+1]==r0) r0v=data;						//check which register to be modified
    		else if (memory[PC+1]==r1) r1v=data;				//and modify it
    		else if (memory[PC+1]==r2) r2v=data;
    		else if (memory[PC+1]==r3) r3v=data;
    		else if (memory[PC+1]==4) r4v=data;
    	}
    	else if (instr==LDM) {
    		if (memory[PC+1]==r0) r0v=data;						//check which register to be modified
    		else if (memory[PC+1]==r1) r1v=data;				//and modify it
    		else if (memory[PC+1]==r2) r2v=data;
    		else if (memory[PC+1]==r3) r3v=data;
    		else if (memory[PC+1]==4) r4v=data;
    	}
    	else if (instr==ST) {									//check for which instruction
    		int store=memory[PC+1];								//modify data accordingly
    		memory[store]=data;
    	}
    	PC=PC+3;												//increment PC to next instruction
    }
    //--------------------------------------------------------------------
}
    
