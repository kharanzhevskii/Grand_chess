#include "piece.hpp"


void Piece::setPiece(bool player, int pos, bool moved){
    setPlayer(player);
    setPosition(pos); //moved true
    setMoved(moved); // moved false
}

std::string Piece::toString() {
    std::string str;
    
    str += player ? "White move " : "Black move ";

    str += "\nto position\nX: ";
    str += std::to_string((position % 10) + 1);
    str += "  Y: ";
    str += std::to_string((position / 10) + 1);
    str += '\n';

    return str;
}

void Piece::move() {
    if (position<=-1 || 100<=position) {
        position = -1;
        sprite.setColor(sf::Color(0x00000000));
        sprite.setPosition(sf::Vector2f((position % 10) * 64.f + 32.f, (position / 10) * 64.f + 32.f));
        possibleMoves.clear();
        moved = true;
    }
    else {
        sprite.setPosition(sf::Vector2f((position % 10) * 64.f + 32.f, (position / 10) * 64.f + 32.f));
        moved = true;
    }
    return;
}

// void Piece::setTexture(){
//     sprite = sf::Sprite();
//     switch (type)
//     {
//         case 'K':
//             sprite.setTexture(player ? PieceTextures::whiteKing : PieceTextures::blackKing);
//             break;
//         case 'Q':
//             sprite.setTexture(player ? PieceTextures::whiteQueen : PieceTextures::blackQueen);
//             break;
//         case 'R':
//             sprite.setTexture(player ? PieceTextures::whiteRook : PieceTextures::blackRook);
//             break;
//         case 'B':
//             sprite.setTexture(player ? PieceTextures::whiteBishop : PieceTextures::blackBishop);
//             break;
//         case 'N':
//             sprite.setTexture(player ? PieceTextures::whiteKnight : PieceTextures::blackKnight);
//             break;
//         case 'P':
//             sprite.setTexture(player ? PieceTextures::whitePawn : PieceTextures::blackPawn);
//             break;
//         default:
//             std::cerr << "Error piece type does not exist.\n";
//             break;
//     }
//     sprite.setOrigin(sf::Vector2f(sprite.getTexture()->getSize().x/2 , sprite.getTexture()->getSize().y/2));
//     sprite.setScale(sf::Vector2f(0.375f,0.375f));
// }