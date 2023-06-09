#include <iostream>
#include <SFML/Graphics.hpp>
#include "pawn.hpp"

int main(){
    Board chess(sf::Color(0xf3bc7aff),sf::Color(0xae722bff));
    Piece* w_pawn_77 = new Pawn(true, 77, false);
    (w_pawn_77)->setTexture();
    chess.board_pieces[77] = w_pawn_77;

    sf::RenderWindow window(sf::VideoMode(768,640), "Grand_chess", sf::Style::Titlebar | sf::Style::Close);
    // window.setVerticalSyncEnabled(false);

    while (window.isOpen()) {

        sf::Event event;

        while (window.pollEvent(event)) {

            if(event.type == sf::Event::Closed)
                window.close();

            if(event.type == sf::Event::MouseButtonPressed){
                if(event.mouseButton.button == sf::Mouse::Left){
                    if ((0 <= event.mouseButton.x) && (event.mouseButton.x <= 640) && (0 <= event.mouseButton.y) && (event.mouseButton.y <= 640)){
                        unsigned int buttonPos {
                            (event.mouseButton.x/64) + ((event.mouseButton.y/64) * (10 * (640/window.getSize().y)))
                        };

                        if(!chess.getSelected())
                             chess.selectPiece(buttonPos);
                        else
                            chess.moveSelected(buttonPos);
                    }
                    // else if((517 <= event.mouseButton.x) && (event.mouseButton.x <= 763) && (5 <= event.mouseButton.y) && (event.mouseButton.y <= 45)){
                    //       chess.restart();
                    // }
                }
            }
        }
        sf::Sprite sprite;
        sprite.setTexture(PieceTextures::blackBishop);
        // sprite.setTextureRect(sf::IntRect(10, 10, 32, 32));
        // sprite.setOrigin(sf::Vector2f(sprite.getTexture()->getSize().x/2 , sprite.getTexture()->getSize().y/2));
        sprite.setScale(sf::Vector2f(0.5f,0.5f));
        window.draw(chess);
        window.draw(sprite);
        window.draw(*w_pawn_77);
        (*w_pawn_77).draw_func(window);
        window.display();

    }
    return 0;
}