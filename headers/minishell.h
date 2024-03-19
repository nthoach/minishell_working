/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthoach <nthoach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 21:00:19 by nthoach           #+#    #+#             */
/*   Updated: 2024/03/17 21:11:50 by nthoach          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef MINISHELL_H
# define MINISHELL_H
# define WELC_MSG	"starting minishell..."

# include <readline/readline.h>
# include <readline/history.h>
# include <stdbool.h>
# include <signal.h>
# include <libft.h>


typedef struct s_mnsh
{
	struct s_cmds	*cmds;
	char			*input;
	char			**envp;
	char			**paths;
	char			*pwd;
	char			*old_pwd;
	int				pipes;
	int				*pid;
	bool			reset;
	bool			heredoc;
}	t_mnsh;


#endif