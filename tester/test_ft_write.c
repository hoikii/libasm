/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_write.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanlee <kanlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 19:28:53 by kanlee            #+#    #+#             */
/*   Updated: 2021/04/11 21:24:45 by kanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

static void	test(int fd, char *buf, int bytes)
{
	int	result;

	errno = 0;
	result = write(fd, buf, bytes);
	printf(" -- result=%d", result);
	if (errno)
		printf(" errno=%d, %s", errno, strerror(errno));
	printf("\n");
	errno = 0;
	result = ft_write(fd, buf, bytes);
	printf(" -- result=%d", result);
	if (errno)
		printf(" errno=%d, %s", errno, strerror(errno));
	printf("\n");
	return ;
}

void		test_ft_write(void)
{
	test(-1, "sample test text", 10);
	test(1, "sample test text", -1);
	test(1, NULL, 10);
	test(1, "sample test text", 10);
	test(1, "sample test text", 5);
}
