#include <stdio.h>
#include <stdlib.h>
int main()
{
FILE *fptr1, *fptr2; char
filename[100], c;
printf("Enter the filename to open for reading \n");
scanf("%s", filename);
fptr1 = fopen(filename, "r");if
(fptr1 == NULL)
printf("Cannot open file %s \n", filename);
exit(0);
}
