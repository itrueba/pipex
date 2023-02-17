/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itrueba- <itrueba-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:14:20 by itrueba-          #+#    #+#             */
/*   Updated: 2023/02/17 14:14:46 by itrueba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


void ft_buffer(t_pipex	*pipex)
{
	int count;
	int temp;
	char *buffer;

	buffer = malloc(50 * sizeof(char));
	count = 0;
	temp = 1;
	while (temp)
	{
		temp = read(pipex->in_fd, buffer, 50);
		count += temp;
	}
	free(buffer);
	buffer = malloc(count * sizeof(char));
}

void ft_pipex(t_pipex	*pipex)
{
	pid_t pid;
	int fd[2];

	pipe(fd);
	pid = fork();
	ft_buffer(pipex);
	if (pid == 0)
	{
		close(fd[0]);
		printf("Hijo\n");
	}
	else
	{
		printf("Padre\n");
		exit (0);
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
		ft_pipex(pipex);
		ft_free(pipex);
	}
	return (0);
}
