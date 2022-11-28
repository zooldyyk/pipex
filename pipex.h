/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmid <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 14:50:01 by eschmid           #+#    #+#             */
/*   Updated: 2022/11/28 15:19:20 by eschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./libft/libft.h"
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <errno.h>

typedef struct s_pipex
{
	pid_t	pid1;
	pid_t	pid2;
	int		pipe[2];
	int		infile;
	int		outfile;
	char	*paths;
	char	**cmd_paths;
	char	**cmd_args;
	char	*cmd;
}t_pipex;

void	child1(t_pipex pipex, char *av[], char *envp[]);
void	child2(t_pipex pipex, char *av[], char *envp[]);
void	close_pipes(t_pipex *pipex);
void	free_parent( t_pipex *pipex);
void	free_child(t_pipex *pipex);
char	*get_path(char **envp);
char	*get_cmd(char **paths, char *cmd);
int		msg(char *err);

#endif
