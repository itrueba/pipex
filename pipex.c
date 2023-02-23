/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itrueba- <itrueba-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:29:06 by itrueba-          #+#    #+#             */
/*   Updated: 2023/02/23 15:29:09 by itrueba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_pipex(t_pipex *pipex)
{
	pid_t	pid;

	dup2(pipex->in_fd, STDIN_FILENO);
	close(pipex->in_fd);
	pipe(pipex->fd);
	pid = fork();
	if (pid == 0)
	{
		close(pipex->fd[WRITE_END]);
		dup2(pipex->fd[1], STDOUT_FILENO);
		close(pipex->fd[1]);
	}
	else
	{
		close(pipex->fd[WRITE_END]);
		pid = fork();
		//pipex->argv->command++;
		if (pid == 0)
		{
			close(pipex->fd[WRITE_END]);
			dup2(pipex->fd[READ_END], STDIN_FILENO);
			close(pipex->fd[READ_END]);
			dup2(pipex->out_fd, STDOUT_FILENO);
		}
		else
		{
			close(pipex->fd[READ_END]);
		}
	}
}