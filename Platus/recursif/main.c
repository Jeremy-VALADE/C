#include <stdio.h>

int factorial(int n){
  if ( n == 0 || n == 1)
    return 1;
  else
    return n* factorial(n-1);
}

int fibonacci(int n) {
	if ( n == 0)
		return 0;
	else if ( n == 1)
		return 1;
	else
		return fibonacci(n-1) + fibonacci(n-2);
}


int ackermann(int m, int n) {
	if ( m == 0)
		return n + 1;
	else if (m > 0 && n == 0)
		return ackermann(m - 1, 1);
	else if (m > 0 && n > 0)
		return ackermann(m-1, ackermann(m, n-1));

}

int main() {
	printf("Factorielle de 5 : %d\n", ackermann(2, 2));
	return 0;
}
