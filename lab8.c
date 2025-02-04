#include<stdio.h>
#include<math.h>
#define n 10
#define TOLERANCE 1e-6
#define MAX_ITERATIONS 1000

void solve_l(double g[n][n]){
	int i,j , iteration= 0;
	double error, max_error;
	double temp[n][n];
	
do{
	max_error = 0.0;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			temp[i][j]= g[i][j];
		}
	}
	for(i=0;i<n-1;i++){
	    for(j=0;j<n-1;j++){
		    g[i][j]=(temp[i+1][j]+temp[i-1][j]+ temp[i][j+1]+temp[i][j-1])/4.0;
			error= fabs(g[i][j]-temp[i][j]);
			if(error>max_error){
            max_error=error;
			}
	    }
	}
	iteration++;

} while(max_error> TOLERANCE && iteration< MAX_ITERATIONS);
printf("CONVERGED IN %d ITERATION \n",iteration);
}

int main(){
	int i,j;
	double g[n][n]= {0};
	for ( i=0; i<n; i++){
		g[0][i]= 100.0;
		g[n-1][i]=0.0;
		g[i][0]= 0.0;
		g[i][n-1]= 0.0;
		
	}
	solve_l(g);
		for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%7.2f",g[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("AASHISH THAPA MAGAR");
	return 0;
}

