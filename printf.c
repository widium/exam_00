/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 18:18:37 by ebennace          #+#    #+#             */
/*   Updated: 2022/07/14 18:18:56 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <stdarg.h>

void ft_putchar(char c, int *count)
{
    write(1, &c, 1);
    *count += 1;
}

void ft_putstr(const char *str, int *count)
{
    int i;

    i = 0;
    while (str[i])
    {
        ft_putchar(str[i], count);
        i++;
    }
}

void ft_putnbr(int number, int *count)
{
    unsigned int nb;
    
    if (number < 0)
    {
        ft_putchar('-', count);
        nb = (unsigned int)number * -1;
    }
    else
        nb = (unsigned int)number;
    if (nb >= 10)
    {
        ft_putnbr(nb / 10, count);
        ft_putnbr(nb % 10, count);
    }
    else
        ft_putchar(nb + '0', count);
}

void ft_puthexa(unsigned long nbr, int *count)
{
    char *alphabet = "0123456789abcdef";
    int base = 16;

    if (nbr >= base)
    {
        ft_puthexa(nbr / base, count);
        ft_puthexa(nbr % base, count);
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
        ft_puthexa(va_arg(arg, unsigned long), &count);
    return (count);
}

int ft_printf(const char *str, ...)
{
    va_list arg;
    int i = 0;
    int return_count = 0;
    
    va_start(arg, str);
    while (str[i])
    {
        if (str[i] == '%')
           return_count += detect_type(arg, str, ++i) - 1;
        else
            ft_putchar(str[i], &return_count);
        i++;
    }
    va_end(arg);
    return (return_count);
}

int main()
{
    int count;

    count = ft_printf("salut moi c'est %s immatriculer : %d qui peut s'ecrire %x\n", 
        "Eddie", 42, 42);
    ft_printf("count : %d\n", count);
}

