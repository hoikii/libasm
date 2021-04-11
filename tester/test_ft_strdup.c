/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strdup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanlee <kanlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 19:28:53 by kanlee            #+#    #+#             */
/*   Updated: 2021/04/11 21:24:35 by kanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

static void	test(char *s)
{
	char *dup;
	char *dup_orig;

	if (s != NULL)
	{
		dup = ft_strdup(s);
		dup_orig = strdup(s);
		printf("%s -- %s\n", dup_orig, dup);
		free(dup);
		free(dup_orig);
	}
	else
	{
		dup = ft_strdup(s);
		printf("%s -- %s\n", "segfult", dup);
		free(dup);
	}
	return ;
}

void		test_ft_strdup(void)
{
	test("abcde");
	test("");
	test(NULL);
}
