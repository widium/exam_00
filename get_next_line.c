/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 14:12:30 by ebennace          #+#    #+#             */
/*   Updated: 2022/07/22 09:31:32 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



char *get_next_line(int fd)
{
    char *start = malloc(10000);
    char *cursor = start;
    
    while(read(fd, cursor, 1) > 0)
    {
        if (*cursor == '\n')
            break;
        cursor++;
    }
    if (cursor > start)
    {
        *cursor = 0;
        return (start);
    }
    free(start);
    return (NULL);
    
}

// char *get_next_line(int fd) 
// {
//     char *s = malloc(10000), *c = s;
//     while (read(fd, c, 1) > 0 && *c++ != '\n');
//     return c > s ? (*c = 0, s) : (free(s), NULL);
// }

int main()
{
    int fd = open("file", O_RDONLY);
    char *a;
    int i = 0;
    while (i < 6)
    {
        a =  get_next_line(fd);
        printf("Return : %s\n", a);
        free(a);
        i++;
    }
    
}
