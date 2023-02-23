/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itrueba- <itrueba-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:14:20 by itrueba-          #+#    #+#             */
/*   Updated: 2023/02/23 15:33:14 by itrueba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_split_free(char **split)
{
	char	*temp_split;

	while (split)
	{
		temp_split = *split;
		free(temp_split);
		split++;
	}
	free(split);
}

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
		free(command);
		command = temp_command->next;
	}
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
