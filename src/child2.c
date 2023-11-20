/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:56:25 by dabdygal          #+#    #+#             */
/*   Updated: 2023/11/20 17:33:57 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "pipex.h"

static int	open_clean2(int *outfile, char *argv[], int fd)
{
	int	flag;

	flag = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
	*outfile = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, flag);
	if (*outfile < 0)
	{
		perror(argv[0]);
		if (close(fd) < 0)
			perror(argv[0]);
		return (-1);
	}
	return (0);
}

int	child2(int fd[2], char *argv[])
{
	int			outfile;
	extern char	**environ;
	char		*vector[2];
	char		*path;

	if (close_warn(fd[1], argv[0], -1) < 0)
		return (EXIT_FAILURE);
	if (open_clean2(&outfile, argv, fd[0]) < 0)
		return (EXIT_FAILURE);
	if (dup2_clean(outfile, STDOUT_FILENO, argv, fd[0]) < 0)
		return (EXIT_FAILURE);
	if (close_warn(outfile, argv[0], fd[0]) < 0)
		return (EXIT_FAILURE);
	if (dup2_clean(fd[0], STDIN_FILENO, argv, fd[0]) < 0)
		return (EXIT_FAILURE);
	if (close_warn(fd[0], argv[0], -1) < 0)
		return (EXIT_FAILURE);
	if (resolve_path(&path, argv[3], environ, argv[0]) < 0)
		return (EXIT_FAILURE);
	vector[0] = argv[3];
	vector[1] = NULL;
	if (execve(argv[3], vector, environ) < 0)
		perror(argv[0]);
	free(path);
	return (EXIT_FAILURE);
}
