/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WebServ.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:54:01 by lucasmar          #+#    #+#             */
/*   Updated: 2024/04/28 13:58:22 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSERV_HPP
#define WEBSERV_HPP

#include "./Libs.hpp"

class Socket;

class WebServ
{
	private:
		std::vector<Socket *>				_sockets;
		std::vector<int>					_qtLocation;
		conf_servers						*_dataServers;
		size_t								_sizeServers;
		int 								_bytesRead;
		int									_maxSizeRequest;
		map_ss								_statusCodes;
		map_ss								_types;
		Poll								_poll;
		bool								_newCliet(size_t i);
		void								_setStatusCode(void);

	public:
		WebServ(void);
		~WebServ(void);

		bool						connect(void);
		int							start(void);
		void						stop(void);
		void						finish(void);
		void						addFdToClose(int fd);
		void						populateConfs(std::vector<std::vector<std::string> > servers, std::vector<std::vector<std::string> > locations);
		int							searchServer(std::string port);
		int						searchLocation(size_t iS, std::string path);
		bool						setDataServer(const char *pathConf);
		void						setBytesRead(int nbr);
		dic							*setParams(const std::string str, dic *vconfs);
		map_ss						getDicTypes(void);
		map_ss						getDicStatusCodes(void);
		int							getBytesRead(void);
		size_t						getQtSevers(void);
		std::vector<int>			getAllQtLocations(void);
		std::string					getStatusCode(std::string code);
		std::vector<std::string>	getServerValue(size_t index, std::string key);
		std::vector<std::string> 	getLocationValue(size_t iS, size_t iL, std::string key);
};

# endif
