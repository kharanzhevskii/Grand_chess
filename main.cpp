#include <iostream>
#include <SFML/Graphics.hpp>
#include "board.hpp"

int main(){
    Board chess(sf::Color(0xf3bc7aff),sf::Color(0xae722bff));

    sf::RenderWindow window(sf::VideoMode(768,640), "Grand_chess", sf::Style::Titlebar | sf::Style::Close);
    // window.setVerticalSyncEnabled(true);

    while (window.isOpen()) {

        sf::Event event;

        while (window.pollEvent(event)) {

            if(event.type == sf::Event::Closed)
                window.close();

            if(event.type == sf::Event::MouseButtonPressed){
                if(event.mouseButton.button == sf::Mouse::Left){
                    if ((0 <= event.mouseButton.x) && (event.mouseButton.x <= 640) && (0 <= event.mouseButton.y) && (event.mouseButton.y <= 640)){
                        unsigned int buttonPos {
                            (event.mouseButton.x/64) + ((event.mouseButton.y/64) * (8 * (640/window.getSize().y)))
                        };

                        // if(!chess.getSelected())
                        //     chess.selectPiece(buttonPos);
                        // else
                        //     chess.moveSelected(buttonPos);
                    }
                    // else if((517 <= event.mouseButton.x) && (event.mouseButton.x <= 763) && (5 <= event.mouseButton.y) && (event.mouseButton.y <= 45)){
                    //     // chess.restart();
                    // }
                }
            }
        }

        window.draw(chess);
        window.display();
    }
    return 0;
}