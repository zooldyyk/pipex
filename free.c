/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmid <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 14:47:45 by eschmid           #+#    #+#             */
/*   Updated: 2022/11/28 14:49:43 by eschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_pipes(t_pipex *pipex)
{
	close(pipex->pipe[0]);
	close(pipex->pipe[1]);
}

void	free_parent( t_pipex *pipex)
{
	int	i;

	i = -1;
	close(pipex->infile);
	close (pipex->outfile);
	while (pipex->cmd_paths[++i])
		free(pipex->cmd_paths[i]);
	free(pipex->cmd_paths);
}

void	free_child(t_pipex *pipex)
{
	int	i;

	i = -1;
	while (pipex->cmd_args[++i])
		free(pipex->cmd_args[i]);
	free (pipex->cmd_args);
	free (pipex->cmd);
}
