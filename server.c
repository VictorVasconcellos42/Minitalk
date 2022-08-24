/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 18:16:50 by vde-vasc          #+#    #+#             */
/*   Updated: 2022/08/23 22:00:30 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	check_signal(int sig)

{
	static int	bin;
	static char chr;

	if (bin < 8)
	{
		if (sig == SIGUSR1)
			chr += (1 << (7 - bin));
		bin++;
	}
	if (bin == 8)
	{
		ft_printf("%c", chr);
		chr = 0;
		bin = 0;
	}
}

int	main(void)

{
	//struct sigaction sa;
	int pid;

	pid = getpid();
	
	ft_printf("Server PID: %i\n", pid);
	//sa.sa_handler = &check_signal;
	signal(SIGUSR1, check_signal);
	signal(SIGUSR2, check_signal);
	while (1)
	{
		pause();
		//sigaction(SIGUSR1, &sa, NULL);
		//sigaction(SIGUSR2, &sa, NULL);
	}
}
