/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itrueba- <itrueba-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:14:20 by itrueba-          #+#    #+#             */
/*   Updated: 2023/02/23 16:05:41 by itrueba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free(t_pipex *pipex)
{
	t_command	*temp_command;
	t_command	*command;
	char		**envp;
	char		*temp_envp;

	command = *(pipex->command);
	envp = pipex->envp;
	while (command)
	{
		temp_command = command;
		free(command->command_path);
		command = temp_command->next;
	}
	free(command);
	while (*envp)
	{
		temp_envp = *envp;
		free(temp_envp);
		envp++;
	}
	free(pipex->envp);
	free(pipex->command);
	free(pipex);
	exit(0);
}
