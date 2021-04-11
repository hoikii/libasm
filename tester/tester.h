/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanlee <kanlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 20:46:17 by kanlee            #+#    #+#             */
/*   Updated: 2021/04/11 21:25:37 by kanlee           ###   ########.fr       */
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

ssize_t		ft_write(int fd, void *buf, size_t nbyte);
size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *s);
char		*ft_strcpy(char *dst, const char *src);
int			ft_strcmp(const char *s1, const char *s2);
ssize_t		ft_read(int fd, void *buf, size_t nbyte);

void		test_ft_strlen(void);
void		test_ft_strcpy(void);
void		test_ft_strcmp(void);
void		test_ft_read(void);
void		test_ft_write(void);
void		test_ft_strdup(void);

#endif
