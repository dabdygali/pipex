/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:56:25 by dabdygal          #+#    #+#             */
/*   Updated: 2023/11/19 14:19:34 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

int	child2(int fd[2], char *argv[])
{
	int			outfile;
	extern char	**environ;
	char		*vector[2];

	if (close(fd[1]) < 0)
	{
		perror(argv[0]);
		return (EXIT_FAILURE);
	}
	outfile = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (outfile < 0)
	{
		perror(argv[0]);
		return (EXIT_FAILURE);
	}
	if (dup2(outfile, STDOUT_FILENO) < 0)
	{
		perror(argv[0]);
		return (EXIT_FAILURE);
	}
	if (dup2(fd[0], STDIN_FILENO) < 0)
	{
		perror(argv[0]);
		return (EXIT_FAILURE);
	}
	vector[0] = argv[3];
	vector[1] = NULL;
	if (execve(argv[3], vector, environ) < 0)
		perror(argv[0]);
	return (EXIT_FAILURE);
}
