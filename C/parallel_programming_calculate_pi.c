// A program built with OpenMP that uses paralell programming to calculate a value for PI.
#include <stdio.h>
#include <unistd.h>
#include <math.h>

int main(){
    // n is a very large, arbitary integer
	int n = 10000000;
	float value = 0;

// omp parallel for - Is a combination of omp parallel and omp for
// omp parallel instructs compiler to parallelize the following code block (the loop) 
// and creates a team of threads.
// omp for distributes the work of the loop among the team of threads created with omp parallel.
#pragma omp parallel for
	for(int a = 1; a <= n; a=a+1){
    // Allows only one thread to execute this code block at a time.
	#pragma omp critical
		value = value + (a - (a*a) + (sqrt(2*a + 2)));
	}
	printf("S = %f\n", value);
}
