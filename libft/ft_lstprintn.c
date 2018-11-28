/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprintn.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiot-- <aguiot--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 12:21:19 by aguiot--          #+#    #+#             */
/*   Updated: 2018/11/24 12:23:30 by aguiot--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstprintn(t_list const *list, size_t n)
{
	while (list && n--)
	{
		ft_putchar('[');
		ft_putstr(list->content);
		ft_putchar(']');
		ft_putchar('(');
		ft_putnbr(list->content_size);
		ft_putchar(')');
		list = list->next;
		if (list && n)
			ft_putstr("-->");
	}
}
