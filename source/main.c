/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng <hheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:51:36 by nchok             #+#    #+#             */
/*   Updated: 2024/10/28 16:16:27 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

/*
	@brief
	- compare both string
	@return
	- return 1 if exactly same string
	- return 0 if not same string
	@error handling
	- can't compare null string
*/
int		same_str(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[i] && s2[i])
	{
		if (s1[i] == s2[i])
			i++;
		else
			return (0);
	}
	if (!s1[i] && !s2[i])
		return (1);
	else
		return (0);
}

int main(int ac, char **av, char **envp)
{
	t_general	utils;

	if (ac != 1 || av[1] != NULL)
	{
		ft_putendl_fd("Program does not accept arguments", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	// print_welcome();
	process_envp(envp, &utils);
	start_shell(&utils);
	return (0);
}
