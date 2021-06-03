void shift_circular_left(unsigned char *c, unsigned int n) {
  n = n%CHAR_BIT;
  unsigned char tmp = (*c)>>(CHAR_BIT - n);
  (*c) = ((*c)<<n) | tmp;
}


int main() {
  unsigned char *c;
  unsigned int n;

  return 0;
}