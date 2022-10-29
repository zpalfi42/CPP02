#include "Fixed.hpp"

Fixed::Fixed( void ) : _n( 0 )
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Default constructor called" << std::endl;
	*this = fixed;
}

Fixed::Fixed( const float f): _n((int)roundf(f * (1 << _c)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed( int n ): _n(n << _c)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed	&Fixed::operator=(const Fixed &fixed)
{
	std::cout << "Assignation operator called" << std::endl;
	this->_n = fixed.getRawBits();
	return (*this);
}

std::ostream	&operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}

int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBIts member function called" << std::endl;
	return (this->_n);
}

void	Fixed::setRawBits( int raw )
{
	std::cout << "setRawBIts member function called" << std::endl;
	this->_n = raw;
}

int		Fixed::toInt( void ) const
{
	return ((int)(roundf((float)this->_n / (1 << this->_c))));
}

float	Fixed::toFloat( void ) const
{
	return((float)this->_n / (1 << this->_c));
}