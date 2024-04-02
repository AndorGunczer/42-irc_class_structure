/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Helper.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:07:03 by slippert          #+#    #+#             */
/*   Updated: 2024/04/02 12:22:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Helper.hpp"

std::string Helper::getCurTime()
{
	time_t now = time(0);
	tm *ltm = localtime(&now);

	std::ostringstream ssHour;
	ssHour << (ltm->tm_hour);
	std::ostringstream ssMin;
	ssMin << (ltm->tm_min);
	std::ostringstream ssSec;
	ssSec << (ltm->tm_sec);
	std::string hour((ltm->tm_hour < 10 ? "0" + ssHour.str() : ssHour.str()));
	std::string min((ltm->tm_min < 10 ? "0" + ssMin.str() : ssMin.str()));
	std::string sec((ltm->tm_sec < 10 ? "0" + ssSec.str() : ssSec.str()));
	std::string localTime = "[" + hour + ":" + min + ":" + sec + "] ";
	return (localTime);
}

std::string Helper::itoa(int i)
{
	std::ostringstream oss;
	oss << i;
	if ((oss.fail()))
		throw(std::runtime_error("Error: oss"));
	return (oss.str());
}

std::string Helper::trim_whitespace(std::string str)
{
	size_t start = str.find_first_not_of(" \n");
	if (start == std::string::npos)
		return str;
	size_t end = str.find_last_not_of(" \n");
	return str.substr(start, end - start + 1);
}

std::vector<std::string> Helper::split_buffer(const char *buffer)
{
	std::vector<std::string> commands;
	std::stringstream strStream(buffer);
	std::string command;
	while (std::getline(strStream, command, ' '))
		commands.push_back(trim_whitespace(command));
	return (commands);
}

std::vector<std::string> Helper::splitString(const std::string &str)
{
	std::istringstream iss(str);
	std::vector<std::string> tokens;
	std::string token;

	while (iss >> token)
	{
		tokens.push_back(token);
	}

	return tokens;
}

std::vector<std::string> Helper::splitStringOnComma(const std::string &str)
{
	std::string tmp = str;
	std::vector<std::string> vectorStore;
	size_t wordStart = 0, wordEnd = 0;

	for (std::string::iterator it = tmp.begin(); it != tmp.end(); ++it) {
		if (*it != ',') {
			wordEnd++;
			continue;
		}	else if (*it == ',') {
			vectorStore.push_back(tmp.substr(wordStart, wordEnd - wordStart));
			wordStart = ++wordEnd;
		}
	}
	vectorStore.push_back(tmp.substr(wordStart, wordEnd - wordStart));

	return vectorStore;
}

std::vector<parsedMode> Helper::collectModes(std::vector<std::string> inputVector) {

	std::vector<parsedMode> modeCollection;
	std::vector<std::string>::iterator it = inputVector.begin();

	while (it < inputVector.end()) {
		bool added = 0;
		parsedMode oneMode;
		
		while (it < inputVector.end() && added != true) {
			if ((*it)[0] == '#' || (*it)[0] == '&') {
				oneMode.channel = *it;
				it++;
			}
			if ((*it)[0] == '-' || (*it)[0] == '+') {
				oneMode.modes = *it;
				if ((*it)[0] == '-')
					oneMode.operation = 0;
				else
					oneMode.operation = 1;
				it++;
				if ((*it)[0] == '-' || (*it)[0] == '+') {
					modeCollection.push_back(oneMode);
					added = true;
				}
				else {
					if(it != inputVector.end()) {
						oneMode.user = *it;
						modeCollection.push_back(oneMode);
						it++;
						added = true;
					}
				}
			}
		}
	}

	return modeCollection;


}

bool Helper::isMode(const std::string &str) {
	if (str[0] == '+' || str[0] == '-')
		return true;
	else
		return false;
}


