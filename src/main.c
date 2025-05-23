/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzamolo- <rzamolo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 12:13:18 by rzamolo-          #+#    #+#             */
/*   Updated: 2025/05/23 12:52:48 by rzamolo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	main(int argc, char **argv)
{
	char	*input;
	(void)argc;
	(void)argv;
	while (1)
	{
		input = readline(PROMPT);
		if (!input)
			break ;
		if (*input != '\0')
			add_history(input);
		printf("%s\n",input);
		free(input);
	}
	return (0);
}