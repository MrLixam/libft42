/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 20:16:40 by lvincent          #+#    #+#             */
/*   Updated: 2024/01/30 07:53:09 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (lst != NULL && del != NULL)
	{
		tmp = *lst;
		while (tmp != NULL)
		{
			tmp = tmp->next;
			ft_lstdelone(*lst, del);
			*lst = tmp;
		}
	}
}
