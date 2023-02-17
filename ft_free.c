/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itrueba- <itrueba-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:14:20 by itrueba-          #+#    #+#             */
/*   Updated: 2023/02/17 13:02:26 by itrueba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free(t_pipex *pipex)
{
	t_command	*temp;

	write(1, "Clean.\n", 7);
	while (pipex->argv->command)
	{
		temp = pipex->argv->command->next;
		free(pipex->argv->command);
		pipex->argv->command = temp;
	}
	free(pipex->argv);
	free(pipex);
	exit(0);
}
