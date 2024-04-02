/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Helper.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:06:52 by slippert          #+#    #+#             */
/*   Updated: 2024/04/02 12:26:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <sstream>
#include <vector>

class parsedMode{
	public:
		std::string channel;
		bool operation;
		std::string modes;
		std::string user;
};

class Helper
{
public:
	static std::string itoa(int i);
	static std::string getCurTime();
	static std::vector<std::string> split_buffer(const char *buffer);
	static std::string trim_whitespace(std::string str);
	static std::vector<std::string> splitString(const std::string &str);
	static std::vector<std::string> splitStringOnComma(const std::string &str);
	static std::vector<parsedMode> collectModes(std::vector<std::string> inputVector);
	static bool isMode(const std::string &str);
};