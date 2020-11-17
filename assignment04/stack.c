#include "stack.h"

#define STACK_SIZE 3

int iStackIndex;
int a_iStack[STACK_SIZE];

////////////////////////////////////////////////////////////////////////////////
//
// Description:  Stack Initialization funtion, to zero out stack array and reset
//               iStackIndex
//       Input:  None
//      Output:  None
//      Return:  None
//
////////////////////////////////////////////////////////////////////////////////
void StackInit(void)
{
    iStackIndex = -1;
    for (int i = 0; i < STACK_SIZE; i++)
    {
      a_iStack[i] = 0;
    }
}

////////////////////////////////////////////////////////////////////////////////
//
// Description:  Push funtion to increment iStackIndex then to Push item on stack 
//               array
//       Input:  iData - Data to Push on stack
//      Output:  None
//      Return:  1 - Success, 0 - fail
//
////////////////////////////////////////////////////////////////////////////////
int Push(int iData)
{
  if (IsFull())
    return 0;
  else
  {
    iStackIndex += 1;
    a_iStack[iStackIndex] = iData;
      
    return 1;
  }
}

////////////////////////////////////////////////////////////////////////////////
//
// Description:  Pop funtion to pop data stack array then decrement iStackIndex          
//       Input:  integer pointer p_iData to hold return data
//      Output:  *p_iData - a data pop off the stack array
//      Return:  1 - Success, 0 - fail
//
////////////////////////////////////////////////////////////////////////////////
int Pop(int* p_iData)
{
  
  if (IsEmpty() || (p_iData == 0))
    return 0;
  else
  {
    *p_iData = a_iStack[iStackIndex];
    iStackIndex -= 1;
    
    return 1;
  }
  
}

////////////////////////////////////////////////////////////////////////////////
//
// Description:  IsEmpty funtion to check if stack array is empty          
//       Input:  None
//      Output:  None
//      Return:  1 - if array is empty, 0 - not empty
//
////////////////////////////////////////////////////////////////////////////////
int IsEmpty(void)
{
  if (iStackIndex < 0)
    return 1;
  else
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
//
// Description:  IsFull funtion to check if stack array is full          
//       Input:  None
//      Output:  None
//      Return:  1 - if array is full, 0 - not full
//
////////////////////////////////////////////////////////////////////////////////
int IsFull(void)
{
  if (iStackIndex >=(STACK_SIZE -1))
    return 1;
  else
    return 0;
}