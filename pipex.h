/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PIPEX.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itrueba- <itrueba-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:47:45 by itrueba-          #+#    #+#             */
/*   Updated: 2023/02/16 11:46:22 by itrueba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "Libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_argv
{
	char			*archivo1;
	char			*comando1;
	char			*comando2;
	char			*archivo2;
}					t_argv;

typedef struct s_pipex
{
	struct s_argv	*argv;
	int				in_fd;
	int				out_fd;
}					t_pipex;

#endif