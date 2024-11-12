/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchok <nchok@student.42kl..edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:30:15 by nchok             #+#    #+#             */
/*   Updated: 2024/11/12 17:54:20 by nchok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../header/minishell.h"

/*
	@brief
		return the index of character after dollar sign
		return 0 if dollar sign is not found
	
*/
size_t	find_dollar(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$') // check if current char is '$'
			return (i + 1); // return the index of the char after '$'
		i++;
	}
	return (i);
}

/*
	@brief
		1. 
		2. return the length of the exit status (in ascii) + 1
		e.g -> 123 -> 3 + 1 = 4
*/
int	replace_question_mark(t_general *utils, char **tmp)
{
	int	len;

	len = 0;
	free(*tmp); // free the old str memory
	*tmp = ft_itoa(utils->exit_status); // convert the exit status to string
	len = ft_strlen(*tmp); // get the length of the new str
	return (len + 1); // return the length of the new str
}

/*
	@brief
	1. return the index of the equal sign + 1
	2. return 0 if equal sign is not found
*/
int	get_equal_sign_index(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (i + 1);
		i++;
	}
	return (0);
}
