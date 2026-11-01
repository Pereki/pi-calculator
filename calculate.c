#include <math.h>
#include <omp.h>
#include <stdio.h>
int main() {
  long double calculated_pi_formula = 0.0;

#pragma omp parallel for reduction(+ : calculated_pi_formula)
  for (long i = 1; i < 100000000; i++) {
    long double n = (long double)i;
    calculated_pi_formula += 1.00 / (n * n);
  }

  long double value_to_be_squred = calculated_pi_formula * 6.00;
  long double pi = sqrt(value_to_be_squred);
  printf("Pi is: %.15Lf", pi);
}
