#ifndef	FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
private:
	int					_n;
	static const int	_c = 8;
public:
	Fixed();
	Fixed( const int n );
	Fixed( const float f);
	Fixed( const Fixed &fixed );

	~Fixed();

	Fixed			&operator=( const Fixed &fixed );

	int		toInt( void ) const;
	int		getRawBits( void ) const;

	void	setRawBits( int raw );

	float	toFloat( void ) const;
};

std::ostream	&operator<<(std::ostream &out, const Fixed &fixed );

# endif