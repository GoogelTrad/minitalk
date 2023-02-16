#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <sys/types.h>

void    ft_putstr(char *str);
void	printf_shell(int compteur);
void	ft_putchar(char c);
int ft_strlen(char *str);
void decal_bit(char c, int pid);
char	*ft_itoa(int n);
int ft_atoi(char *nptr);

#endif