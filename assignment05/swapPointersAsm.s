////////////////////////////////////////////////////////////////////////////////
//
//  File name       : swapPointersAsm.s
//  Description     : Assembly language function to swap 2 pointers
//
////////////////////////////////////////////////////////////////////////////////   

    EXTERN PrintString        // PrintString is defined outside this file.
    EXTERN myCstr             // myCstr defined outside this file.
    
    PUBLIC swapPointersAsm    // Exports symbols to other modules
                              // Making swapCharsAsm available to other modules.
                        
    SECTION .text:CODE:REORDER:NOROOT(2)
    THUMB               // Indicates THUMB code is used
                        // Subsequent instructions are assembled as THUMB instructions
                        
////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : swapPointersAsm
//  Description     : Calls C code to swap 2 pointers
//  C Prototype     : int swapPointersAsm(int** p_piNum1, p_piNum2)
//                  : Where p_piNum1, p_piNum2 are the inputs holding the memory 
//                    address of 2 integer pointers to be swapped
//  Parameters      : R0 - address of p_piNum1
//                    R1 - address of p_piNum2
//  Return value    : None
//
////////////////////////////////////////////////////////////////////////////////   

swapPointersAsm
    PUSH {R0-R1, LR}    // save inputs in R0, R1, and LR on stack.
    LDR  R0, =myCstr    // load (global) address of address of string into R0
    LDR  R0, [R0]       // load address of string into R0
    BL   PrintString    // call PrintString to print the string
    POP  {R0-R1, LR}    // Restore R0 (p_piNum1), R1 (p_piNum2) and LR
    LDR  R2, [R0]       // load content (p_piNum1) of memory address in R0 to R2
    LDR  R3, [R1]       // load content (p_piNum2) of memory address in R1  to R3
    STR  R2, [R1]       // store content (p_piNum1) in R2 to memory location in R1
    STR  R3, [R0]       // store content (p_piNum2) in R3 to memory location in R0
    BX   LR             // return
    END
    
    