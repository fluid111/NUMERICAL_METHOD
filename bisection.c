#include<stdio.h>
#include<conio.h>
#include<math.h>
#define f(x) x*x*x-x-11
int main(){
    int i;
    float a,b,fa,fb,fc;
	float c;
	do{
	printf("\nEnter any two initial guesses:");
		scanf("%f%f",&a,&b);
		fa=f(a);
		fb=f(b);
	}while(f(a)*f(b)>0);
	do{
		c=(a+b)/2;
		printf("%d\t%.3f\t%.3f\t%.3f\t%.3f\t%.3f\t%.3f\n",i,a,b,c,fa,fb,fc);
		i++;
		fc=f(c);
		if(fa*fc<0){
			b=c;
		}
		else{
			a=c;
		}
	}while(fabs(b-a)>0.001);
	printf("\nIteration: ");
	printf("%d",i);
	printf("\nRoot is: ");
	printf("%f",c);
	return 0;
}
