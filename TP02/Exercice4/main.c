#include <stdio.h>


void print_var(int toto) {
	printf("Value of the variable : %d\n", toto);

}

void print_pointer(int* p){
	printf("Pointer adress : %p and Pointer value : %d\n", p, *p);
}

void set_pointer(int *p ,int n) {
	*p = n;
}

int main(){
	int a;
	int *p = &a;
	print_var(a);
	a = 53;
	print_var(a);
	print_pointer(p);
	set_pointer(p, 42);
	print_pointer(p);
	print_var(a);

	return 0;
}
