////////////////////////////////////////////////////////////////////////////////
//
//  File name       : divAsm.s
//  Description     : Assembly language function for divide by 2
//
////////////////////////////////////////////////////////////////////////////////   

    EXTERN PrintString  // PrintString is defined outside this file.
    EXTERN myCstr       // myCstr defined outside this file.
    
    PUBLIC divBy2Asm    // Exports symbols to other modules
                        // Making divBy2Asm available to other modules.
                        
    SECTION .text:CODE:REORDER:NOROOT(2)
    THUMB               // Indicates THUMB code is used
                        // Subsequent instructions are assembled as THUMB instructions
    
////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   : divBy2Asm
//  Description     : Calls C code to print a string; 
//                    computes divide by 2 of its input argument
//  C Prototype     : int divBy2Asm(iNum)
//                  : Where iNum is theinput value to divide by 2
//  Parameters      : R0: integer iNum
//  Return value    : R0
//
////////////////////////////////////////////////////////////////////////////////  
  
divBy2Asm
    PUSH {R0,LR}        // save the input argument (iNum) and return address
    LDR R0,=myCstr      // load (global) address of address of string into R0
    LDR R0,[R0]         // load address of string into R0
    BL  PrintString     // call PrintString to print the string
    POP {R0,LR}         // Restore R0 (iNum) and LR
    MOV R1, R0          // R1 = R0
    MOV R2, #2          // move 2 into R2 divisor
    SDIV R0, R1, R2     // signed divide R0 = R1/R2
    BX LR               // return (with function result in R0)

    END

