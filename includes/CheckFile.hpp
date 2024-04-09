/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CheckFile.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 11:04:35 by ryoshio-          #+#    #+#             */
/*   Updated: 2024/04/08 22:15:30 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CheckFile_HPP
#define CheckFile_HPP


#include "./library.hpp"

class CheckFile{
    private:
        CheckFile();
        
        static std::set<std::string> _getValidFirstWords(void);
        static std::set<std::string> _getValidServerWords(void);
        static std::set<std::string> _getValidLocationWords(void);
        
        static int _isFirstWordInSet(const std::string& text, const std::set<std::string>& wordSet);
        
        static bool _checkServerParams(std::string element);
        static bool _checkSLocationParams(std::string text);
       
    public:
        static bool check(std::string path);
};


#endif