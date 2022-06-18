/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 12:24:34 by ebennace          #+#    #+#             */
/*   Updated: 2022/06/18 13:40:46 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <unistd.h>

void inter(char *str1, char *str2)
{
    int vector[128] = {0};
    int i;

    i = 0;
    while (str2[i])
    {
        if (vector[(int)str2[i]] == 0)
            vector[(int)str2[i]] = 1;
        i++;
    }
    i = 0;
    while (str1[i])
    {
        if (vector[(int)str1[i]] == 1)
        {
            vector[(int)str1[i]] = 2;
            write(1, &str1[i], 1);
        }
        i++;
    }
}

int main(int argc, char **argv)
{
    if (argc == 3)
        inter(argv[1], argv[2]);
    write(1, "\n", 1);
    return (0);
}