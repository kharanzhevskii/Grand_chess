#include "pawn.hpp"

Board chess(sf::Color(0xf3bc7aff),sf::Color(0xae722bff));

void Pawn::promote_toQueen() {
    if (player && (position / 10 == 2)){
        // Queen queen(player, position, false);
        // queen.setTexture();
    }
    if (!player && (position / 10 == 7)){
        // Queen queen(player, position, false);
        // queen.setTexture();
    }
}

void Pawn::setTexture() {
    sf::Sprite sprite;
    sprite.setTexture(player ? PieceTextures::whitePawn : PieceTextures::blackPawn);
    sprite.setOrigin(sf::Vector2f(sprite.getTexture()->getSize().x/2 , sprite.getTexture()->getSize().y/2));
    sprite.setScale(sf::Vector2f(0.5f, 0.5f));
}

void Pawn::calcDangerMoves() {}

void Pawn::calcPossibleMoves() {
    if (!player){   //check for black pawn
        if (position / 10 == 2){    //if starter position can move 2 tiles
            if (chess.board_pieces[position+2*10]==NULL or chess.board_pieces[position+2*10]->getPlayer()==player) {    //check if empty or enemy piece
                possibleMoves.push_back(position+2*10);
            }
        }
        if (chess.board_pieces[position+10]==NULL or chess.board_pieces[position+10]->getPlayer()==player) {    //check if empty or enemy piece
            possibleMoves.push_back(position+10);
        }
        if ((position%10!=0) and (chess.board_pieces[position+11]==NULL or chess.board_pieces[position+11]->getPlayer()==player)) {    //check if can attack left
            possibleMoves.push_back(position+11);
        }
        if ((position%10!=9) and (chess.board_pieces[position+9]==NULL or chess.board_pieces[position+9]->getPlayer()==player)) {    //check if can attack right
            possibleMoves.push_back(position+9);
        }
    }
    if (player){   //check for white pawn
        if (position / 10 == 7){    //if starter position can move 2 tiles
            if (chess.board_pieces[position-2*10]==NULL or chess.board_pieces[position-2*10]->getPlayer()==player) {    //check if empty or enemy piece
                possibleMoves.push_back(position-2*10);
            }
        }
        if (chess.board_pieces[position-10]==NULL or chess.board_pieces[position-10]->getPlayer()==player) {    //check if empty or enemy piece
            possibleMoves.push_back(position-10);
        }
        if ((position%10!=0) and (chess.board_pieces[position-9]==NULL or chess.board_pieces[position-9]->getPlayer()==player)) {    //check if can attack left
            possibleMoves.push_back(position-9);
        }
        if ((position%10!=9) and (chess.board_pieces[position-11]==NULL or chess.board_pieces[position-11]->getPlayer()==player)) {    //check if can attack right
            possibleMoves.push_back(position-11);
        }
    }
}