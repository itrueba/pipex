/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itrueba- <itrueba-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:14:20 by itrueba-          #+#    #+#             */
/*   Updated: 2023/02/13 18:16:25 by itrueba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
/*
open, close, read, write,
malloc, free, perror,
strerror, access, dup, dup2,
execve, exit, fork, pipe,
unlink, wait, waitpid
*/


static int	ft_check_files(t_pipex *pipex)
{
	pipex->in_fd = open(pipex->argv->archivo1, O_RDONLY);
	pipex->out_fd = open(pipex->argv->archivo2, \
		O_CREAT | O_WRONLY | O_TRUNC, 0660);
	if (pipex->in_fd == -1)
	{
		perror("");
		return (0);
	}
	return (1);
}git 


int	main(int argc, char **argv)
{
	t_pipex	*pipex;

	if (argc == 5)
	{
		pipex = malloc(sizeof(t_pipex));
		pipex->argv->archivo1 = argv[1];
		pipex->argv->archivo2 = argv[2];
		pipex->argv->comando1 = argv[3];
		pipex->argv->comando2 = argv[4];
		ft_check_files(pipex);
		free(pipex);
	}
	return (0);
}