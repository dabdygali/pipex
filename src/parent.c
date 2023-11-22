/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:04:30 by dabdygal          #+#    #+#             */
/*   Updated: 2023/11/20 10:57:07 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int	parent(int fd[2], pid_t pid[2], char *s)
{
	int	status;

	status = EXIT_FAILURE;
	if (close(fd[1]) < 0)
		perror(s);
	if (close(fd[0]) < 0)
		perror(s);
	if (waitpid(pid[0], NULL, WUNTRACED) < 0)
		perror(s);
	if (waitpid(pid[1], &status, WUNTRACED) < 0)
		perror(s);
	return (WEXITSTATUS(status));
}
