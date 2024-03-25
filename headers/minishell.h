/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthoach <nthoach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 21:00:19 by nthoach           #+#    #+#             */
/*   Updated: 2024/03/25 20:45:46 by nthoach          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef MINISHELL_H
# define MINISHELL_H
# define WELC_MSG	"starting minishell..."

# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdbool.h>
# include <signal.h>
# include <fcntl.h>
# include <../libft/libft.h>

int	g_state; // global variable to show the status

typedef enum s_all_state
{
	CMD_IN = 20,
	HEREDOC_STOP = 1,
	HEREDOC_IN = 40,
	CTRL_C = 130,
	CTRL_BS = 131,
} t_all_state;

typedef struct s_mnsh
{
	struct s_cmd	*cmd;
	char			*input;
	char			**envp;
	char			**path;
	char			*pwd;
	char			*old_pwd;
	int				pipe;
	int				*pid;
	bool			reset;
	bool			heredoc;
}	t_mnsh;

typedef struct s_redir
{
	char			*path;
	int				type;
	int				fd;
	struct s_redir	*next;
	struct s_redir	*prev;
}	t_redir;

typedef struct s_cmd
{
	char			*cmd;
	char			*arg;
	t_redir			*redirect;
	struct s_cmd	*next;
	int				(*builtin)(t_mnsh *, struct s_cmd *);
	struct s_cmd	*prev;
	char			*h_filename;
}	t_cmd;

#endif