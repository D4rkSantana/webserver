/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Libs.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 11:50:06 by ryoshio-          #+#    #+#             */
/*   Updated: 2024/03/25 14:00:20 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#pragma once
#include "library.hpp"

#include <algorithm>
#include <cerrno>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <dirent.h>
#include <exception>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <sys/wait.h>
#include <vector>

#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <poll.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include "library.hpp"


#define IP "127.0.0.1"

#define DEFAULT_ROOT "www/html"
#define DEFAULT_ROOT_CGI "www/cgi"
#define DEFAULT_ERROR_ROOT "www/error"

#define P_BLUE "\e[0;38;5;24m"
#define RESET_COLOR "\e[0m"

#define OK 200
#define NO_CONTENT 204
#define PERMANENT_REDIRECT 301
#define TEMPORARY_REDIRECT 302
#define BAD_REQUEST 400
#define FORBIDDEN 403
#define NOT_FOUND 404
#define METHOD_NOT_ALLOWED 405
#define ENTITY_TOO_LARGE 413
#define INTERNAL_SERVER_ERROR 500
#define HTTP_VERSION_NOT_SUPPORTED 505

struct responseData {
    int         status;
    std::string content;
    std::string statusCode;
    std::string contentType;
    int         contentLength;
    std::string location;
};
