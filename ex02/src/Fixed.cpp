#include "Fixed.hpp"

/*
*	CONSTRUCTORS
*/

Fixed::Fixed( void ) : _n( 0 )
{
}

Fixed::Fixed(const Fixed &fixed)
{
	*this = fixed;
}

Fixed::Fixed( const float f): _n((int)roundf(f * (1 << _c)))
{
}

Fixed::Fixed( int n ): _n(n << _c)
{
}

/*
*	DESTRUCTORS
*/

Fixed::~Fixed( void )
{
}

/*
*	OPERATORS
*/

Fixed	&Fixed::operator=(const Fixed &fixed)
{
	this->_n = fixed.getRawBits();
	return (*this);
}

Fixed	Fixed::operator+( const Fixed &fixed1 ) const
{
	return (Fixed(fixed1.toFloat() + this->toFloat()));
}

Fixed	Fixed::operator-( const Fixed &fixed1 ) const
{
	return (Fixed(fixed1.toFloat() - this->toFloat()));
}

Fixed	Fixed::operator*( const Fixed &fixed1 ) const
{
	return (Fixed(fixed1.toFloat() * this->toFloat()));
}

Fixed	Fixed::operator/( const Fixed &fixed1 ) const
{
	return (Fixed(fixed1.toFloat() / this->toFloat()));
}

bool	Fixed::operator>( const Fixed &fixed1 ) const
{
	return (this->toFloat() > fixed1.toFloat());
}
bool	Fixed::operator<( const Fixed &fixed1 ) const
{
	return (this->toFloat() < fixed1.toFloat());
}
bool	Fixed::operator>=( const Fixed &fixed1 ) const
{
	return (this->toFloat() >= fixed1.toFloat());
}

bool	Fixed::operator<=( const Fixed &fixed1 ) const
{
	return (this->toFloat() <= fixed1.toFloat());
}

bool	Fixed::operator==( const Fixed &fixed1 ) const
{
	return (this->toFloat() == fixed1.toFloat());
}

bool	Fixed::operator!=( const Fixed &fixed1 ) const
{
	return (this->toFloat() != fixed1.toFloat());
}

Fixed	&Fixed::operator++( void )
{
	(this->_n)++;
	return (*this);
}

Fixed	&Fixed::operator--( void )
{
	(this->_n)--;
	return (*this);
}

Fixed	Fixed::operator++( int n )
{
	Fixed	aux = *this;
	if (n < 0)
	{
		while (n <= 0)
		{
			--*this;
			n++;
		}
	}
	else
	{
		while (n >= 0)
		{
			++*this;
			n--;
		}
	}
	return (aux);
}

Fixed	Fixed::operator--( int n )
{
	Fixed	aux = *this;
	if (n < 0)
	{
		while (n <= 0)
		{
			++*this;
			n++;
		}
	}
	else
	{
		while (n >= 0)
		{
			--*this;
			n--;
		}
	}
	return (aux);
}

std::ostream	&operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}

/*
*	OTHER FUNCTIONS
*/

int	Fixed::getRawBits( void ) const
{
	return (this->_n);
}

void	Fixed::setRawBits( int raw )
{
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

Fixed	Fixed::min( const Fixed &fixed1, const Fixed &fixed2)
{
	if (fixed1 > fixed2)
		return (Fixed( fixed2 ));
	return (Fixed( fixed1 ));
}

Fixed	Fixed::min(Fixed &fixed1, Fixed &fixed2)
{
	if (fixed1 > fixed2)
		return (Fixed( fixed2 ));
	return (Fixed( fixed1 ));
}

Fixed	Fixed::max( const Fixed &fixed1, const Fixed &fixed2)
{
	if (fixed1 >= fixed2)
		return (Fixed( fixed1 ));
	return (Fixed( fixed2 ));
}

Fixed	Fixed::max(Fixed &fixed1, Fixed &fixed2)
{
	if (fixed1 >= fixed2)
		return (Fixed( fixed1 ));
	return (Fixed( fixed2 ));
}