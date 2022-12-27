/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 18:17:41 by vde-vasc          #+#    #+#             */
/*   Updated: 2022/12/26 17:32:09 by dmatavel         ###   ########.fr       */
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

/*
** The first if checks if there's an argv[1] before calling ft_atoi.
** If the program tries to call ft_atoi with an argument that doesn't exists
** it'll get segfault; The second if  prevents the user from passing
** an non-numerical argument in the PID's placeholder, what could lead
** to an undefined behavior.
*/

int	check_invalid_pid(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (!ft_isdigit(argv[i]))
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	int	pid;
	int	i;

	if (argc != 3)
	{
		ft_printf("Number of arguments invalid!");
		exit(EXIT_FAILURE);
	}
	if (check_invalid_pid(argv[1]))
	{
		ft_printf("PIDs are composed of digits only.\n");
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(argv[1]);
	i = 0;
	while (argv[2][i])
	{
		transl_char_bit(pid, argv[2][i]);
		i++;
	}
	return (0);
}
