// GPIO Port Address Base
#define GPIOA_BASE 0x48000000   // Base Address for GPIOA registers
#define GPIOB_BASE 0x48000400   // Base Address for GPIOB registers
#define GPIOC_BASE 0x48000800   // Base Address for GPIOC registers
#define GPIOD_BASE 0x48000C00   // Base Address for GPIOD registers
#define GPIOE_BASE 0x48001000   // Base Address for GPIOE registers
#define GPIOF_BASE 0x48001400   // Base Address for GPIOF registers
#define GPIOG_BASE 0x48001800   // Base Address for GPIOG registers
#define GPIOH_BASE 0x48001C00   // Base Address for GPIOH registers

// GPIO Clock 
#define RCC_BASE (0x40021000)             // Base Address for RCC registers
#define RCC_AHB2ENR_OFFSET (0x4C)         // set bit[0] to 1 to enable GPIOA clock
#define GPIO_PORTA_CLOCK (0x1 << 0)       // clock bit portA
#define GPIO_PORTB_CLOCK (0x1 << 1)       // clock bit portB
#define GPIO_PORTC_CLOCK (0x1 << 2)       // clock bit portC
#define GPIO_PORTD_CLOCK (0x1 << 3)       // clock bit portD
#define GPIO_PORTE_CLOCK (0x1 << 4)       // clock bit portE
#define GPIO_PORTF_CLOCK (0x1 << 5)       // clock bit portF
#define GPIO_PORTG_CLOCK (0x1 << 6)       // clock bit portG
#define GPIO_PORTH_CLOCK (0x1 << 7)       // clock bit portH

// GPIO set pin mode register
#define GPIOx_MODER_OFFSET 0x00 // To enable port mode (IN, OUT, AF..)
#define GPIO_PIN0 0
#define GPIO_PIN1 1
#define GPIO_PIN2 2
#define GPIO_PIN3 3
#define GPIO_PIN4 4
#define GPIO_PIN5 5
#define GPIO_PIN6 6
#define GPIO_PIN7 7
#define GPIO_PIN8 8
#define GPIO_PIN9 9
#define GPIO_PIN10 10
#define GPIO_PIN11 11
#define GPIO_PIN12 12
#define GPIO_PIN13 13
#define GPIO_PIN14 14
#define GPIO_PIN15 15

// GPIO Pin Modes
#define GPIO_INPUT_MODE 0x0    // Input mode
#define GPIO_OUTPUT_MODE 0x1   // Output mode
#define GPIO_ALT_MODE 0x2      // Alternate function mode
#define GPIO_ANALOG_MODE 0x3   // Analog mode (reset state)

// Output Data Register
#define GPIOx_ODR_OFFSET 0x14   // Port output data register for port A..H
#define TURN_ON_LED1 0x20       // Set bit[5] to 1, use bitwise | operation to turn on
#define TURN_OFF_LED1 
// Set bit[5] to 1 --> 0x20; // Turn LED1 ON
// Set bit[5] to 0 --> 0x0; // Turn LED1 OFF

// GPIO toggle mode
#define TOGGLE_OFF 0x0
#define TOGGLE_ON  0x1

// Bit Banding Section
// SRAM 0x22000000-0x23FFFFFF bit-banding alias for 0x20000000-0x200FFFFF SRAM bit-band region
// Peripheral 0x42000000-0x43FFFFFF bit-band alias for 0x40000000-0x400FFFFF Peripheral bit-band region
#define SRAM_BB_ALIAS_BASE 0x22000000           // SRAM bit-banding alias base
#define PERIPHERAL_BB_ALIAS_BASE 0x42000000     // Peripheral bit-banding alias base
#define RCC_BASE_BB_ALIAS_OFFSET 0x00021000     // OFFSET RCC Base bit-banding alias
#define AHB2ENR_BB_ALIASOFFSET   0x4C           // OFFSET AHB2ENR bit-banding alias

