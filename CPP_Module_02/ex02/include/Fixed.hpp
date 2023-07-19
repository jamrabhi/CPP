/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 00:26:24 by jamrabhi          #+#    #+#             */
/*   Updated: 2023/07/12 00:26:29 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	public:
		Fixed();
		Fixed(Fixed const &src);
		Fixed(const int fixedValue);
		Fixed(const float fixedValue);
		~Fixed();

		Fixed 	&operator=(Fixed const &rhs);
		bool	operator>(Fixed const &rhs) const;
		bool	operator<(Fixed const &rhs) const;
		bool	operator>=(Fixed const &rhs) const;
		bool	operator<=(Fixed const &rhs) const;
		bool	operator==(Fixed const &rhs) const;
		bool	operator!=(Fixed const &rhs) const;
		Fixed	operator+(Fixed const &rhs) const;
		Fixed	operator-(Fixed const &rhs) const;
		Fixed	operator*(Fixed const &rhs) const;
		Fixed	operator/(Fixed const &rhs) const;
		Fixed	&operator++(void);
		Fixed	&operator--(void);
		Fixed	operator++(int);
		Fixed	operator--(int);

		int					getRawBits(void) const;
		void				setRawBits(int const raw);
		float				toFloat(void) const;
		int					toInt(void) const;
		static Fixed		&min(Fixed &a, Fixed &b);
		static const Fixed	&min(Fixed const &a, Fixed const &b);
		static Fixed		&max(Fixed &a, Fixed &b);
		static const Fixed	&max(Fixed const &a, Fixed const &b);

	private:
		int					_fixedValue;
		static const int 	_fractBits = 8;
};

std::ostream	&operator<<(std::ostream &o, Fixed const &rhs);

#endif
