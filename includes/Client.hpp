/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 09:30:22 by slippert          #+#    #+#             */
/*   Updated: 2024/04/07 15:13:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_HPP
#define CLIENT_HPP

#pragma once

#include <iostream>
#include <map>

class Client
{
private:
public:
	int socket;
	std::string Nickname;
	std::string Username;
	std::string Realname;
	std::string UserMode;
	std::string Hostname;
	std::string Password;
	std::string recvMsg;
	std::map<std::string, bool> channel;
	bool Connected;
};

#endif
