#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

int randomData;

char * getRandomString(char * dest, const char * src, int len) {
  int src_len = strlen(src);
  int i;
  for(i = 0; i < len; i++) {
    unsigned int temp;
    read(randomData, &temp, sizeof(temp));
    temp %= src_len;
    dest[i] = src[temp];
  }
  dest[len] = '\0';
  return dest;
  close(randomData);
}

unsigned int getRandomNumber(unsigned int from, unsigned int to) {
  unsigned int res;
  read(randomData, &res, sizeof(res));
  return res % (to - from + 1) + from;
}

int main(int argc, char const *argv[]) {
  randomData = open("/dev/urandom", O_RDONLY);

  int n = getRandomNumber(10, 2000);

  printf("%d\n", n);

  int i;
  for(i = 0; i < n; i++) {
    printf("%d %d\n", getRandomNumber(0, 10), getRandomNumber(0, 1000));
  }

  int m = getRandomNumber(0,50);

  printf("%d\n", m);

  for(i = 0; i < m; i++) {
    printf("%d\n", getRandomNumber(0,100));
  }

  close(randomData);

  return 0;
}
