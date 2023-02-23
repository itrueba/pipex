/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itrueba- <itrueba-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:05:05 by itrueba-          #+#    #+#             */
/*   Updated: 2023/02/23 15:34:20 by itrueba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_path(t_pipex *pipex, char **command)
{
	const char	*slash;
	char		*path;
	char		*path_command;
	int			count;

	slash = "/";
	count = 0;
	while (pipex->envp[count])
	{
		path = ft_strjoin(pipex->envp[count], slash);
		free(path);
		path_command = ft_strjoin(path, *command);
		ft_split_free(command);
		if (access(path_command, F_OK) == 0)
			return (path_command);
		free(path_command);
		count++;
	}
	return ("Mal");
}

char	*ft_find_path(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}
