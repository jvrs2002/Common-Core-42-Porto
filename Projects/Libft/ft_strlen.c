/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:53:50 by joao-vri          #+#    #+#             */
/*   Updated: 2024/04/11 11:46:37 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <string.h>
//#include <stdio.h>

size_t ft_strlen(const char *c)
{
    size_t i;

    i = 0;
    while(c[i])
        i++;
    return i;
}
/*int main()
{
    printf("%lu", ft_strlen("teste"));
}*/