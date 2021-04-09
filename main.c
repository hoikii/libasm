#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

size_t	ft_strlen(const char *s);
char	*ft_strcpy(char *dst, const char *src);
int		ft_strcmp(const char *s1, const char *s2);
ssize_t	ft_read(int fd, void *buf, size_t nbyte);

void	test_ft_strlen(char *s)
{
	if (s == NULL)
		printf("%s: %s --  %zu\n", s, "segfault", ft_strlen(s));
	else
		printf("%s: %ld -- %zu\n", s, strlen(s), ft_strlen(s));
	return ;
}

void	test_ft_strcpy(char *s)
{
	char	dst[10];
	char	dst_ori[10];

	if (s == NULL)
		printf("%s: %s -- %s\n", s, "segfault", ft_strcpy(dst, s));
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

void	test_ft_read_err1(int bytes)
{
	int		result;
	char	buf[100];
	char	buf_ori[100];

	memset(buf, 0, sizeof(buf));
	memset(buf_ori, 0, sizeof(buf_ori));
	errno = 0;
	result = read(-1, buf_ori, bytes);
	printf("(result=%d)%s(errno=%d)\n", result, buf_ori, errno);
	errno = 0;
	result = ft_read(-1, buf, bytes);
	printf("(result=%d)%s(errno=%d)\n", result, buf, errno);
	return ;
}

void	test_ft_read_err2(int bytes)
{
	int		fd;
	int		result;
	char	buf[100];
	char	buf_ori[100];

	memset(buf, 0, sizeof(buf));
	memset(buf_ori, 0, sizeof(buf_ori));
	fd = open("main.c", O_RDONLY);
	if (fd < 0)
		return ;
	errno = 0;
	result = read(fd, NULL, bytes);
	printf("(result=%d)%s(errno=%d)\n", result, buf_ori, errno);
	errno = 0;
	result = ft_read(fd, NULL, bytes);
	printf("(result=%d)%s(errno=%d)\n", result, buf, errno);
	return ;
}

void	test_ft_read(int bytes)
{
	int		fd;
	int		result;
	char	buf[100];
	char	buf_ori[100];

	memset(buf, 0, sizeof(buf));
	memset(buf_ori, 0, sizeof(buf_ori));
	fd = open("main.c", O_RDONLY);
	if (fd < 0)
		return ;
	errno = 0;
	result = read(fd, buf_ori, bytes);
	printf("(result=%d)%s(errno=%d)\n", result, buf_ori, errno);
	lseek(fd, 0, SEEK_SET);
	errno = 0;
	result = read(fd, buf, bytes);
	printf("(result=%d)%s(errno=%d)\n", result, buf, errno);
	close(fd);
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
	test_ft_strcmp("abc", "abC");
	test_ft_strcmp("abc", "abx");
	test_ft_strcmp("xyz", "xyz");

	printf("\n===ft_read===\n");
	test_ft_read_err1(5);
	test_ft_read_err2(5);
	test_ft_read(5);
	test_ft_read(4);
	test_ft_read(3);
	return (0);
}
