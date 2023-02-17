/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itrueba- <itrueba-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:03:26 by itrueba-          #+#    #+#             */
/*   Updated: 2023/02/17 12:25:53 by itrueba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

	if (*lst)
	{
		last = ft_pipex_lstlast(*lst);
		last->next = new;
	}
	else
		*lst = new;
}

t_command	*ft_pipex_lstnew(char *content)
{
	t_command	*s_command;

	s_command = (t_command *)malloc(sizeof(*s_command));
	if (!s_command)
		return (NULL);
	s_command->content = content;
	s_command->next = NULL;
	return (s_command);
}
