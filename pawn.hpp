#ifndef PAWN_H
#define PAWN_H

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include "board.hpp"


class Pawn : public Piece {
public:

    Pawn (bool _player = true, int _pos=-1, bool moved=false) : Piece (_player, _pos, moved) {}
    void calcPossibleMoves(Board& chess);
    void calcDangerMoves();
    virtual void setTexture() override;
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void promote_toQueen();


};

#endif // PAWN_H