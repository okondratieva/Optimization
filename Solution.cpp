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

double foo_bar(my_vector *v)
{
	long i, len = my_vector_len(v);

	double tmp = 1, tmp2 = 1;
	for (i = 0; i < lim; i += 2) {
		tmp *= v->data[i];
		tmp2 *= v->data[i + 1];
	}
	return tmp * tmp2;
}

double a[LENGTH];
my_vector v = { LENGTH, a };

int main() {
	double res;

	for (i = 0; i < LENGTH; i++)
		a[i] = i / 2 + 1;

	double start = omp_get_wtime();
	for (int j = 0; j<100; j++)
		res=foo_bar(&v);
	double finish = omp_get_wtime();

	std::cout << "time: " << (finish - start) / 100 << std::endl;
	std::cout << "res: " << res << std::endl;
}
