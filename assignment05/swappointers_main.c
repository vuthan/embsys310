
////////////////////////////////////////////////////////////////////////////////
//
// Description:  vSwapPointers function to swap 2 pointers
//               
//       Input:  p_iVarAPtr - pointer point to a pointer of an integer 
//               p_iVarBPtr - pointer point to a pointer of an integer
//      Output:  p_iVarAPtr's data will be swapped with p_iVarBPtr's data
//               p_iVarBPtr's data will be swapped with p_iVarAPtr's data
//      Return:  None
//
////////////////////////////////////////////////////////////////////////////////
void vSwapPointers(int** p_iVarAPtr, int** p_iVarBPtr )
{
  int* p_Temp;
  
  p_Temp = *p_iVarAPtr;
  *p_iVarAPtr = *p_iVarBPtr;
  *p_iVarBPtr = p_Temp;
  
}
int main()
{
  int iNum1;
  int iNum2;
  int* p_iNum1;
  int* p_iNum2;
  
  iNum1 = 100;
  iNum2 = 200;
  
  p_iNum1 = &iNum1;
  p_iNum2 = &iNum2;
  
  vSwapPointers(&p_iNum1, &p_iNum2);
  
  return 0;
}
