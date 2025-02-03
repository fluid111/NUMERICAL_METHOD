#include<stdio.h>
#include<conio.h>
#include<math.h>

float f(float x){
    return (x*x*x-2*x-5);
}
void main(){
    int i=0;
    float a,b,c,fa,fb,fc;
    printf("\nEnter any two guesses: ");
    scanf("%f%f",&a,&b);
    printf("\nsn|\ta|\tb|\tc|\tf(a)|\tf(b)|\tf(c)");
    do{
        fa=f(a);
        fb=f(b);

        c=b-((b-a)*f(b)/(fb-fa));
        
        fc=f(c);
        printf("\n\n%d|\t%.3f|\t%.3f|\t%.3f|\t%.3f|\t%.3f|\t%.3f",i,a,b,c,fa,fb,fc);
        a=b;
        b=c;
        i++;
    }while(fabs(b-a)>0.0001);
    printf("\nNo of iteration: ");
    printf("%d",i);
    printf("\nRequired root: ");
    printf("%f",c);
}
