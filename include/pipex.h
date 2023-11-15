/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 12:09:38 by dabdygal          #+#    #+#             */
/*   Updated: 2023/11/15 14:22:44 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# define PARSE_ERR_MSG "parse error\n"

# include <unistd.h>

int		checkwarn(int argc, char *argv[]);
pid_t	fork_warn_clean(int fd[2], char *s);
int		pipe_warn(int fd[2], char *s);

#endif
