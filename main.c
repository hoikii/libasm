#include <stdio.h>
#include <string.h>

size_t	ft_strlen(const char *s);
char	*ft_strcpy(char *dst, const char *src);

void	test_ft_strlen(char *s)
{
	if (s == NULL)
		printf("NULL: %s --  %zu\n", "segfault", ft_strlen(s));
	else
		printf("%s: %ld -- %zu\n", s, strlen(s), ft_strlen(s));
}

void	test_ft_strcpy(char *s)
{
	char	dst[10];
	char	dst_ori[10];

	if (s == NULL)
		printf("NULL: %s -- %s\n", "segfault", ft_strcpy(dst, s));
	else
		printf("%s -- %s\n", strcpy(dst_ori, s), ft_strcpy(dst, s));
}

int		main()
{
	printf(">>> Starting libasm test <<<\n");
	printf("\n===ft_strlen===\n");
	test_ft_strlen(NULL);
	test_ft_strlen("");
	test_ft_strlen("abcde");

	printf("\n===ft_strcpy===\n");
	test_ft_strcpy(NULL);
	test_ft_strcpy("");
	test_ft_strcpy("abcde");
	test_ft_strcpy("xyz");
	

	return (0);
}
