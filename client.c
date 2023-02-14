/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:11:42 by cmichez           #+#    #+#             */
/*   Updated: 2023/02/14 19:21:09 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int main(int argc, char **argv)
{
    int j;
    int pid;
    char c;
    
    pid = argv[2];
    j = ft_strlen(argv[2]) - 1;
    while (argv[2][j] && argc == 3)
    {
        c = argv[2][j];
        printf("%c\n", c);
        decal_bit(argv[2][j], pid);
        j--;
    }
    return (0);
}

void decal_bit(char c, int pid)
{
    int i;
    
    i = 8;
    while (i)
    {
        if ((c >> (i - 1)) & 1)
        {
            printf("Prout\n");
        }
        else
            printf("Prout\n");
        i--;
    }
}