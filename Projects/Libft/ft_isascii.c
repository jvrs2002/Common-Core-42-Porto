/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 11:47:05 by joao-vri          #+#    #+#             */
/*   Updated: 2024/04/11 12:10:16 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int ft_isascii(char c){
    if (c >= 0 && c <= 122)
        return 1;
    return 0;
}

/*int main(void){
    int a = ft_isascii('a');
    int b = ft_isascii(123);

    printf("%i\n", a);
    printf("%i", b);
}*/