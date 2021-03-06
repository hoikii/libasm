/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanlee <kanlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 19:28:53 by kanlee            #+#    #+#             */
/*   Updated: 2021/04/11 21:09:45 by kanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester/tester.h"

int		main(void)
{
	printf(">>> Starting libasm test <<<\n");
	printf("\n===ft_strlen===\n");
	test_ft_strlen();
	printf("\n===ft_strcpy===\n");
	test_ft_strcpy();
	printf("\n===ft_strcmp===\n");
	test_ft_strcmp();
	printf("\n===ft_read===\n");
	test_ft_read();
	printf("\n===ft_write===\n");
	test_ft_write();
	printf("\n===ft_strdup===\n");
	test_ft_strdup();
	return (0);
}
