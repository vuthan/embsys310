/*******************************************************************************
File name       : rcc_ctrl.s
Description     : Assembly language function for controlling the user LED
*******************************************************************************/   

    PUBLIC enable_rcc        // Exports symbols to other modules

// Code is split into logical sections using the SECTION directive.
// Source: http://ftp.iar.se/WWWfiles/arm/webic/doc/EWARM_AssemblerReference.ENU.pdf
// SECTION  section  :type [:flag] [(align)]
//      The data section is used for declaring initialized data or constants. This data does not change at runtime
//      The bss section is used for declaring variables. The syntax for declaring bss section is -
//      The text section is used for keeping the actual code.

// CODE: Interprets subsequent instructions as Arm or Thumb instructions, 
// depending on the setting of related assembler options.

// NOREORDER (the default mode) starts a new fragment in the section
// with the given name, or a new section if no such section exists.
// REORDER starts a new section with the given name.

// NOROOT means that the section fragment is discarded by the linker if
// no symbols in this section fragment are referred to. Normally, all
// section fragments except startup code and interrupt vectors should
// set this flag.

// The (2) is for the (align)
// The power of two to which the address should be aligned.
// The permitted range is 0 to 8. 
// Code aligned at 4 Bytes.

    SECTION .text:CODE:REORDER:NOROOT(2)
    
    THUMB               // Indicates THUMB code is used
                        // Subsequent instructions are assembled as THUMB instructions
    
/*******************************************************************************
Function Name   : enable_rcc
Description     : - Uses Bit-Band registers at base 0x4200.0000
                    to set GPIOA Output Data Register.
                  - Calls another assembly function delay to insert
                    delay loop

C Prototype     : void enable_rcc(uint32_t port)
                : Where port indicates wich port to enable the clock for
Parameters      : R0: uint32_t port

Return value    : None
*******************************************************************************/  

// Bitband address calculation formula
// (0x42000000+(0x2104C *32) + (1*4))) = 0x1;

BB_PERIPHERAL_BASE  EQU  0x42000000
BB_RCC_OFFSET       EQU  0x2104C

enable_rcc
    MOV  R2, #4
    MUL  R1, R0, R2                     // input port * 4
    LDR  R2, =BB_PERIPHERAL_BASE        // load bb alias of peripheral base 
    LDR  R3, =BB_RCC_OFFSET             // load RCC offset address 
    LSL  R3, R3, #5                     // multiply by 32, formula above
    ORR  R3, R3, R1                     // add (port * 4) + (offset * 32)
    ORR  R2, R2, R3                     // add (base + (offset*32)  + (port*4))
    MOV  R0, #1                         // move 1 to R0
    STR  R0, [R2]                       // (base + (offset*32)  + (port*4)) = 0x1
    BX   LR                             // return    
    
    END
