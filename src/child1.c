/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:56:25 by dabdygal          #+#    #+#             */
/*   Updated: 2023/11/20 17:35:50 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "pipex.h"
#include "libft.h"

void	free_vector(char **vector)
{
	char	**tmp;

	tmp = vector;
	while (*tmp)
	{
		free(*tmp);
		tmp++;
	}
	free(vector);
}

static int	open_clean1(int *infile, char *argv[], int fd)
{
	*infile = open(argv[1], O_RDONLY);
	if (*infile < 0)
	{
		perror(argv[0]);
		if (close(fd) < 0)
			perror(argv[0]);
		return (-1);
	}
	return (0);
}

int	dup2_clean(int dup, int new, char *argv[], int fd)
{
	if (dup2(dup, new) < 0)
	{
		perror(argv[0]);
		if (close(fd) < 0)
			perror(argv[0]);
		return (-1);
	}
	return (0);
}

static int	setup1(int fd[2], char *argv[], int *infile)
{
	if (close_warn(fd[0], argv[0], -1) < 0)
		return (-1);
	if (open_clean1(infile, argv, fd[1]) < 0)
		return (-1);
	if (dup2_clean(*infile, STDIN_FILENO, argv, fd[1]) < 0)
		return (-1);
	if (close_warn(*infile, argv[0], fd[1]) < 0)
		return (-1);
	if (dup2_clean(fd[1], STDOUT_FILENO, argv, fd[1]) < 0)
		return (-1);
	if (close_warn(fd[1], argv[0], -1) < 0)
		return (-1);
	return (0);
}

int	child1(int fd[2], char *argv[])
{
	int			infile;
	extern char	**environ;
	char		**vector;
	char		*path;

	if (setup1(fd, argv, &infile) < 0)
		return (EXIT_FAILURE);
	vector = ft_split_wspace(argv[2]);
	if (!vector)
	{
		perror(argv[0]);
		return (EXIT_FAILURE);
	}
	if (resolve_path(&path, vector[0], environ, argv[0]) < 0)
	{
		free_vector(vector);
		return (EXIT_FAILURE);
	}
	if (execve(path, vector, environ) < 0)
		perror(argv[0]);
	free_vector(vector);
	free(path);
	return (EXIT_FAILURE);
}