#define BIT_0 0
#define BIT_1 1
#define BIT_2 2
#define BIT_3 3
#define BIT_4 4
#define BIT_5 5
#define BIT_6 6
#define BIT_7 7
#define BIT_8 8
#define BIT_9 9
#define BIT_10 10
#define BIT_11 11
#define BIT_12 12
#define BIT_13 13
#define BIT_14 14
#define BIT_15 15
#define BIT_16 16
#define BIT_17 17
#define BIT_18 1
#define BIT_19 19
#define BIT_20 20
#define BIT_21 21
#define BIT_22 22
#define BIT_23 23
#define BIT_24 24
#define BIT_25 25
#define BIT_26 26
#define BIT_27 27
#define BIT_28 28
#define BIT_29 29
#define BIT_30 30
#define BIT_31 31

// Morse Code Section
#define CODE_DOT   0x1
#define CODE_DASH  0x3
#define CODE_SPACE 0x5
#define CODE_END   0x7
#define DOT_DURATION 100000

////////////////////////////////////////////////////////////////////////////////
//
// Description:  Delay function, like sleep
//       Input:  uiCount - while loop increment to uiCount
//      Output:  None
//      Return:  None
//
////////////////////////////////////////////////////////////////////////////////
void vdDelay(unsigned int uiCount)
{
  unsigned int uiDelayCount = 0;
  
  while(uiDelayCount < uiCount)
  {
    uiDelayCount++;
  } 
}


////////////////////////////////////////////////////////////////////////////////
//
// Description:  Turn on GPIOx port clock
//       Input:  ulGPIOPort - GPIO Port that has its clock to be enable
//      Output:  None
//      Return:  None
//
////////////////////////////////////////////////////////////////////////////////
void vdEnableGPIOClock(unsigned int ulGPIOPort)
{
  unsigned int* p_uiRCCReg;
  p_uiRCCReg = (unsigned int*)(RCC_BASE | RCC_AHB2ENR_OFFSET);
  // enable clock of uiGPIOPort
  *p_uiRCCReg = (*p_uiRCCReg) | ulGPIOPort; 
}

////////////////////////////////////////////////////////////////////////////////
//
// Description:  Turn on GPIOx port clock using Bit-Banding
//       Input:  ulGPIOPortPin - GPIO Port Pin that has its clock to be enable
//      Output:  None
//      Return:  None
//
////////////////////////////////////////////////////////////////////////////////
void vdBBEnableGPIOClock(unsigned int ulGPIOPortPin)
{
  unsigned int* p_uiRCCAddr;
  p_uiRCCAddr = (unsigned int*)((PERIPHERAL_BB_ALIAS_BASE) | 
                                (32*(RCC_BASE_BB_ALIAS_OFFSET | AHB2ENR_BB_ALIASOFFSET)) |
                                 4*ulGPIOPortPin);
  // set clock of ulGPIOPortPin
  *p_uiRCCAddr = 1; 
}

////////////////////////////////////////////////////////////////////////////////
//
// Description:  Set GPIO pin Mode for use.  Mode can be either input mode
//               output mode, alternate funtion mode or Analog mode (reset state)
//       Input:  p_uiGPIOPortAddr - base address GPIO port that GPIO pin is in
//               uiGPIOPin - GPIO Pin #
//               uiGPIOMode - mode that will be set of specified GPIO Pin
//      Output:  None
//      Return:  None
//
////////////////////////////////////////////////////////////////////////////////
void vdSetGPIOMode(unsigned int* p_uiGPIOPortAddr, unsigned int uiGPIOPin, unsigned int uiGPIOMode)
{
  switch (uiGPIOMode)
  {
    case GPIO_INPUT_MODE:
        // set bit[2*uiGPIOPin+1]bit[2*uiGPIOPin] to 00
        *p_uiGPIOPortAddr = (*p_uiGPIOPortAddr) & (~(0x3 << (2*uiGPIOPin)));
      break;

    case GPIO_OUTPUT_MODE:
        // set bit[2*uiGPIOPin+1]bit[2*uiGPIOPin] to 01
        *p_uiGPIOPortAddr = (*p_uiGPIOPortAddr) | (1 << (2*uiGPIOPin));
        *p_uiGPIOPortAddr = (*p_uiGPIOPortAddr) & (~(1 << (2*uiGPIOPin+1)));
      break;

    case GPIO_ALT_MODE:
      // set bit[2*uiGPIOPin+1]bit[2*uiGPIOPin] to 10
        *p_uiGPIOPortAddr = (*p_uiGPIOPortAddr) | (1 << (2*uiGPIOPin+1));
        *p_uiGPIOPortAddr = (*p_uiGPIOPortAddr) & (~(1 << (2*uiGPIOPin)));
      break;
    case GPIO_ANALOG_MODE:
      // set bit[2*uiGPIOPin+1]bit[2*uiGPIOPin] to 11
        *p_uiGPIOPortAddr = (*p_uiGPIOPortAddr) | (0x3 << (2*uiGPIOPin));
      break;
  default:
    break;

  }

}


