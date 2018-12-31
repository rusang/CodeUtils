#include <stdio.h>
#include <test.h>

int main(void)
{
	print_version();
	printf("hello world\n");
	printf("%s\n", TEST_STRING);
	return 0;
}
