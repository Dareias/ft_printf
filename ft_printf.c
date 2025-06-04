/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fillip <fillip@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 00:50:19 by fillip            #+#    #+#             */
/*   Updated: 2025/06/04 04:51:12 by fillip           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "libft.h"
#include "ft_printf.h"
/*
hh - char, unsigned char argument
h - short, unsigned short argument
l - long, unsigned long argument
ll - long long, unsigned long long argument
L - a, A, e, E, f, F, g, G long double argument
j - intmax_t uintmax_t argument
z - size_t ssize_t argument
t - ptrdiff_t argument
*/

/*
d, i - int to signed decimal
o, u, x, X - unsigned int to octal, unsigned decimal, hexadecimal
e, E - d.ddde+-dd, exponent, precision spec
f, F - ddd.ddd, precision spec
g, G - wtf?
a, A - hexadecimal something ?
c - if no l modifier, convert int to unsigned char, if l then some multibyte shit
s - if no l, const char * expected as pointer to array, if precision then do special stuff
p - void * to hexadecimal
n - number of characters stored to int pointed to by argument
m - glibc, errno output
*/

typedef struct s_spec
{
	char	spec;
	int (*printer)(va_list, t_format *);
}	t_spec;

static const t_spec g_spec[] = 
{
	{'c', print_char},
	{'s', print_str},
	{'p', print_ptr},
	{'d', print_num},
	{'i', print_num},
	{'u', print_uns},
	{'x', print_lhex},
	{'X', print_uhex},
	{0, NULL}
};

int	ft_printf(const char *restrict format, ...)
{
	va_list	args;
	int		printed;

	va_start(args, format);
	printed = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			t_format f = {0};
			parse_flags
			parse_width
			parse_prec
			const t_spec *spec = find_spec(*format);
			if (spec)
				printed += spec->printer(args, &f);
			else
			{
				write(1, format - 1, 1);
				write(1, format, 1);
				printed += 2;
			}
		}
		else
		{
			write(1, format, 1);
			printed++;
		}
		format++;
	}
	va_end(args);
	return (printed);
}
