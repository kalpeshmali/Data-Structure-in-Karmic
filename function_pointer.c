#include<stdio.h>
/*
function pointer no argument and no return type
void (*func)();
void display()
{
	printf("Kalpesh\n");
}
void (*func)(void);

int main()
{
	func=display;
	(*func)();
}
...............................................

Function pointer intialise the 
void display()
{
	printf("Kalpesh\n");
}
void (*func)(void)=display;

int main()
{
	func=display;
	(*func)();
}
.....................................................*/
/*
function pointer with argument:

void display(int x)
{
	printf("%d ",x);
}
void (*func)(int x)=display;
int main()
{
	(*func)(7);
}
.....................................................*/
//Array of Function Pointer

int Add(int a,int b)
{
	return a+b;
}
int Sub(int a,int b)
{
	return a-b;
}
int Mul(int a,int b)
{
	return a*b;
}
int Div(int a,int b)
{
	return a/b;
}
int (*func[4])(int x,int y)={Add,Sub,Mul,Div};
int main()
{
	int a,b,choice,result=0;
	scanf("%d%d",&a,&b);
	scanf("%d",&choice);
	result=(*func[choice])(a,b);
	printf("%d",result);
}

