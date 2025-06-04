/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fillip <fillip@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 18:41:25 by fillip            #+#    #+#             */
/*   Updated: 2025/05/31 12:56:43 by fillip           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>

typedef struct s_format
{
	char	type;
	int		minus;
	int		plus;
	int		space;
	int		hash;
	int		zero;
	int		width;
	int		dot;
	int		prec;
} t_format;

typedef int (*t_print)(va_list args, t_format *f);

typedef struct s_spec
{
	char	spec;
	t_print	func;
} t_spec;


#endif