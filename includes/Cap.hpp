/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cap.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 10:26:18 by marvin            #+#    #+#             */
/*   Updated: 2024/04/04 10:26:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAP_HPP
#define CAP_HPP

#pragma once

// #include "Includes.hpp"
#include "Command.hpp"
#include "Server.hpp"
#include "Client.hpp"

// class Server;
// class Command;

class Cap : public Command {
    private:
        Cap();
    public:
        std::string capSubCommand;


        Cap(const std::string &userInput);
        ~Cap();
        // bool execute(int _clientSocket);
};

#endif