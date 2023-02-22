/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itrueba- <itrueba-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:47:45 by itrueba-          #+#    #+#             */
/*   Updated: 2023/02/22 15:52:44 by itrueba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "Libft/libft.h"
# include <fcntl.h>
# include <stdio.h>

# define READ_END 0
# define WRITE_END 1

typedef struct s_command
{
	char const			*content;
	struct s_command	*next;

}						t_command;

typedef struct s_argv
{
	struct s_command	*command;
	char				*archivo1;
	char				*archivo2;
	char				**envp;
}						t_argv;

typedef struct s_pipex
{
	struct s_argv		*argv;
	int					in_fd;
	int					out_fd;
	int					fd[2];
	char				**command;
}						t_pipex;

void					ft_free(t_pipex *pipex);
void					ft_error(t_pipex *pipex);

void					ft_command_list(t_pipex *pipex, char **argv);
int						ft_check_files(t_pipex *pipex);

void					ft_pipex_lstadd_back(t_command **lst, t_command *new);
t_command				*ft_pipex_lstnew(char *content);

#endif