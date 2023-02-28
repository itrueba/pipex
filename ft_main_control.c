/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_control.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itrueba- <itrueba-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:14:20 by itrueba-          #+#    #+#             */
/*   Updated: 2023/02/28 18:02:38 by itrueba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_check_files(t_pipex *pipex, char *file1, char *file2)
{
	pipex->in_fd = open(file1, O_RDONLY);
	if (pipex->in_fd < 0)
		ft_error_file(pipex, 0);
	pipex->out_fd = open(file2, O_CREAT | O_WRONLY | O_TRUNC,
			0660);
	if (pipex->out_fd < 0)
		ft_error_file(pipex, 1);
	return (1);
}

void	ft_command_list(t_pipex *pipex, char **argv)
{
	t_command	*command;
	int			count;

	count = 0;
	pipex->command = malloc(sizeof(t_command));
	while (count < pipex->argc)
	{
		command = ft_pipex_lstnew(argv[count], pipex);
		ft_pipex_lstadd_back(pipex->command, command);
		count++;
	}
}