////////////////////////////////////////////////////////////////////////////////
//
// Description:  Toggle GPIO pin ON/OFF with XOR bitwise
//       Input:  p_uiODRAddr - ODR GPIO Address
//               uiGPIOPin - GPIO Pin that will be toggled
//      Output:  None
//      Return:  None
//
////////////////////////////////////////////////////////////////////////////////
void vdXORToggle(unsigned int* p_uiODRAddr, unsigned int uiGPIOPin)
{
  unsigned int uiPinMode;
  unsigned int* p_uiODR;
  
  p_uiODR = p_uiODRAddr;
  uiPinMode = 1 << uiGPIOPin;
  
  *p_uiODR = (*p_uiODR) ^ uiPinMode;
  
}


////////////////////////////////////////////////////////////////////////////////
//
// Description:  Toggle GPIO pin with specified state ON or OFF
//       Input:  p_uiODRAddr - ODR GPIO Address
//               uiGPIOPin - GPIO Pin that will be toggled
//               uiToggleMode - Toggle state ON or OFF
//      Output:  None
//      Return:  None
//
////////////////////////////////////////////////////////////////////////////////
void vdGPIOToggle(unsigned int* p_uiODRAddr, unsigned int uiGPIOPin, unsigned int uiToggleMode)
{
  unsigned int uiPinMode;
  unsigned int* p_uiODR;
  
  p_uiODR = p_uiODRAddr;
  uiPinMode = 1 << uiGPIOPin;
  
  // toggle specified GPIO pin ON
  if (uiToggleMode == TOGGLE_ON)
    *p_uiODR = (*p_uiODR) | uiPinMode;
  else
    *p_uiODR = (*p_uiODR) & (~uiPinMode);
}

////////////////////////////////////////////////////////////////////////////////
//
// Description:  Program starting point.  It will initialize and toggle PA5
//               GPIO Pin to turn ON/OFF LED1, toggle LED1 with XOR bitwise, and
//               play Morse Codes "quang vu" (Author's first name) out on LED1 
//       Input:  None               
//      Output:  None
//      Return:  0
//
////////////////////////////////////////////////////////////////////////////////
int main()
{
  int iCount = 0;
  
  // enable GPIO portA clock
  // vdEnableGPIOClock(GPIO_PORTA_CLOCK);
   
  // Enable GPIO PortA Clock using bit-banding @ bit0
  vdBBEnableGPIOClock(BIT_0);
  // set PA5 to output mode
  vdSetGPIOMode((unsigned int*)(GPIOA_BASE | GPIOx_MODER_OFFSET), GPIO_PIN5, GPIO_OUTPUT_MODE);

  //turn on and off LED1
  while (iCount < 10) 
  {
    
    vdGPIOToggle((unsigned int*)(GPIOA_BASE | GPIOx_ODR_OFFSET), GPIO_PIN5, TOGGLE_ON);
    vdDelay(1000000);
    vdGPIOToggle((unsigned int*)(GPIOA_BASE | GPIOx_ODR_OFFSET), GPIO_PIN5, TOGGLE_OFF);
    vdDelay(1000000);
    iCount++;
  }
  
  // toggle on/off with XOR
  iCount = 0;
  while (iCount < 10)
  {
    vdXORToggle((unsigned int*)(GPIOA_BASE | GPIOx_ODR_OFFSET), GPIO_PIN5);     
    vdDelay(1000000);
    iCount++;
  }

  return 0;
}

