#include<stdio.h>
#include<conio.h>
#include<math.h>
float f(float);
float g(float);
float f(float x){
	return ((x*x*x*x)-x-10);
}
float g(float x){
	return ((4*x*x*x)-1);
}
int main(){
	int i=1;
	float x0,x1,fx0,gx0;
	printf("\nEnter the guess: ");
	scanf("%f",&x0);
	printf("\n\t|%4s|%8s|%8s|\n","iter","x0","x1" );
	printf("-----------------------------------------\n");
	do{
		x1=x0;
		fx0=f(x0);
		gx0=g(x0);
		x0=(x0-(fx0/gx0));
	    printf("\t|%4d|%8.3f|%8.3f|\n",i,x1,x0);
	    i++;
	}while((fabs((x0-x1)))>0.0001);
	printf("\n\nNo of iteration: ");
	printf("%d",i-1);
	printf("\n\nRequired root: ");
	printf("%f",x0);
	return 0;
}
