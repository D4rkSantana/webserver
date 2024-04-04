/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readFileContents.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 11:11:57 by ryoshio-          #+#    #+#             */
/*   Updated: 2024/04/03 18:34:24 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.hpp"

std::string readFileContents(const std::string& filename) {
    std::ifstream file(filename.c_str());
    std::stringstream buffer;

    if (file) {
        buffer << file.rdbuf();
        file.close(); 
        return buffer.str();
    } else {
        return "";
    }
}