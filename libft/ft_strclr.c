/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiot-- <aguiot--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 19:48:06 by aguiot--          #+#    #+#             */
/*   Updated: 2018/11/26 15:02:10 by aguiot--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		ft_strclr(char *s)
{
	while (s && *s)
		*(s++) = 0;
}
