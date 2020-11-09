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

// Morse Code Section
#define CODE_DOT   0x1
#define CODE_DASH  0x3
#define CODE_SPACE 0x5
#define CODE_END   0x7
#define DOT_DURATION 100000


// Morse Code section
typedef struct MorseCode* MorseCodePtr;
typedef struct MorseCode 
{
    char cLetter;
    int iCodes[8];      // dots = 1, dash = 3, space = 5, end = 7
} MorseCode;

// Lower case and upper case letter have same code.
// There is also different solution to handle this.
MorseCode a_AlphabetMorseCodeTable[] = {
  {'a', {1,5,3,7}},
  {'A', {1,5,3,7}},
  {'b', {3,5,1,5,1,5,1,7}},
  {'B', {3,5,1,5,1,5,1,7}},
  {'c', {3,5,1,5,3,5,1,7}},
  {'C', {3,5,1,5,3,5,1,7}},
  {'d', {3,5,1,5,1,7}},
  {'D', {3,5,1,5,1,7}},
  {'e', {1,7}},
  {'E', {1,7}},
  {'f', {1,5,1,5,3,5,1,7}},
  {'F', {1,5,1,5,3,5,1,7}},
  {'g', {3,5,3,5,1,7}},
  {'G', {3,5,3,5,1,7}},
  {'h', {1,5,1,5,1,5,1,7}},
  {'H', {1,5,1,5,1,5,1,7}},
  {'i', {1,5,1,7}},
  {'I', {1,5,1,7}},
  {'j', {1,5,3,5,3,5,3,7}},
  {'J', {1,5,3,5,3,5,3,7}},
  {'k', {3,5,1,5,3,7}},
  {'K', {3,5,1,5,3,7}},
  {'l', {1,5,3,5,1,5,1,7}},
  {'L', {1,5,3,5,1,5,1,7}},
  {'m', {3,5,3,7}},
  {'M', {3,5,3,7}},
  {'n', {3,5,1,7}},
  {'N', {3,5,1,7}},
  {'o', {3,5,3,5,3,7}},
  {'O', {3,5,3,5,3,7}},
  {'p', {1,5,3,5,3,5,1,7}},
  {'P', {1,5,3,5,3,5,1,7}},
  {'q', {3,5,3,5,1,5,3,7}},
  {'Q', {3,5,3,5,1,5,3,7}},
  {'r', {1,5,3,5,1,7}},
  {'R', {1,5,3,5,1,7}},
  {'s', {1,5,1,5,1,7}},
  {'S', {1,5,1,5,1,7}},
  {'t', {3,7}},
  {'T', {3,7}},
  {'u', {1,5,1,5,3,7}},
  {'U', {1,5,1,5,3,7}},
  {'v', {1,5,1,5,1,5,3,7}},
  {'V', {1,5,1,5,1,5,3,7}},
  {'w', {1,5,3,5,3,7}},
  {'W', {1,5,3,5,3,7}},
  {'x', {3,5,1,5,1,5,3,7}},
  {'X', {3,5,1,5,1,5,3,7}},
  {'y', {3,5,1,5,3,5,3,7}},
  {'Y', {3,5,1,5,3,5,3,7}},
  {'z', {3,5,3,5,1,5,1,7}},
  {'Z', {3,5,3,5,1,5,1,7}},
};

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

// Morse Code functions

////////////////////////////////////////////////////////////////////////////////
//
// Description:  Play Dot Code, Dot Duration last 1 unit (DOT_DURATION)
//       Input:  None
//      Output:  None
//      Return:  None
//
////////////////////////////////////////////////////////////////////////////////
void vdDot()
{
  vdGPIOToggle((unsigned int*)(GPIOA_BASE | GPIOx_ODR_OFFSET), GPIO_PIN5, TOGGLE_ON);
  vdDelay(DOT_DURATION);
  vdGPIOToggle((unsigned int*)(GPIOA_BASE | GPIOx_ODR_OFFSET), GPIO_PIN5, TOGGLE_OFF);

}


////////////////////////////////////////////////////////////////////////////////
//
// Description:  Play Space Code, Space Duration last 1 unit (DOT_DURATION)
//       Input:  None
//      Output:  None
//      Return:  None
//
////////////////////////////////////////////////////////////////////////////////
void vdSpace()
{
  vdDelay(DOT_DURATION);
}

////////////////////////////////////////////////////////////////////////////////
//
// Description:  Play Letter Space Code, Letter Space Duration last 
//               3 unit (DOT_DURATION)
//       Input:  None
//      Output:  None
//      Return:  None
//
////////////////////////////////////////////////////////////////////////////////
void vdLetterSpace()
{
  vdDelay(3*DOT_DURATION);
}

////////////////////////////////////////////////////////////////////////////////
//
// Description:  Play Word Space Code, Word Space Duration last 
//               7 unit (DOT_DURATION)
//       Input:  None
//      Output:  None
//      Return:  None
//
////////////////////////////////////////////////////////////////////////////////
void vdWordSpace()
{
  vdDelay(7*DOT_DURATION);
}




////////////////////////////////////////////////////////////////////////////////
//
// Description:  Play Dash Code, Dash Code Duration last 3 unit (DOT_DURATION) 
//       Input:  None
//      Output:  None
//      Return:  None
//
////////////////////////////////////////////////////////////////////////////////
void vdDash()
{

  vdGPIOToggle((unsigned int*)(GPIOA_BASE | GPIOx_ODR_OFFSET), GPIO_PIN5, TOGGLE_ON);
  vdDelay(3*DOT_DURATION);
  vdGPIOToggle((unsigned int*)(GPIOA_BASE | GPIOx_ODR_OFFSET), GPIO_PIN5, TOGGLE_OFF);
}


////////////////////////////////////////////////////////////////////////////////
//
// Description:  Play 1 word Morse Code signals 
//       Input:  p_cString - string contains 1 word that will be played in 
//               Morse Codes
//      Output:  None
//      Return:  None
//
////////////////////////////////////////////////////////////////////////////////
void vdMorseCodePlayWord(char* p_cString)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int iCode;
    
    while (p_cString[i] != '\0')
    { 
      while (p_cString[i] != a_AlphabetMorseCodeTable[j].cLetter && 
             j < sizeof(a_AlphabetMorseCodeTable)/sizeof(MorseCode))
      {
        j++;
      }
      k = 0;
      while (a_AlphabetMorseCodeTable[j].iCodes[k] != CODE_END)
      {
        iCode = a_AlphabetMorseCodeTable[j].iCodes[k];
        switch (iCode)
        {
            case CODE_DOT:
                vdDot();
              break;
            case CODE_DASH:
                vdDash();
              break;
            case CODE_SPACE:
                vdSpace();
              break;
            default:
              break;
        }
        k++;      
      }
      vdLetterSpace();
      i++;
      j = 0;
    }
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
  vdEnableGPIOClock(GPIO_PORTA_CLOCK);
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

/*
  // Play Morse Code first name
  vdMorseCodePlayWord("quang");
  vdWordSpace();
  vdMorseCodePlayWord("vu");
*/
  return 0;
}

