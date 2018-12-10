#include <iostream>
#include <omp.h>
#define LENGTH 20000

typedef struct {
	long len;
	double *data;
} my_vector;

long my_vector_len(my_vector *v) {
	return v->len;
}

void foo_bar(my_vector *v, double *res)
{
	long i, len = my_vector_len(v);
	*res = 1;
	for (i = 0; i < len; i++) {
		*res *= v->data[i];
	}
}

double a[LENGTH];
my_vector v = { LENGTH, a };

int main() {
	double res;

	for (i = 0; i < LENGTH; i++)
		a[i] = i / 2 + 1;

	double start = omp_get_wtime();
	for (int j = 0; j<100; j++)
		foo_bar(&v, &res);
	double finish = omp_get_wtime();

	std::cout << "time: " << (finish - start) / 100 << std::endl;
	std::cout << "res: " << res << std::endl;
}
