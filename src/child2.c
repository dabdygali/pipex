/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:56:25 by dabdygal          #+#    #+#             */
/*   Updated: 2023/11/19 13:11:13 by dabdygal         ###   ########.fr       */
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
	outfile = open(argv[1], O_RDONLY);
	if (infile < 0)
	{
		perror(argv[0]);
		return (EXIT_FAILURE);
	}
	if (dup2(infile, STDIN_FILENO) < 0)
	{
		perror(argv[0]);
		return (EXIT_FAILURE);
	}
	vector[0] = argv[2];
	vector[1] = NULL;
	if (execve(argv[2], vector, environ) < 0)
		perror(argv[0]);
	return (EXIT_FAILURE);
}
