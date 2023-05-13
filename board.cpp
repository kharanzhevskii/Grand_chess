#include "board.hpp"



Board::Board(sf::Color col1, sf::Color col2){
    load(col1,col2);
}

// Member function that sets Board stuff, can choose square colors in parameters
void Board::load(sf::Color col1, sf::Color col2){
    for(int i = 0; i < BOARD_SIZE; i++){

        bool tmpColor = ((i % 2) == 0) ? true : false;

        for(int j = 0; j < BOARD_SIZE; j++){

            m_boardSquares[j + (i * BOARD_SIZE)].setPosition(sf::Vector2f(j*64.f, i*64.f ));
            m_boardSquares[j + (i * BOARD_SIZE)].setSize(sf::Vector2f(64.f, 64.f));
            m_boardSquares[j + (i * BOARD_SIZE)].setFillColor(tmpColor ? col1 : col2);

            tmpColor = !tmpColor;
        }
    }
}

// Draw class on SFML Window
void Board::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    for(int i = 0; i < BOARD_SIZE*BOARD_SIZE; i++){
        target.draw(m_boardSquares[i]);
    }
}