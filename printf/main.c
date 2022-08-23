/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 08:34:43 by vde-vasc          #+#    #+#             */
/*   Updated: 2022/07/14 18:19:47 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	main(void)

{
	//int len = ft_printf("Victor%s%d\n", "Victor", 10);
	int len = ft_printf("%x", 155);
//	ft_putchar('\n');
	int len2 = printf("%x", 155);

	printf("\n%d\toriginal:%d", len, len2);
	return 0;
}
