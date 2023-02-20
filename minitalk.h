/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 18:48:06 by cmichez           #+#    #+#             */
/*   Updated: 2023/02/19 15:38:37 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <sys/types.h>

void	ft_putstr(char *str);
void	printf_shell(int compteur);
void	ft_putchar(char c);
int		ft_strlen(char *str);
void	decal_bit(char c, int pid);
char	*ft_itoa(int n);
int		ft_atoi(char *nptr);
char	*ft_strjoin(char *s1, char s2);

#endif