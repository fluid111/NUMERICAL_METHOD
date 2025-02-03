#include<stdio.h>
#include<conio.h>
float y(float x){
    return (1/(x+1));
}
int main(){
    float xo, xn, h, s=0, I;
    int i, n;
    printf("Enter xo, xn, n: ");
    scanf("%f %f %d",&xo,&xn,&n);
    h=(xn-xo)/n;
    s=y(xo)+y(xn);
    for(i=1; i<n; i++){
        if(i%2==0){
            s=s+2*y(xo+i*h);
        }
        else{
            s=s+4*y(xo+i*h);
        }
    }
    I=(h/3)*s;
    printf("The required integration is %f",I);
    getch();
    return 0;

}
