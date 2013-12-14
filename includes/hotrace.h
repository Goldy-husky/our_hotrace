/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 23:48:37 by cmehay            #+#    #+#             */
/*   Updated: 2013/12/14 02:08:38 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H

# include "get_next_line.h"

# define TABLESIZE 263167
# define ROTATE_X 5
# define ROTATE_Y 2

typedef enum	e_bool
{
	FALSE,
	TRUE
}				t_bool;

typedef struct	s_keyword
{
	int					key;
	char				*value;
	struct s_keyword	*next;
}				t_keyword;

#endif
