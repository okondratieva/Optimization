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
	double tmp = 1, tmp2 = 1, tmp4 = 1, tmp3 = 1;
	long lim = len - 3;
	
	for (i = 0; i < lim; i += 4) {
		tmp *= v->data[i];
		tmp2 *= v->data[i + 1];
		tmp3 *= v->data[i + 2];
		tmp4 *= v->data[i + 3];
	}
	while (i < len)
	{
		tmp *= v->data[i];
		i++;
	}
	return tmp*tmp2*tmp3*tmp4;
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
