       An interpreter implemented in Java.  The interpreter receives & executes the following instructions:
       
	      ADDI	r4	12	<-- add value of 12 to contents of register 4
	      ADDM	r1	92	<-- add value in memory location 92 to contents of register 1
	      ADDR	r1	r3	<-- add value in register 3 to the value in register 1 (with the result in r1)
	      CLR	r0		<-- set value in register 0 to 0
	      DBG			<-- turn on debug flag
	      HALT			<-- halt the processor
	      NODBG			<-- turn off debug flag
	      LDI	r4	7	<-- load register 4 with the value 7
	      LDM	r3	6	<-- load register 3 with the value in memory location 6
	      ST	9	r3	<-- store the value in register 3 in memory location 9
	      
	      
The test files demonstrate the use of all the instructions.
