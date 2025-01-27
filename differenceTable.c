#include <stdio.h>
int main(){
    int n, x[100], y[100], arr[100][100];
    printf("enter n ");
    scanf("%d", &n);
    
    printf("enter x values: \n");
    for(int i=0; i<n; i++){
        printf("x[%d]: ",i);
        scanf("%d", &x[i]);
    }
    printf("enter y values: \n");
    for(int i=0; i<n; i++){
        printf("y[%d]: ",i);
        scanf("%d", &y[i]);
    }
    for(int i=0; i<n; i++){
        arr[i][0]= y[i];
    }
    for(int j=1; j<n; j++){
        for(int i=0; i<=n-j-1; i++){
            arr[i][j]=arr[i+1][j-1]-arr[i][j-1];
        }
    }
    printf("The difference table is :\n");
    // printf("y \t del y \t delsq y \t delcub y  :\n");
    for(int i=0; i<=n-1; i++){
        for(int j=0; j<=n-i-1; j++){
            printf("%d \t\t", arr[i][j]);
        }
        printf("\n");
    }
    printf("AASHISH THAPA MAGAR");
    return 0;
}