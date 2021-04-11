/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strcmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanlee <kanlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 19:28:53 by kanlee            #+#    #+#             */
/*   Updated: 2021/04/11 21:24:24 by kanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

static void	test(char *s1, char *s2)
{
	if (s1 == NULL || s2 == NULL)
		printf("cmp (%s,%s): %s -- %d\n",
			s1, s2, "segfault", ft_strcmp(s1, s2));
	else
		printf("cmp (%s,%s): %d -- %d\n",
			s1, s2, strcmp(s1, s2), ft_strcmp(s1, s2));
	return ;
}

void		test_ft_strcmp(void)
{
	test(NULL, NULL);
	test("a", NULL);
	test(NULL, "a");
	test("", "");
	test("abc", "abC");
	test("abc", "abx");
	test("xyz", "xyz");
}
