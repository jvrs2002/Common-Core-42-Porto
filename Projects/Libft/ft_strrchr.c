/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:54:29 by joao-vri          #+#    #+#             */
/*   Updated: 2024/04/15 16:12:01 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

char    *ft_strrchr(const char *s, int c)
{    
    char    *ptr;

    ptr = NULL;
    while (*s)
    {
        if (*s == c)
            ptr = (char *)s;
        s++;
    }
    if (c == '\0')
        return ptr;
    else if (ptr != NULL)
        return ptr;
    return NULL;
}

/*int main(void)
{
    printf("%s", ft_strrchr("Teste", 't'));
}*/