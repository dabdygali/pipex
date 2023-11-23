/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:16:03 by dabdygal          #+#    #+#             */
/*   Updated: 2023/11/23 15:12:10 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "libft.h"

int	main(int argc, char *argv[])
{
	pid_t	pid[2];
	int		fd[2];

	pid[1] = -1;
	if (argc == 1 || !checkwarn(argc, argv))
		return (EXIT_FAILURE);
	if (pipe_warn(fd, argv[0]) < 0)
		return (EXIT_FAILURE);
	pid[0] = fork_warn_clean(fd, argv[0]);
	if (pid[0] < 0)
		return (EXIT_FAILURE);
	if (pid[0] > 0)
	{
		pid[1] = fork_warn_clean(fd, argv[0]);
		if (pid[1] < 0)
			return (EXIT_FAILURE);
	}
	if (pid[1] > 0)
		return (parent(fd, pid, argv[0]));
	if (pid[0] == 0)
		return (child1(fd, argv));
	if (pid[1] == 0)
		return (child2(fd, argv));
}
