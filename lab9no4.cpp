#include<stdio.h>

//function prototype
	void swapValue(int *a, int *b, int *c);
	void swapArray(int a[], int b[], int size); 

	
int main() {
	int a = 1, b = 2, c = 3;
	printf("Before swap function: a=%d, b=%d, c=%d\n", a, b, c);
	swapValue(&a ,&b ,&c );
	printf("After swap function: a= %d, b=%d, c=%d\n", a, b, c);
	//calling swapArray()
	int ar1[5] ={1,2,3,4,5};
	int ar2[5] ={10,20,30,40,50};
	
	printf("Before swapArray:\n");
	for(int i =0;i <5;i++)
		printf("ar1[%d]=%d ar2[%d]=%d\n",i,ar1[i],i,ar2[i]);
	
	swapArray(ar1,ar2,5);
	
	printf("After swapArray:\n");
	for(int i =0;i <5;i++)
		printf("ar1[%d]=%d ar2[%d]=%d\n",i,ar1[i],i,ar2[i]);
		
	return 0;
}
void swapValue(int *a, int *b,int *c)
{
	int temp = *c;
	*c = *a;
	*a = *b;
	*b = temp;
}
void swapArray(int a[], int b[],int size)
{
	int temp;
	for	(int i =0;i < size;i++)
	{
		temp = a[i];
		a[i] = b[i];
		b[i] = temp;
	}
}
