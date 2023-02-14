/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:42:11 by cmichez           #+#    #+#             */
/*   Updated: 2023/02/14 15:26:33 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void print_pid(void)
{
    int pid;

    pid = getpid();
    ft_putstr("PID : ");
    printf_shell(pid);
    ft_putstr("\n");
}

int main(void)
{
    ft_putstr("Server start !\n");
    print_pid();
    return (0);
}