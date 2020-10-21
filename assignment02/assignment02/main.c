
#define _POINTER_ 1
//#define _UNSIGNED_ 1

#ifdef _POINTER_
    int counter = 0x0;
#endif

int main()
{
  
#ifdef _POINTER_
    int *p_int = (int *)0x20000000;
    ++(*p_int);
    ++(*p_int);
    ++(*p_int);
    counter ++;
#endif
  
#ifdef _UNSIGNED_
    unsigned int counter = 0x7FFFFFFF;
    counter ++;
    counter ++;
    counter ++;
    counter ++;
    counter ++;
    counter ++;
    counter ++;
#endif
    
    return 0;
}
