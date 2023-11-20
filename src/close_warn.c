/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_warn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:01:49 by dabdygal          #+#    #+#             */
/*   Updated: 2023/11/20 14:18:07 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	close_warn(int fd, char *s, int x)
{
	if (close(fd) < 0)
	{
		perror(s);
		if (x >= 0)
		{
			if (close(x) < 0)
				perror(s);
		}
		return (-1);
	}
	return (0);
}
