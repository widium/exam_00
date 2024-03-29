## **Inter && Union**
![](https://i.imgur.com/xyNtrbQ.png)

La difference entre c'est deux fonction c'est que 
- **Union** *ecrit tous les caracteres rencontrer* 
- **Inter** *ecrit que ceux en commun* 
Il ecrivent tous les deux des caracteres unique !

~~~C
#include <unistd.h>

void    ft_union(char *str1, char *str2)
{
    int    i;
    int vector[128] = {0};

    i = 0;
    while (str1[i])
    {
        //Si le caracteres n'est pas ecrit, l'ecrire
        if (vector[(int)str1[i]] == 0)
        {
            //enregistrer la lecture
            vector[(int)str1[i]] = 1;
            write(1, &str1[i], 1);
        }
        i++;
    }
    i = 0;
    while (str2[i])
    {
        //Si le caracteres n'est pas ecrit, l'ecrire
        if (vector[(int)str2[i]] == 0)
        {
            // enregistrer la lecture
            vector[(int)str2[i]] = 1;
            write(1, &str2[i], 1);
        }
        i++;
    }
}
~~~
### **Vecteur de Stockage de caracteres** 
![](https://i.imgur.com/FIxl9qR.png)
![](https://i.imgur.com/aQKiJ53.png)
~~~C
int vector[128] = {0};
char c = 'A'
	
if (vector[(int)c] == 0;
	//l'index numero 65 = 0 ?
~~~
***
## **Mini Printf**
![](https://i.imgur.com/93Hug3n.png)

~~~C
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
~~~

~~~C
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
~~~
***
## **Mini Get_next_line**

![](https://i.imgur.com/FlAh9cJ.png)

~~~C
char *get_next_line(int fd)
{
    char *start = malloc(10000);
    char *cursor = start;
    
    while(read(fd, cursor, 1) > 0)
    {
        if (*cursor == '\n')
            break;
        *cursor++;
    }
    if (cursor > start)
    {
        *cursor = 0;
        return (start);
    }
    return (NULL);
    
}
~~~