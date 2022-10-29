#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
private:
	Fixed const _x;
	Fixed const _y;
public:
	Point( void );
	Point( const Point &point);
	Point( const float x, const float y );

	~Point( void );

	Point &operator=( Point &point );

	Fixed	getX( void ) const;
	Fixed	getY( void ) const;
};

std::ostream	&operator<<( std::ostream &out, const Point &point );

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif