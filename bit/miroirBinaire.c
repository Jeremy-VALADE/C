void miror_bin(void* data, size_t size){
  char* a = (char*)data;
  int i, j;
  for (i = 0; i < size; i++) {
    unsigned char d = 0;
    for(j = 0; j < 8; j++){
      if(a[i]&(1<<j))
        d = d|(1<<(7-j));
    }
    a[i] = d;

  }
  for (i = 0; i < size/2; i++) {
    char tmp = a[i];
    a[i] = a[size-1-i];
    a[size-1-i] = tmp;
  }

}