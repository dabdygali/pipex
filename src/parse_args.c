/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 12:05:27 by dabdygal          #+#    #+#             */
/*   Updated: 2023/11/11 13:11:00 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pipex.h"
#include <unistd.h>
#include <fcntl.h>

int	parse_args(int argc, char *argv[])
{
	if (argc != 5)
	{
		ft_putstr_fd(PARSE_ERR_MSG, STDERR_FILENO);
		return (-1);
	}
}
