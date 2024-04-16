/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 12:10:49 by joao-vri          #+#    #+#             */
/*   Updated: 2024/04/16 10:19:08 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_isprint(char c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

/*int main(void){
	int	a = ft_isprint('A');
	int	b = ft_isprint(12);

	printf("%i", a);
	printf("%i", b);
}*/
