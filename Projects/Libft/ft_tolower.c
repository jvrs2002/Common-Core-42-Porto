/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 12:04:27 by joao-vri          #+#    #+#             */
/*   Updated: 2024/04/15 13:48:39 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

unsigned char   ft_tolower(unsigned char c)
{
    if (c >= 65 && c <= 90)
        c += 32;
    return c;
}

/*int main (void)
{
    char c = 'A';
    printf("%c", ft_tolower(c));
}*/