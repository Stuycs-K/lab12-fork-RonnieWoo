#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>
#include <time.h>
#include <sys/types.h>
#include <dirent.h>
#include "random.h"

int err(){
    printf("errno %d\n",errno);
    printf("%s\n",strerror(errno));
    exit(1);
}

int randomInt(){
  int file = open("/dev/random", O_RDONLY, 0);
  if(file == -1){
    err();
  }
  int p;
  int result = read(file, &p, 4);
  if (result == -1){
    err();
  }
  p = abs(p);
  return p % 5 + 1;
}