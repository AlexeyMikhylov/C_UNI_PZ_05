#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	run();
}

int run(void) 
{
	int ex;

	printf("\n\nstart\n0 - exit\ninput ex num: ");
	scanf_s("%d", &ex);

	switch (ex)
	{
	case 0:
		exit(1);
	case 10:
		example1(); run();
	case 20:
		example2(); run();
	case 30:
		example3(); run();
	case 40:
		example4(); run();
	case 50:
		example5(); run();
	case 1:
		ex1(); run();
	case 2:
		ex2(); run();
	case 3:
		ex3(); run();
	case 4:
		ex4(); run();
	case 5:
		ex5(); run();
	case 51:
		ex5_1(); run();
	case 52:
		ex5_2(); run();
	case 53:
		ex5_3(); run();
	case 54:
		ex5_4(); run();
	default:
		printf("incorrect nuber"); run();
	}

}

int example1(void)
{
	int m = 10, n, o;
	int* pm = &m;

	printf("\n addres 'm' - %p", pm);
	printf("\n data 'm' - %i", *pm);

	printf("\n address 'm' %p", &m);
	printf("\n address 'n' %p", &n);
	printf("\n address 'o' %p", &o);

	printf("\n %d", *pm);
}

int example2(void)
{
	int* pm;
	int m = 29;

	printf("\n address of m - %p", &m);
	printf("\n m = %d", m);

	pm = &m;

	printf("\n address of pm - %p", pm);

	m = 34;

	printf("\n address of pm - %p", pm);
	printf("\n data of pm - %i", *pm);

	*pm = 7;

	printf("\n address of m - %p", &m);
	printf("\n m = %d", m);
}

int example3(void)
{
	int M = 300;
	float FX = 300.600006;
	char cht = 'Z';

	int* ptr;
	float* fptr;

	printf("\naddresses:");
	printf("\n %p", &M);
	printf("\n %p", &FX);
	printf("\n %p", &cht);

	printf("\ndata:");
	printf("\n %d", *&M);
	printf("\n %.06lf", *&FX);
	printf("\n %c", *&cht);

	printf("\n\n via pointer:");
	ptr = &M;
	printf("\n %p", ptr);
	printf("\n %d", *ptr);

	fptr = &FX;
	printf("\n %p", fptr);
	printf("\n %.06lf", *fptr);

	ptr = &cht;
	printf("\n %p", ptr);
	printf("\n %c", *ptr);

	//free(*ptr);
}

int example4(void)
{
	int a, b;
	int* pa, * pb;

	printf("Input a: "); scanf_s("%d", &a);
	printf("Input b: "); scanf_s("%d", &b);

	pa = &a;
	pb = &b;

	printf("a + b = %d", (*pa + *pb));
}

int example5(void)
{
	int a, b;
	int* pa, * pb;

	printf("Input a: "); scanf_s("%d", &a);
	printf("Input b: "); scanf_s("%d", &b);

	pa = &a;
	pb = &b;

	if (*pa > *pb) {
		printf("%d is greater", *pa);
	}
	else {
		printf("%d is greater", *pb);
	}
}

int ex1(void)
{
	char Z = 'Z';
	int A = 10;
	double D = 10.10;

	char* pZ; pZ = &Z;
	int* pA; pA = &A;
	double* pD; pD = &D;

	printf("\nptr char \n %lu bytes", sizeof(pZ));
	printf("\nchar \n %lu bytes", sizeof(Z));
	printf("\nptr int \n %lu bytes", sizeof(pA));
	printf("\nint \n %lu bytes", sizeof(A));
	printf("\nptr double \n %lu bytes", sizeof(pD));
	printf("\ndouble \n %lu bytes", sizeof(D));
}

int ex2(void)
{
	float PI = 3.14159, * p1, * p2;
	p1 = p2 = &PI;
	printf("Address p1=%p stores *p1=%g\n", p1, *p1);
	printf("Address p2=%p stores *p2=%g\n", p2, *p2);

	//
	int number = 10, * pa;
	pa = &number;
	printf("\n %d", *pa);
	printf("\n %x", *pa);
}

int ex3(void)
{
	int* pa, x = 5;
	pa = &x;
	printf("address %p stores *ptr=%d\n", pa, *pa);
	pa++;
	printf("address %p stores *ptr=%d\n", pa, *pa);
	pa--;
	printf("address %p stores *ptr=%d\n", pa, *pa);
	
	//++ и -- меняет на 4 байта по инту
	// double 8
	//char 1

}

int ex4(void)
{
	float array[4] = { 1.1, 2.2, 3.3, 4.4 };
	float* ptr_array;
	int i;

	ptr_array = &array;

	printf("\n %.01lf", array[0]);
	printf("\n %.01lf", *ptr_array);

	printf("\n\n %p", array);
	printf("\n %p", &array);
	printf("\n %p", &array[0]);

	printf("\n");

	printf("\n %.01lf", *ptr_array);
	printf("\n %.01lf", *++ptr_array);
	printf("\n %.01lf", *ptr_array + 4);
	printf("\n %.01lf", *ptr_array - 2);

	ptr_array--; printf("\n");
	//via adresses

	for (i = 0; i < 4; i++) {
		printf("\n%.01lf = %p", array[i], &array[i]);
	}

	printf("\n");

	for (i = 3; i >= 0; i--) {
		printf("\n%.01lf = %p", array[i], &array[i]);
	}

	printf("\n");

	//via pointers
	for (i = 0; i < 4; i++) {
		printf("\n%.01lf = %p", *ptr_array++, ptr_array);	
	}
	*ptr_array--;

	printf("\n");

	for (i = 3; i >=0; i--) {
		printf("\n%.01lf = %p", *ptr_array--, ptr_array);
	}
}

int ex5(void)
{
	int x = 0x12345678;
	printf("%.2x\n", x);
	printf(" (%d)\n", x);

	int* ptr;
	unsigned char* a1, * a2, * a3, * a4; //bytes pointers
	unsigned char* a; //byte pointer

	ptr = &x; //
	a = (unsigned char*)ptr; //convertion

	a1 = a + 3; //4th byte of number x
	a2 = a + 2; 
	a3 = a + 1;
	a4 = a;

	printf("%.2x\n%.2x\n%.2x\n%.2x\n", *a1, *a2, *a3, *a4);
}

int ex5_1(void)
{
	float x = 1.123456;
	int i;

	int* ptr;
	ptr = &x;
	unsigned char* byte = (unsigned char*) ptr;

	for (i = sizeof(x); i >= 0; i--) {
		printf("%.02X \n", byte[i]);
	}
}

int ex5_2(void)
{
	char x = 'A';
	int i;

	int* ptr;
	ptr = &x;
	unsigned char* byte = (unsigned char*)ptr;

	for (i = sizeof(x); i >= 0; i--) {
		printf("%.02X \n", byte[i]);
	}
}

int ex5_3(void)
{
	int x = 12345678;
	int i;

	int* ptr;
	ptr = &x;
	unsigned char* byte = (unsigned char*)ptr;

	for (i = sizeof(x); i >= 0; i--) {
		printf("%.02X \n", byte[i]);
	}
}

int ex5_4(void)
{
	int x = 0x12345678;
	int i;

	int* ptr;
	ptr = &x;

	unsigned char* byte = (unsigned char*)ptr;

	//printf("%lu\n", sizeof(x));

	for (i = sizeof(x); i >= 0; i--) {
		printf("%.02X \n", byte[i]);
	}
}