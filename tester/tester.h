/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanlee <kanlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 20:46:17 by kanlee            #+#    #+#             */
/*   Updated: 2021/04/16 18:36:51 by kanlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTER_H
# define TESTER_H

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <stdlib.h>
# include "../libasm.h"

void		test_ft_strlen(void);
void		test_ft_strcpy(void);
void		test_ft_strcmp(void);
void		test_ft_read(void);
void		test_ft_write(void);
void		test_ft_strdup(void);

#endif
