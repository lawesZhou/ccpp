#include <stdio.h>

void * (* f)();

double * f1(int argc,double *args)
{
	int i = 0;
	double sum = 0;
	double *ans = &sum;

	for (i = 0; i < argc; i++){
		sum += args[i];	
	}
	return ans;
}

int *f2(int argc,double *args)
{
	int i = 0;
	int sum = 1;
	int *ans = &sum;

	for (i = 0; i < argc; i++){
		sum *= args[i];	
	}
	return ans;
}

void f3()
{
	printf("test f3\n");
}

void test_noargs()
{
}

void * test_void_void(void * a)
{
	int *b = (int *)a;
	printf("double a = %lf\n", *(double *)a);
	printf("int a = %d\n", *(int *)a);
	printf("char a = %d\n", *(char *)a);
	
	printf("b = %d\n", *b);

	return (void *)b;
}

int test_void(void * a)
{
	int *b = (int *)a;
	printf("double a = %lf\n", *(double *)a);
	printf("int a = %d\n", *(int *)a);
	printf("char a = %d\n", *(char *)a);
	
	printf("b = %d\n", *b);

	return *b;
}

int main()
{
	double d[3] = {4,2.5,1};

	double *b = d;
	int *b2 = (int *)d;
	int i;
	for (i = 0; i < 3; ++i)
		printf("%lf\t",b2[i]);

	f = (void *)f1;//只能是指针类型？
	printf("f1 = %lf\n", *(double *)(*f)(2, d));

	f = (void *)f2;
	printf("f2 = %d\n", *(int *)(*f)(2, d));

	f = (void *)f3;
	(void)(*f)();

	printf("b = %lf\n", *b);
	printf("test_void = %d\n", test_void(b));

	printf("*******************\n");
	printf("test void int = %d\n", *(int *)test_void_void(b2));
	printf("test void double = %lf\n", *(double *)test_void_void(b));

	return 0;
}
