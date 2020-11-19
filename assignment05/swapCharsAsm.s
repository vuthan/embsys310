////////////////////////////////////////////////////////////////////////////////
//
//  File name       : swapCharsAsm.s
//  Description     : Assembly language function to swap 2 character
//
////////////////////////////////////////////////////////////////////////////////   

    EXTERN PrintString  // PrintString is defined outside this file.
    EXTERN myCstr       // myCstr defined outside this file.
    
    PUBLIC swapCharsAsm    // Exports symbols to other modules
                           // Making swapCharsAsm available to other modules.
                        
    SECTION .text:CODE:REORDER:NOROOT(2)
    THUMB               // Indicates THUMB code is used
                        // Subsequent instructions are assembled as THUMB instructions
                        
////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : swapCharsAsm
//  Description     : Calls C code to swap character of 2 inputs
//  C Prototype     : int swapCharsAsm(char* p_cChar1, p_cChar2)
//                  : Where p_cChar1, p_cChar2 are the input holding the memory 
//                    address of 2 characters to be swapped
//  Parameters      : R0 - address of p_cChar1
//                    R1 - address of p_cChar2
//  Return value    : R0 - 0 if 2 character is identical, otherwise return 1
//
////////////////////////////////////////////////////////////////////////////////   

swapCharsAsm
    PUSH {R0-R1, LR}    // save inputs in R0, R1, and LR on stack. 
    LDR R0,=myCstr      // load (global) address of address of string into R0
    LDR R0,[R0]         // load address of string into R0
    BL  PrintString     // call PrintString to print the string
    POP {R0-R1,LR}      // Restore R0 (p_cChar1), R1 (p_cChar2) and LR
    LDRB R2, [R0]       // load character in R0 (p_cChar1) to R2
    LDRB R3, [R1]       // load character in R1 (p_cChar2) to R3
    CMP R2, R3          // is 2 character identical
    BEQ identical       // branch to identical: label if 2 characters identical
    STRB R3, [R0]       // swap character in R1 (p_cChar2) to R0 (p_cChar1)
    STRB R2, [R1]       // swap character in R0 (p_cChar1) to R1 (p_cChar2)
    MOV R0, #1          // move 1 to R0 for return because 2 char. not indentical
    BX  LR              // return
identical:
    MOV R0, #0          // move 0 to R0 for return because 2 char.  indentical
    BX  LR              // return
    END

