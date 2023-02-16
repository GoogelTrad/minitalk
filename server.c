/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:42:11 by cmichez           #+#    #+#             */
/*   Updated: 2023/02/16 17:22:45 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void print_pid()
{
    ft_putstr("PID : ");
    printf_shell(getpid());
    ft_putstr("\n");
}

void recu(int s)
{
    static char res = 0;
    static int i = 0;

    res |= (s == SIGUSR1);
    i++;
    if (i < 8)
        res <<= 1;
    if(i == 8)
    {
        ft_putchar(res);
        i = 0;
        res = 0;
    }
}

int main(void)
{   
    ft_putstr("Server start !\n");
    print_pid();
    signal(SIGUSR1, recu);
    signal(SIGUSR2, recu);
    while (1)
        pause();
    return (0);
}