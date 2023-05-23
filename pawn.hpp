#ifndef PAWN_H
#define PAWN_H

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include "board.hpp"

class Pawn : public Piece {
public:

    Pawn (bool _player = true, int _pos=-1, bool moved=false) : Piece (_player = true, _pos=-1, moved=false) {}
    virtual void calcPossibleMoves() override;
    virtual void calcDangerMoves() override;
    virtual void setTexture() override;
    void promote_toQueen();

};

#endif // PAWN_H