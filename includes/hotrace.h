/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 23:48:37 by cmehay            #+#    #+#             */
/*   Updated: 2013/12/15 00:03:36 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H

# include <stdint.h>
# include "get_next_line.h"

# define TABLESIZE 263167
# define ROTATE_X 0
# define ROTATE_Y 2


typedef enum		e_bool
{
	FALSE,
	TRUE
}					t_bool;

typedef struct		s_keyword
{
	t_hash				key;
	char				*value;
	struct s_keyword	*next;
}					t_keyword;

typedef uint32_t	t_hash;

/*
** CRC32
*/
typedef uint8_t		t_crc;
# define POLY 0xD8
# define WIDTH  (8 * sizeof(crc))
# define TOPBIT (1 << (WIDTH - 1))
# define REDUCE 24


t_keyword	*hr_keyword_lstadd(t_keyword *keyword, int key, const char *value);
void		hr_keyword_lstchg(t_keyword *keyword, int key, const char *value);
void		hr_keyword_lstdel(t_keyword *keyword);



#endif
