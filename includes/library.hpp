/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   library.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:13:52 by lucasmar          #+#    #+#             */
/*   Updated: 2024/04/04 12:03:38 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




//padrão libs
#include <arpa/inet.h>

#include <ctime>
#include <csignal>
#include <cstdlib>
#include <cstdio>

#include <fcntl.h>
#include <fstream>

#include <iomanip>
#include <iostream>

#include <map>

#include <netinet/in.h>
#include <netdb.h>

#include <unistd.h>

#include <sys/socket.h>
#include <string>
#include <sstream>
#include <stack>
#include <set>

#include <vector>

#include "template.tpp"

// my libs

#include "Logs.hpp"
#include "CheckArg.hpp"
#include "CheckFile.hpp"
#include "ParseConf.hpp"

bool isLineEmpty(const std::string& text);
bool checkBraces(const std::string& text);
bool fileExists(char *path);









// defines

#define COLOR_RED     "\x1b[31m"
#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_BLUE    "\x1b[34m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_RESET   "\x1b[0m"



// function 