/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_control.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itrueba- <itrueba-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:14:20 by itrueba-          #+#    #+#             */
/*   Updated: 2023/02/22 16:03:13 by itrueba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_check_files(t_pipex *pipex)
{
	pipex->in_fd = open(pipex->argv->archivo1, O_RDONLY);
	if (pipex->in_fd < 0)
		ft_error(pipex);
	pipex->out_fd = open(pipex->argv->archivo2, O_CREAT | O_WRONLY | O_TRUNC,
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
