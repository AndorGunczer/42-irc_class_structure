/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:57:09 by slippert          #+#    #+#             */
/*   Updated: 2024/04/01 15:08:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Command.hpp"

int main() {
    // test 1: Command Class
    {
    
        // std::string userInput = "JOIN #wedogreat +o 12345";

        // Command newCommand = Command(userInput);
    }
    // test 2: Helper::splitStringOnComma()
    {
        // std::string const &multipleChannels = "#wedogreat";
        // std::vector<std::string> channels = Helper::splitStringOnComma(multipleChannels);

        // for (std::vector<std::string>::iterator it = channels.begin(); it != channels.end(); ++it){
        //     std::cout << *it << std::endl;
        // }
    }
    // test 3: Join Class
    {
        // Command testClassCommand("JOIN #wedogreat,#foo,&bar 12345,thisissuper");
        Join testClass("JOIN #wedogreat,#foo,&bar 12345,thisissuper");

        for (std::vector<std::string>::iterator it = testClass.channelsToJoin.begin(); it != testClass.channelsToJoin.end(); ++it){
            std::cout << *it << std::endl;
        }

        for (std::vector<std::string>::iterator it = testClass.passwordStore.begin(); it != testClass.passwordStore.end(); ++it){
            std::cout << *it << std::endl;
        }
    }
}