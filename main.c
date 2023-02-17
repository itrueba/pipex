/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itrueba- <itrueba-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:14:20 by itrueba-          #+#    #+#             */
/*   Updated: 2023/02/17 13:03:11 by itrueba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(t_pipex *pipex)
{
	write(1, "Error.\n", 7);
	ft_free(pipex);
}

static int	ft_check_files(t_pipex *pipex)
{
	pipex->in_fd = open(pipex->argv->archivo1, O_RDONLY);
	if (pipex->in_fd < 0)
		ft_error(pipex);
	pipex->out_fd = open(pipex->argv->archivo2,
							O_CREAT | O_WRONLY | O_TRUNC,
							0660);
	if (pipex->out_fd < 0)
		ft_error(pipex);
	return (1);
}

void	ft_command_list(t_pipex *pipex, char **argv)
{
	while (*(argv + 1))
	{
		ft_pipex_lstadd_back(&pipex->argv->command,
								ft_pipex_lstnew(*argv));
		argv++;
	}
}

int	main(int argc, char **argv)
{
	t_pipex	*pipex;

	if (argc == 5)
	{
		pipex = malloc(sizeof(t_pipex));
		pipex->argv = malloc(sizeof(t_argv));
		pipex->argv->archivo1 = argv[1];
		pipex->argv->archivo2 = argv[argc - 1];
		ft_command_list(pipex, &argv[2]);
		ft_check_files(pipex);
		ft_free(pipex);
	}
	return (0);
}
