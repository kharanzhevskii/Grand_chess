#include "board.hpp"


Board::Board(sf::Color col1, sf::Color col2){
    load(col1,col2);
}

// member function that sets Board, can choose square colors in parameters, w/b by default
void Board::load(sf::Color col1, sf::Color col2){
    for (int i = 0; i < BOARD_SIZE; i++){

        bool tmpColor = ((i % 2) == 0) ? true : false;

        for (int j = 0; j < BOARD_SIZE; j++){

            boardSquares[j + (i * BOARD_SIZE)].setPosition(sf::Vector2f(j*64.f, i*64.f ));
            boardSquares[j + (i * BOARD_SIZE)].setSize(sf::Vector2f(64.f, 64.f));
            boardSquares[j + (i * BOARD_SIZE)].setFillColor(tmpColor ? col1 : col2);

            tmpColor = !tmpColor;
        }
    }
    for (int i = 0; i < BOARD_SIZE*BOARD_SIZE; i++){
        board_pieces[i] = NULL;
    }
}

// Draw class on SFML Window
void Board::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    for (int i = 0; i < BOARD_SIZE*BOARD_SIZE; i++){
        target.draw(boardSquares[i]);
    }
}

void Board::createMovesSquares(){

    if(selectedPiece == NULL)
        return;

    possibleMovesSquares.clear();

    for(int i=0; i<selectedPiece->getPossibleMoves().size();i++){
        sf::RectangleShape tmp;
        tmp.setPosition(sf::Vector2f((selectedPiece->getPossibleMoves().at(i) % 10) * 64.f , (selectedPiece->getPossibleMoves().at(i) / 10) * 64.f));
        tmp.setSize(sf::Vector2f(64.f, 64.f));
        tmp.setFillColor(sf::Color(0x66b4cc50));
        possibleMovesSquares.push_back(tmp);
    }

    sf::RectangleShape tmp;
    tmp.setPosition(sf::Vector2f((selectedPiece->getPosition() % 10) * 64.f , (selectedPiece->getPosition() / 10) * 64.f));
    tmp.setSize(sf::Vector2f(64.f, 64.f));
    tmp.setFillColor(sf::Color(0x00000000));
    tmp.setOutlineColor(sf::Color::Red);
    tmp.setOutlineThickness(-3.f);
    possibleMovesSquares.push_back(tmp);

    return;

}

bool Board::selectPiece(int pos){

    // for(int i=0; i<16; i++){
    //     if(playerTurn){ // If white turn
    //         if(whitePieces[i].getPosition() == pos){
    //             selectedPiece = &whitePieces[i];
    //             selected = true;
    //             break;
    //         }
    //     }
    //     else{ // If black turn
    //         if(blackPieces[i].getPosition() == pos){
    //             selectedPiece = &blackPieces[i];
    //             selected = true;
    //             break;
    //         }
    //     }
    //     selected = false;
    // }

    // if(!selected){
    //     selectedPiece = NULL;
    //     possibleMovesSquares.clear();
    //     return selected;
    // }

    selectedPiece = board_pieces[pos];
    createMovesSquares();
    
    return (selectedPiece==NULL ? false : true);
}


void Board::moveSelected(int pos){
    bool validMove {false};

    if(selectedPiece == NULL)
        return;
    
    // Check position with the Piece's possibleMoves
    for(size_t i=0; i<selectedPiece->getPossibleMoves().size(); i++){
        if(pos == selectedPiece->getPossibleMoves().at(i)){
            validMove = true;
            break;
        }
    }

    if(validMove){
       
        int old_pos = selectedPiece->getPosition();
        board_pieces[old_pos] = NULL;
        board_pieces[pos] = selectedPiece;
        selectedPiece->setPosition(pos);


        playerTurn = !playerTurn; // Here player turn changes
    }
    
    selectedPiece = NULL;
    selected = false;
    
}
