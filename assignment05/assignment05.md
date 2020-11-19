1. Create a function in “C” that allows swapping of two pointers.
 * a. Explain what the “main” function does in order to setup the input arguments prior to
      calling the swap_pointer() function?
      In main() function moves 2 input arguments into R0, R1 before calling (or **BL** to) vSwapPointer function.  2 inputs are the 2 memory address holding the 2 memory address (pointers) those contain two integer numbers; iNum1, iNum2.
 * b. What are the values in R0 & R1 when swap_pointer() is called? The values in **R0 & R1** are 2 memory 
      addresses holding the 2 memory addresses (pointers) those contain 2 integer numbers; iNum1, iNum2
 * c. Share a screen shot of the local variables inside of “main” after the function
 
      **Swap Pointers Screen Shot**
      
     ![Image Swap Pointers](https://github.com/vuthan/embsys310/blob/master/assignment05/swappointers.png)

2. Create a new file divAsm.s and add the file to the same HelloWorld project
 * f. Run your program on the board and capture a snapshot image of the output from
      TeraTerm showing the result of the divAsm.
      
      **Divide by 2 in Assembly Screen Shot**
      
      ![Divide by 2](https://github.com/vuthan/embsys310/blob/master/assignment05/divby2.png)

3. Implement a swap function in assembly and call it “swapCharsAsm”:
 * a. It takes as input two variables of char data type each and swaps the two chars.
 * b. Add a comment for every statement in your assembly function code.
 * c. Bonus: Return 0 if the two chars are identical; otherwise, return 1.
 
      **Swap Characters Screen Shot**
      
      ![Swap Characters](https://github.com/vuthan/embsys310/blob/master/assignment05/swapchars.png)

4. Bonus: Implement the swap_pointer() function from #1 above in assembly and call it
   swapPointersAsm().
 * a. Add a comment for every statement in your assembly function code.
 * b. Invoke swapPointersAsm() from your main function main.c
 * c. Run your program on the board and capture a snapshot image of the output from
      TeraTerm showing the result of the swapPointersAsm() subroutine.
      
      **Swap Pointers in Assembly Screen Shoot**
      
      ![Swap Characters](https://github.com/vuthan/embsys310/blob/master/assignment05/swappointersasm.png)
      
