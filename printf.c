/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 11:50:20 by ebennace          #+#    #+#             */
/*   Updated: 2022/07/27 11:03:42 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdarg.h>

void ft_putchar(char c, int *count)
{
    write(1, &c, 1);
    *count += 1;
}

void ft_putstr(char *str, int *count)
{
    int i;

    i = 0;
    if (!str)
    {
        write(1, "(null)", 6);
        return;
    }
    while (str[i])
    {
        ft_putchar(str[i], count);
        i++;
    }
}

void ft_putnbr(int number, int *count)
{
    unsigned int nbr;

    if (number < 0)
    {
        ft_putchar('-', count);
        nbr = (unsigned int)number * -1;
    }
    else
        nbr = (unsigned int)number;
    if (nbr >= 10)
    {
        ft_putnbr(nbr / 10, count);
        ft_putnbr(nbr % 10, count);
    }
    else 
        ft_putchar(nbr + '0', count);
}

void ft_puthexa(unsigned int nbr, int *count)
{
    char *alphabet = "0123456789abcdef";

    if (nbr >= 16)
    {
        ft_puthexa(nbr / 16, count);
        ft_puthexa(nbr % 16, count);
    }
    else 
        ft_putchar(alphabet[nbr], count);
}

int detect_type(va_list arg, const char *str, int index)
{
    int count = 0;
    
    if (str[index] == 's')
        ft_putstr(va_arg(arg, char *), &count);
    else if (str[index] == 'd')
        ft_putnbr(va_arg(arg, int), &count);
    else if (str[index] == 'x')
        ft_puthexa(va_arg(arg, unsigned int), &count);
    return (count);
}

int ft_printf(const char *str, ...)
{
    va_list arg;
    int i = 0;
    int ret = 0;

    va_start(arg, str);
    while (str[i])
    {
        if (str[i] == '%')
            ret += detect_type(arg, str, ++i) - 1;
        else
            ft_putchar(str[i], &ret);
        i++;
    }
    va_end(arg);
    return (ret);
}

int main()
{
    int count;
    char *null = NULL;
    unsigned long min = -2147483649;

    count = ft_printf("salut moi c'est %s immatriculer : %d qui peut s'ecrire %x\n", 
        null, min, 42);
    ft_printf("count : %d\n", count);
}