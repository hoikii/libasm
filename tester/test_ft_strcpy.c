/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strcpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanlee <kanlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 19:28:53 by kanlee            #+#    #+#             */
/*   Updated: 2021/04/11 21:24:30 by kanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

static void	test(char *s)
{
	char	dst[10];
	char	dst_ori[10];

	if (s == NULL)
		printf("%s: %s -- %s\n", s, "segfault", ft_strcpy(dst, s));
	else
		printf("%s -- %s\n", strcpy(dst_ori, s), ft_strcpy(dst, s));
	return ;
}

void		test_ft_strcpy(void)
{
	test(NULL);
	test("");
	test("abcde");
	test("xyz");
}
