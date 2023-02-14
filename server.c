/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:42:11 by cmichez           #+#    #+#             */
/*   Updated: 2023/02/14 22:57:25 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void print_pid()
{
    ft_putstr("PID : ");
    printf_shell(getpid());
    ft_putstr("\n");
}

int main(void)
{
    ft_putstr("Server start !\n");
    print_pid();
    signal(SIGUSR1, print_pid);
    signal(SIGUSR2, print_pid);
    while (1);
    return (0);
}