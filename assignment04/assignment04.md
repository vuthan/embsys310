  1. Follow the same steps as we did in the class to blink LED1 (PA5) at a visible rate using the bitband 
     region to enable the clock to Port A, then answer the following:
* a. What instructions does the compiler produce in assembly for “writing” to the GPIO bit when using bit-band
     address?
     
     **STR  R2, [R1]**
* b. What were the instructions produced when writing to the GPIOx_ODR without using bitbanding?
     
     **LDR   R5, [R4]**
     
     **ORRS  R5, R5, R3**
     
     **STR   R5, [R4]**

  2. Create a function “func1” with multiple arguments (5 arguments for example) and call “func1”
     from within another function “func2”. Trace thru the assembler and note:
* a. How does the calling function “func2” pass the values to the called function “func1”?
     func2 moves 5th value to **R0** then store 5th value in R0 on stack.  then 1st to 4th values will be 
     stored in **R0-R3** that is how func2 passes these 5 values to func1.  **R0** is used as scratch register
     to store 5th, 6th, 7th ... values on the stack
* b. What extra code did the compiler generate before calling the function “func1” with the
     multiple arguments?
     Compiler generated **STR**(s) instruction(s) to store values on the stack if more than 4 values are passed
     to function func1.
* c. What extra code did the compiler generate inside the called function “funct1” with the
     multiple list of arguments?
     Compiler generated **LDR**(s) instruction(s) to load values from the stack if more than 4 values were passed to func1
     to a called function.
* d. Any other observations? For **LDR**(s) instructions, compiler has to calculate correct offset and add 
     to current *SP* to get to where the passed in values to func1 are stored on stack, because the stack grow to lower address.

* 4. Bonus: Using the power of pointers and type casting, create a function that can determine if a
     computer is big-endian or little-endian. Test your function in the simulator and modify the
     Project Options (as shown in the figure below) against:
     a. Cortex M4 (Little endian option)
     b. Cortex M4 (Big Endian option)

    function to determine Little or Big Endian: 
    
    int BigOrLittleEndian(void)
    {
    
        unsigned int iNumber = 0x22334455;
        char* pChar = (char*)(&iNumber);
        
        char cResult;
        
        cResult = *pChar;
        
        if (cResult == 0x55)
        {
            printf("Computer is Little Endian \n");
            return 1;
        }
        else if (cResult == 0x22)
        {
            printf("Computer is Big Endian \n");
            return 2;
        }
        else
            return 0;
    }
