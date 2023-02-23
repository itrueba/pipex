/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itrueba- <itrueba-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:14:20 by itrueba-          #+#    #+#             */
/*   Updated: 2023/02/23 15:29:25 by itrueba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;

	if (argc > 2)
	{
		pipex = malloc(sizeof(t_pipex));
		pipex->argc = argc - 3;
		pipex->archivo1 = argv[1];
		pipex->archivo2 = argv[argc - 1];
		pipex->envp = ft_split(ft_find_path(envp), ':');
		pipex->command = malloc(sizeof(t_command));
		ft_command_list(pipex, &argv[2]);
		ft_check_files(pipex);
		ft_free(pipex);
	}
	return (0);
}
