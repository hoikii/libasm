#include <stdio.h>
#include <string.h>

size_t	ft_strlen(char *s);

void test_ft_strlen(char *s)
{
	printf("%s: %ld %zu\n", s, strlen(s), ft_strlen(s));
}

int	main()
{
	printf("Starting libasm test\n");
	printf("==ft_strlen==\n");
	test_ft_strlen("abcde");
	test_ft_strlen("");

	return (0);
}
