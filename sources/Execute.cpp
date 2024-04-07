/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Execute.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 17:19:10 by marvin            #+#    #+#             */
/*   Updated: 2024/04/07 17:19:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../includes/Server.hpp"
// #include "../includes/Command.hpp"
// #include "../includes/Cap.hpp"

// void Command::checkCommand(int _clientSocket, std::map<int, Client> clients, Server *server)
// {
// 	std::string msg = clients[_clientSocket].recvMsg;
// 	Command command(msg, server);
// 	if (msg == "")
// 		return;

// 	if (command.command == "CAP")
// 	{
// 		Cap capInstance(msg, this);
// 		return;
// 	}
// }

bool executeCap(int _clientSocket, Server *server, Cap *cap)
{
        std::string custom = "";
		server->clients[_clientSocket].recvMsg = "";
		std::string replyMsg = "";
		if (cap->capSubCommand == "LS")
		{
			replyMsg = "CAP * LS :multi-prefix sasl\r\n";
			server->srvSend(_clientSocket, replyMsg);
			return (true);
		} 
		else if (cap->capSubCommand == "REQ")
		{
			// substract all after "CAP REQ :"
			custom = cap->receivedString.substr(cap->capSubCommand.size() + cap->capSubCommand.size() + 2, cap->receivedString.size() - (cap->capSubCommand.size() + cap->capSubCommand.size() + 4));
			replyMsg = "CAP * ACK :" + cap->capSubCommand + CRLF;
			server->srvSend(_clientSocket, replyMsg);
			return (true);
		}
		else if (cap->capSubCommand == "END")
		{
			std::string incomingMsg;
			// wait for receiving NICK <username and USER <username> <usermode> <hostname> <clientcomment>
			size_t breakit = 0;
			while (Server::Signal == false)
			{
				char buffer[1024];
				ssize_t bytes_received = recv(_clientSocket, buffer, sizeof(buffer), 0);
				if (bytes_received < 1)
				{
					if (++breakit >= 99999999)
						break;
					continue;
				}

				buffer[bytes_received] = '\0';
				incomingMsg = std::string(buffer);
				break;
			}
			std::cout << magenta << "srvRecv: " << incomingMsg << res;
            // 19901
			// create tokens, split string on each space ' '.
			std::vector<std::string> strTokens = Helper::splitString(incomingMsg);
			std::vector<std::string>::iterator itToken = strTokens.begin();

			bool foundPASS = false;
			// set <password>
			if (itToken != strTokens.end() && *itToken == "PASS")
			{
				if (++itToken != strTokens.end() && !itToken->empty())
					itToken->erase(0, 1);
				if (*itToken == _password)
				{
					foundPASS = true;
					server->clients[_clientSocket].Password = *itToken;
				}
				++itToken;
			}
			if (!foundPASS)
			{
				replyMsg = ERR_PASSWDMISMATCH(server->clients[_clientSocket].Nickname);
				server->srvSend(_clientSocket, replyMsg);
				server->clients[_clientSocket].Connected = false;
				return (true);
			}

			// set <nickname> and send reply to client
			if (itToken != strTokens.end() && *itToken == "NICK")
			{
				if (++itToken != strTokens.end())
					checkNICK(_clientSocket, "NICK " + *itToken + "\r\n");
				++itToken;
			}
			if (itToken != strTokens.end() && *itToken == "USER")
			{
				// set <username>
				if (++itToken != strTokens.end())
					server->clients[_clientSocket].Username = *itToken;
				// set <usermode>
				if (++itToken != strTokens.end())
					server->clients[_clientSocket].UserMode = *itToken;
				// set <hostname>
				if (++itToken != strTokens.end())
					server->clients[_clientSocket].Hostname = *itToken;
				// set <realname>
				// skip ':1,8' (kvIRC comment)
				if (++itToken != strTokens.end() && !itToken->empty())
					itToken->erase(0, 5);
				while (itToken != strTokens.end())
				{
					server->clients[_clientSocket].Realname += *itToken;
					if (++itToken != strTokens.end())
						server->clients[_clientSocket].Realname += " ";
				}
			}

			// send welcome message and login
			replyMsg = RPL_WELCOME(server->clients[_clientSocket].Nickname);
			server->srvSend(_clientSocket, replyMsg);
			// send message of the day
			replyMsg = RPL_MOTD();
			server->srvSend(_clientSocket, replyMsg);
			return (true);
		}
	return (true);
}