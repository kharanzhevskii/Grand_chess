#ifndef PIECE_H
#define PIECE_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include "piece_texture.hpp"

class Piece : public sf::Drawable {
public:

    Piece (bool _player = true, int _pos=-1, bool moved=false) :
    player(_player), position(-1), moved(true) {}

    void setPiece(bool player, int pos, bool moved=false);

    void setPlayer(bool wb) { player = wb; setTexture(); }
    bool getPlayer() const { return player; }

    void setPosition(int pos){ position = pos; move(); } 
    int getPosition() const { return position; }

    void setMoved(bool moved){ moved = moved; }
    bool getMoved() const { return moved; }

    std::vector<int>& getPossibleMoves() { return possibleMoves; }
    std::vector<int>& getDangerMoves() { return dangerMoves; }

    std::string toString();

    void draw_func(sf::RenderWindow& window);
    virtual void setTexture() = 0;

protected:

    sf::Sprite sprite;
    std::vector<int> possibleMoves;
    std::vector<int> dangerMoves; // Moves that endanger opposite king NO WAY TO CALCULATE

    bool player; // true == White , false == Black for no specific reason
    int position; // 0-99 board from lt, -1 dead
    bool moved;


    void move();

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {   target.draw(sprite);    }
};

#endif //PIECE_H