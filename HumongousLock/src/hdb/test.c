#include <stdio.h>
#include <string.h>


int main()
{
  char input[60];

  unsigned long a, b;
  char lockMode[2];
  char queryType[16];

  printf("Enter info\n");
  fgets(input, 60, stdin);
  // sscanf(input,"%lu , %lu , %2s , %s", &a, &b, lockMode, queryType);

  // char* hello = strtok(input, ",");

  printf("%s\n", strtok(input, ","));
  printf("%s\n", strtok(NULL, ","));
  printf("%s\n", strtok(NULL, ","));

  printf("%lu  %lu  %s  %s\n", a, b, lockMode, queryType);
  return 0;
}