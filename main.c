/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itrueba- <itrueba-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:14:20 by itrueba-          #+#    #+#             */
/*   Updated: 2023/02/22 16:30:31 by itrueba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_command(t_pipex *pipex)
{
	const char	*slash;
	char		*ptr;
	int			count;

	slash = "/";
	while (pipex->argv->command->content)
	{
		
		count = 0;
		while (pipex->argv->envp[count])
		{
			printf("%s\n", pipex->argv->envp[count]);
			ptr = ft_strjoin(ft_strjoin(*pipex->argv->envp[count], slash),
								*ft_split(pipex->argv->command->content, ' '));
			if (access(ptr, F_OK) == 0)
			{
				printf("%s\n", ptr);
				break ;
			}
			count++;
		}
		pipex->argv->command++;
	}
}

char	*ft_find_path(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

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
		pipex->argv->command++;
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

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;

	if (argc > 2)
	{
		pipex = malloc(sizeof(t_pipex));
		pipex->argv = malloc(sizeof(t_argv));
		pipex->argv->archivo1 = argv[1];
		pipex->argv->archivo2 = argv[argc - 1];
		pipex->argv->envp = ft_split(ft_find_path(envp), ':');
		ft_command_list(pipex, &argv[2]);
		ft_check_files(pipex);
		ft_command(pipex);
		//ft_pipex(pipex);
		//ft_free(pipex);
	}
	return (0);
}
