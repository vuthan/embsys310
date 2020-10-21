**Observe and Answers:**
* 1. Inject 0x7FFFFFFF for the “counter” value in the variable window, then step thru the program
  only once to increment “counter”
   * a) What is the value of the “counter” from the “Locals” window? **-2147483648**
   * b) What is the value of the “counter” in the “Registers” window? **0x80000000**
   * c) N and V flags in the APSR register both are set. Integer variable 'counter' set to 0x7FFFFFFF. 
        When 'counter' increments 1, counter equals 0x80000000.  bit-31th of counter or sign bit are set.
        'counter' is two's complement signed integer.  Variable 'counter' becomes negative number.
        N flag (negative flag) and V flag (overflow flag) in the APSR register are set.

* 2. If your write all Fs (0XFFFFFFFF) in the Register value for “counter” then step thru the program
  once to increment “counter”
   * a) What happens to the value of “counter” in the “Locals” window?
        'counter' equals **0**
   * b) The N flag and V flag are cleared, because when counter equals 0xFFFFFFFF then incrementing 1, 
        all 32 bits in 'counter' are **0**; bit 31th (signed bit) equal zero.  

* 3. Change the “counter” variable type in your code to “unsigned int”. Inject the values
    “**0x7FFFFFFF**” then step thru the program to increment the “counter” once:
   * a) What is the value of “counter” in the “Locals” window after incrementing for each value? **2147483648**  
   * b) The N and V flags are set in the APSR register, because bit 31th is set; signed bit equals 1.

* 4. Change the “counter” variable type in your code to “unsigned”. Inject the values “0xFFFFFFFF”
  then step thru the program to increment the “counter” once:
   * a) What is the value of “counter” in the “Locals” window after incrementing for each value? **0**
   * b) Both N and V flags are cleared in the APSR register, because all 32 bits are zero; signed bit
        (bit 31th) is **0**.   

* 5. Move the “counter’ variable outside of main (at the top of the file):
   * a) What is the scope of the variable “counter”? "counter" variable scope is a **global** scope
   * b) Is it still visible in the “Locals” view? **NO**
   * c) In which window view can we track “counter” now? Watch window, where you can add "counter" to watch
   * d) What is the address of the “counter” variable in memory? **0x20000000**

* 6. Change the source code to the following, then run the program in the simulator:
   * a) What is the value of “counter” at the end of the program? **counter = 4**
   * b) Explain why the counter value has changed? 
        'counter' value changed because variable "counter" is stored at memory address 0x20000000.  p_int pointer 
        assigns to an address 0x2000000, which is same memory address of variable "counter".  when ++(*p_int) execute,
        this instruction will change the value in memory address p_int points to, which is same as counter variable's
        memory address. That is why we see "counter" variable value changed.
        
* 7. Change the setting of IAR to run the same program on the **evaluation board**:
   * a) What is the address where “counter” is stored? **0x20000000**
   * b) Is the “counter” variable stored in RAM or ROM? **RAM**
   * c) What is the value of “counter” at the end of the program? **counter = 4**
