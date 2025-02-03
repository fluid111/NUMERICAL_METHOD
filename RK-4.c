//Runge Kutta-4 Method

#include<stdio.h>
#include<math.h>
float f(float x,float y)
{
    return (x-y)/2;
}
int main(){
    int i=0,n;
    float x0,y0,k,k1,k2,k3,k4,h=0,xn=0,yn=0;
    printf("Enter initial conditions ");
    scanf("%f %f",&x0,&y0);
    printf("Enter no of steps ");
    scanf("%d", &n);
    printf("Enter calculation point");
    scanf("%f", &xn);
    h=(xn-x0)/n;
    // printf("\n\nX\t\tY\n");
    do{
        k1=h*f(x0,y0);
        k2=h*f((x0+h/2.0),(y0+k1/2.0));
        k3=h*f((x0+h/2.0),(y0+k2/2.0));
        k4=h*f((x0+h),(y0+k3));
        k=((k1+2*k2+2*k3+k4)/6);
        yn=y0+k;
        x0=x0+h;
        y0=yn;
        i=i+1;
        // printf("%f\t%f\n",x0,y0);
    }while(i<n);
    printf("%f", yn);

    return 0;
}
