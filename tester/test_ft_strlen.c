/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanlee <kanlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 19:28:53 by kanlee            #+#    #+#             */
/*   Updated: 2021/04/11 21:24:14 by kanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

static void	test(char *s)
{
	if (s == NULL)
		printf("%s: %s --  %zu\n", s, "segfault", ft_strlen(s));
	else
		printf("%s: %ld -- %zu\n", s, strlen(s), ft_strlen(s));
	return ;
}

void		test_ft_strlen(void)
{
	test(NULL);
	test("");
	test("abcde");
}
