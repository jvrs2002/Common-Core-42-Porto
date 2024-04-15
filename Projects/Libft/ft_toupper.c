/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:22:24 by joao-vri          #+#    #+#             */
/*   Updated: 2024/04/15 13:48:29 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

unsigned char   ft_toupper(unsigned char c)
{
    if (c >= 97 && c <= 122)
        c -= 32;
    return c;
}

/*int main (void)
{
    char c = 'a';
    printf("%c", ft_toupper(c));
}*/