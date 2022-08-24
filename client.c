/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 18:17:41 by vde-vasc          #+#    #+#             */
/*   Updated: 2022/08/23 23:40:24 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	transl_char_bit(int pid, char sign)

{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (sign & (1 << i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(200);
		i--;
	}
}

int	main(int argc, char *argv[])

{
	int	pid;
	int	i;

	i = 0;
	pid = ft_atoi(argv[1]);
	if (argc == 3)
	{
		while (argv[2][i])
		{
			transl_char_bit(pid, argv[2][i]);
			i++;
		}
	}
	else
		ft_printf("Number of arguments invalid!");
	return (0);
}
