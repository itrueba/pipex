/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itrueba- <itrueba-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:29:06 by itrueba-          #+#    #+#             */
/*   Updated: 2023/03/01 16:31:28 by itrueba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_child_one(t_pipex *pipex)
{
	close(pipex->fd[READ_END]);
	dup2(pipex->fd[WRITE_END], STDOUT_FILENO);
	close(pipex->fd[WRITE_END]);
	execve((*pipex->command)->command_path, (*pipex->command)->content,
		pipex->envp);
}

void	ft_child_two(t_pipex *pipex)
{
	dup2(pipex->fd[READ_END], STDIN_FILENO);
	close(pipex->fd[READ_END]);
	dup2(pipex->out_fd, STDOUT_FILENO);
	execve((*pipex->command)->next->command_path,
		(*pipex->command)->next->content,
		pipex->envp);
}

void	ft_pipex(t_pipex *pipex)
{
	pid_t	pid;

	dup2(pipex->in_fd, STDIN_FILENO);
	close(pipex->in_fd);
	pipe(pipex->fd);
	pid = fork();
	if (pid == 0)
		ft_child_one(pipex);
	else
	{
		close(pipex->fd[WRITE_END]);
		pid = fork();
		if (pid == 0)
			ft_child_two(pipex);
		else
			close(pipex->fd[READ_END]);
	}
}
