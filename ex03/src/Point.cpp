#include "Point.hpp"

Point::Point( void ): _x(Fixed()), _y(Fixed())
{
}

Point::Point( const Point &point): _x(point._x), _y(point._y)
{
}

Point::Point(const float x, const float y): _x(Fixed(x)), _y(Fixed(y))
{

}

Point::~Point( void )
{

}

Point &Point::operator=( Point &point )
{
	this->~Point();
	new(this) Point(point._x.toFloat(), point._y.toFloat());
	return (*this);
}

Fixed	Point::getX( void ) const
{
	return (this->_x);
}

Fixed	Point::getY( void ) const
{
	return (this->_y);
}

std::ostream	&operator<<( std::ostream &out, const Point &point )
{
	out << point.getX();
	return (out);
}
