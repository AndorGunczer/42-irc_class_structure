/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 09:30:22 by slippert          #+#    #+#             */
/*   Updated: 2024/03/27 12:29:01 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

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
