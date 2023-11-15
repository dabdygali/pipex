/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkwarn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:32:44 by dabdygal          #+#    #+#             */
/*   Updated: 2023/11/15 10:27:24 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pipex.h"
#include <stdio.h>
#include <errno.h>

int	checkwarn(int argc, char *argv[])
{
	if (argc != 5)
	{
		errno = EINVAL;
		perror(argv[0]);
		return (0);
	}
	return (1);
}
