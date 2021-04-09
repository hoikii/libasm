#include <stdio.h>
#include <string.h>

size_t	ft_strlen(const char *s);
char	*ft_strcpy(char *dst, const char *src);
int		ft_strcmp(const char *s1, const char *s2);

void	test_ft_strlen(char *s)
{
	if (s == NULL)
		printf("NULL: %s --  %zu\n", "segfault", ft_strlen(s));
	else
		printf("%s: %ld -- %zu\n", s, strlen(s), ft_strlen(s));
	return ;
}

void	test_ft_strcpy(char *s)
{
	char	dst[10];
	char	dst_ori[10];

	if (s == NULL)
		printf("NULL: %s -- %s\n", "segfault", ft_strcpy(dst, s));
	else
		printf("%s -- %s\n", strcpy(dst_ori, s), ft_strcpy(dst, s));
	return ;
}

void	test_ft_strcmp(char *s1, char *s2)
{
	if (s1 == NULL || s2 == NULL)
		printf("cmp (%s,%s): %s -- %d\n",
			s1, s2, "segfault", ft_strcmp(s1, s2));
	else
		printf("cmp (%s,%s): %d -- %d\n",
			s1, s2, strcmp(s1, s2), ft_strcmp(s1, s2));
	return ;
}

int		main(void)
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

	printf("\n===ft_strcmp===\n");
	test_ft_strcmp(NULL, NULL);
	test_ft_strcmp("a", NULL);
	test_ft_strcmp(NULL, "a");
	test_ft_strcmp("", "");
	test_ft_strcmp("abc", "abd");
	test_ft_strcmp("abx", "abd");
	test_ft_strcmp("xyz", "xyz");

	return (0);
}
