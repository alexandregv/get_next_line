/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiot-- <aguiot--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 11:11:23 by aguiot--          #+#    #+#             */
/*   Updated: 2018/11/24 11:27:30 by aguiot--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstprint(t_list const *list)
{
	while (list)
	{
		ft_putchar('[');
		ft_putstr(list->content);
		ft_putchar(']');
		ft_putchar('(');
		ft_putnbr(list->content_size);
		ft_putchar(')');
		list = list->next;
		if (list)
			ft_putstr("-->");
	}
}
