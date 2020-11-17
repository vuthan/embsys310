#ifndef _STACK_
#define _STACK_

void StackInit(void);
int Push(int iData);
int Pop(int* p_iData);
int IsEmpty(void);
int IsFull(void);

#endif