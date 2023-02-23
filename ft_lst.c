/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itrueba- <itrueba-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:03:26 by itrueba-          #+#    #+#             */
/*   Updated: 2023/02/23 16:06:25 by itrueba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_command(char *ptr)
{
	int	len;

	len = 0;
	while (ptr[len] && ptr[len] != ' ')
		len++;
	ptr[len] = 0;
	return (ptr);
}

t_command	*ft_pipex_lstlast(t_command *lst)
{
	if (lst)
		while (lst->next)
			lst = lst->next;
	return (lst);
}

void	ft_pipex_lstadd_back(t_command **lst, t_command *new)
{
	t_command	*last;

	if (lst)
	{
		if (*lst)
		{
			last = ft_pipex_lstlast(*lst);
			last->next = new;
		}
		else
			*lst = new;
	}
	free(new);
}

t_command	*ft_pipex_lstnew(char *content, t_pipex *pipex)
{
	t_command	*s_command;

	s_command = (t_command *)malloc(sizeof(*s_command));
	if (!s_command)
		return (NULL);
	s_command->content = content;
	s_command->command_path = ft_path(pipex, ft_command(content));
	s_command->next = NULL;
	return (s_command);
}
