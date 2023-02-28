/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itrueba- <itrueba-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:14:20 by itrueba-          #+#    #+#             */
/*   Updated: 2023/02/28 18:15:00 by itrueba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;

	if (argc > 2)
	{
		pipex = malloc(sizeof(t_pipex));
		ft_check_files(pipex, argv[1], argv[argc - 1]);
		pipex->argc = argc - 3;
		pipex->envp = ft_split(ft_find_path(envp), ':');
		ft_command_list(pipex, &argv[2]);
		ft_pipex(pipex);
		ft_free(pipex);
	}
	return (0);
}
