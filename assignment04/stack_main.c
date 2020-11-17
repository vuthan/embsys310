#include<assert.h>
#include"stack.h"

int main()
{
  int iTestData;
  int iResult1;
  int iResult2;
  
  // Test1: pop item from an empty stack  
  // Arrange: 
  iTestData = 10;
  iResult1 = 5;
  StackInit();
    
  // Act:
  iResult1 = Pop(&iTestData);
      
  // Assert:
  assert(0 == iResult1);
  assert(10 == iTestData);
  
  // Test2: Successfully push then pop an item off the stack
  // Arrange:
  iTestData = 10;
  iResult1 = 5;
  iResult2 = 5;
  StackInit();
  
  //Act
  iResult1 = Push(20);
  iResult2 = Pop(&iTestData);
  
  // Assert:
  assert(1 == iResult1);
  assert(1 == iResult2);
  assert(20 == iTestData);
  
  // Test3: Push data fill up stack then pop all data off the stack
  // Arrange:
  iTestData = 20;
  StackInit();
  
  // Act:
  Push(5);
  Push(10);
  Push(15);
    
  // Assert:
  assert(1 == Pop(&iTestData));
  assert(15 == iTestData);
 
  assert(1 == Pop(&iTestData));
  assert(10 == iTestData);
  
  assert(1 == Pop(&iTestData));
  assert(5 == iTestData);
  
  // Test4: Push data fill up stack then push 1 more data this push should fail,  
  // then pop all data off the stack
  iTestData = 25;
  StackInit();
  
  // Act:
  Push(5);
  Push(10);
  Push(15);
    
  // Assert:
  assert(0 == Push(20));
  
  assert(1 == Pop(&iTestData));
  assert(15 == iTestData);
 
  assert(1 == Pop(&iTestData));
  assert(10 == iTestData);
  
  assert(1 == Pop(&iTestData));
  assert(5 == iTestData);
  
  // Test5:  Push 2 items, Pop 3 times.  Last Pop should fail
  iTestData = 20;
  StackInit();
  
  // Act:
  Push(5);
  Push(10);
    
  // Assert:
  assert(1 == Pop(&iTestData));
  assert(10 == iTestData);
 
  assert(1 == Pop(&iTestData));
  assert(5 == iTestData);
  
  assert(0 == Pop(&iTestData));
  
  return 0;
}
