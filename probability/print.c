#include "print.h"

#define FM 	"%d"
#define Elem_type int
#define printArray2 print_intArray 

#include "print.ic"

#undef Elem_type
#undef FM
#undef printArray2

#define FM	"%lf"
#define Elem_type double
#define printArray2 print_doubleArray 

#include "print.ic"
