#ifndef BOARD_HPP
#define BOARD_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <array>
#include "piece.hpp"

const int BOARD_SIZE = 10;

class Board : public sf::Drawable {

public:
    std::array<Piece*, 100> board_pieces;
    Board(sf::Color col1 = sf::Color::White, sf::Color col2 = sf::Color::Black);    
    // loads the sprites of board' rectangles
    void load(sf::Color col1 = sf::Color::White, sf::Color col2 = sf::Color::Black);

private:

    std::array<sf::RectangleShape, 100> boardSquares;    
    // draw class on SFML Window, const for target
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;


};





#endif // BOARD_HPP