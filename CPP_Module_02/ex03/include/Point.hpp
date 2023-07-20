/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <jamrabhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 00:24:34 by jamrabhi          #+#    #+#             */
/*   Updated: 2023/07/20 00:24:40 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"
# include <iostream>

class Point
{
	public:
		Point();
		Point(Point const &src);
		Point(const float x, const float y);
		~Point();

		Point 	&operator=(Point const &rhs);

	private:
		Fixed const	_x;
		Fixed const	_y;
};

#endif
