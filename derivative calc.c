#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void diplay_poly(int n, float *num, int *ctr);
void derive(int deg, float *num, int*);
void integrate(int deg, float *num,int *num_s);

int main()
{
	int choice;
	int i,n;
	float *coeff;
	int deg;
	int *deg_s;
	
	printf("Enter How many terms in polynomial: ");
	scanf("%d", &deg);
	printf("\n");
	
	//allocating dynamic memory to deg and coeff arrays
	coeff = (float*) calloc(deg,sizeof(float));
	deg_s = (int*) calloc(deg,sizeof(int));

	//getting values for coeffs and degrees
	for(i = 0; i < deg; i++)
	{
		printf("%d. Enter Degree: ",i+1);
		scanf("%d", &deg_s[i]);
		printf("%d. Enter co-efficient of X to the power %d: ",i+1, *(deg_s+i));
		scanf("%f", &coeff[i]);
		printf("\n");
	}
		
	printf("\nEntered polynomial: \nf(x) = ");
	display_poly(deg,coeff,deg_s);
	getch();
	
	printf("\nOptions\n1.Differentiation\n2.Integration\nChoice: ");
	scanf("%d", &choice);
	
	switch(choice)
	{
		case 1:
			
			printf("\nDerivative:\nf`(x) = ");
			derive(deg,coeff,deg_s);
			printf("\n");
			getch();
			break;
			
		case 2:
		
			printf("\nIntegral:\nf(x) = ");
			integrate(deg, coeff, deg_s);
			printf("+ C\n");
			getch();
			break;
						
		default: 
			printf("Invalid choice!");
			return 1;
	}
}

void derive(int deg, float *num,int *num_s)
{
	int i;
	for(i = 0; i < deg; i++)
	{
		*(num + i) =(float) *(num + i) *  *(num_s + i);
		*(num_s + i) = *(num_s + i) - 1;
	}
	display_poly(deg,num,num_s);
	
}

void integrate(int deg, float *num,int *num_s)
{
	int i;
	for(i = 0; i < deg; i++)
	{
		*(num_s + i) = *(num_s + i) + 1;
		*(num + i) = *(num+i) / *(num_s+i);
//		printf("%d%d",*(num+ i),*(num_s+i));
	}
	
	display_poly(deg,num,num_s);
	
}

void display_poly(int n, float *num,int *ctr)
{
	int i;
	for(i = 0; i <= n; i++)
	{
		//condition to check if the coefficient's value is zero to skip 
		if(*(num + i ) == 0)
		{
			continue;
		}
		
		//condition to print + sign
		else if(*(num + i ) > 0)
		{
			if(i != 0)
			printf(" + ");		
		}
		
		//condition to print - sign
		else if(*(num + i ) < 0)
		{
			printf(" - ");
		}
		
		//condition to check if degree of x is equal to zero	
		if(*(ctr+i) == 0)
		{
			printf("%.1f",fabs(*(num + i )));
			break;
		}
		
		//condition to check if coefficient of x is 1
		if(*(num + i) == 1)
		{
			printf("X^%d",*(ctr+i));
		}
		else
		printf("%.1fX^%d",fabs(*(num + i )),*(ctr+i));	
	}
}
