/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 12:09:38 by dabdygal          #+#    #+#             */
/*   Updated: 2023/11/20 17:31:21 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# define PARSE_ERR_MSG "parse error\n"

# include <unistd.h>

int		checkwarn(int argc, char *argv[]);
pid_t	fork_warn_clean(int fd[2], char *s);
int		pipe_warn(int fd[2], char *s);
int		parent(int fd[2], pid_t pid[2], char *s);
int		child1(int fd[2], char *argv[]);
int		child2(int fd[2], char *argv[]);
int		close_warn(int fd, char *s, int x);
int		dup2_clean(int infile, int new, char *argv[], int fd);
int		resolve_path(char **path, char *s, char **env, char *name);
void	free_vector(char **vector);

#endif
