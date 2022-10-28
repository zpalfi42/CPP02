#ifndef	FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
private:
	int					_n;
	static const int	_c = 8;
public:
	Fixed();
	Fixed (Fixed &fixed);
	~Fixed();
	Fixed	&operator=(Fixed &fixed);

	int		getRawBits(void) const;
	void	setRawBits(int raw);
};

# endif