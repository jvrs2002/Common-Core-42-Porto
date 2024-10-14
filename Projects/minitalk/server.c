/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 18:36:39 by joao-vri          #+#    #+#             */
/*   Updated: 2024/10/14 18:45:11 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>



// void printCharAsBinaryVer2(char c){
//     int bit_index;
//     for (bit_index = __CHAR_BIT__; bit_index >= 0; --bit_index)
//     {
//         int bit = ( unsigned int ) (c >> bit_index) & 1;
//         printf("%d", bit);
//     }
// }

int	main(void)
{
	printf("Server's PID: %i\n", getpid()); //This will print the server's PID
	// while (1)
	// {

	// }
	printf("%i", bin_converter('D'));
	//printf("%i", bin_converter('d'));
	// printCharAsBinaryVer2('f');
}
