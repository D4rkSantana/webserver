#ifndef Config_HPP
#define Config_HPP

#include "library.hpp"

class Config
{
	private:
		std::string _name_file;
		std::string _raw_config;
		bool		_raw_config_open;
		
	public:
		Config(void);
		Config(const Config &copy);
		Config(std::string name_file);
		~Config(void);
		
		Config &operator= (Config const &rhs);

		bool		readConfig(void);

		std::string	getNameFile(void) const;
		std::string getRawConfig(void) const;
		bool		getRawConfigOpen(void) const;
		
		/*class GradeTooHighException: public std::exception
		{
			public:
				const char *what() const throw(); 	
		}; 

		class GradeTooLowException: public std::exception
		{
			public:
				const char *what() const throw(); 	
		};
		*/
};

//std::ostream &operator<<(std::ostream &o, Config const &Config);

#endif