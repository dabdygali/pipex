/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_warn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:01:05 by dabdygal          #+#    #+#             */
/*   Updated: 2023/11/15 14:22:05 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

pid_t	fork_warn_clean(int fd[2], char *s)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		perror(s);
		if (close(fd[0]) < 0)
			perror(s);
		if (close(fd[1]) < 0)
			perror(s);
	}
	return (pid);
}
