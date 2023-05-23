#ifndef PIECE_TEXTURE_HPP
#define PIECE_TEXTURE_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

class PieceTextures{
public:
    static sf::Texture blackKing;
    static sf::Texture blackQueen;
    static sf::Texture blackRook;
    static sf::Texture blackKnight;
    static sf::Texture blackBishop;
    static sf::Texture blackPawn;
    static sf::Texture blackChancellor;
    static sf::Texture blackArchbishop;

    static sf::Texture whiteKing;
    static sf::Texture whiteQueen;
    static sf::Texture whiteRook;
    static sf::Texture whiteKnight;
    static sf::Texture whiteBishop;
    static sf::Texture whitePawn;
    static sf::Texture whiteChancellor;
    static sf::Texture whiteArchbishop;

    static sf::Texture loadTexture (std::string str);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif // PIECE_TEXTURE_HPP