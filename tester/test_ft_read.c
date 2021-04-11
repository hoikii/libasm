/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_read.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanlee <kanlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 19:28:53 by kanlee            #+#    #+#             */
/*   Updated: 2021/04/11 21:25:22 by kanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

static void	test_err(int fd, int bytes)
{
	int		result;
	char	buf[100];
	char	buf_orig[100];

	memset(buf, 0, sizeof(buf));
	memset(buf_orig, 0, sizeof(buf_orig));
	errno = 0;
	result = read(fd, NULL, bytes);
	printf("(result=%d)%s", result, buf_orig);
	if (errno)
		printf(" errno=%d, %s", errno, strerror(errno));
	printf("\n");
	errno = 0;
	result = ft_read(fd, NULL, bytes);
	printf("(result=%d)%s", result, buf);
	if (errno)
		printf(" errno=%d, %s", errno, strerror(errno));
	printf("\n");
	return ;
}

static void	test(int fd, int bytes)
{
	int		result;
	char	buf[100];
	char	buf_orig[100];

	memset(buf, 0, sizeof(buf));
	memset(buf_orig, 0, sizeof(buf_orig));
	errno = 0;
	lseek(fd, 0, SEEK_SET);
	result = read(fd, buf_orig, bytes);
	printf("(result=%d)%s", result, buf_orig);
	if (errno)
		printf(" errno=%d, %s", errno, strerror(errno));
	printf("\n");
	errno = 0;
	lseek(fd, 0, SEEK_SET);
	result = read(fd, buf, bytes);
	printf("(result=%d)%s", result, buf);
	if (errno)
		printf(" errno=%d, %s", errno, strerror(errno));
	printf("\n");
	return ;
}

void		test_ft_read(void)
{
	int	fd;

	fd = open("main.c", O_RDONLY);
	if (fd < 0)
		return ;
	test(-1, 5);
	test_err(fd, 5);
	test(fd, -1);
	test(fd, 5);
	test(fd, 3);
	close(fd);
}
