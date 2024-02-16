// ChessBoard.cpp
#include "ChessBoard.h"
#include <iostream>

ChessBoard::ChessBoard() {
    
    for (auto& element : m_Board ){
        for (auto& p : element ){
            p.type=Piece::None;
        } 
    }
    setPiece(0, 0, Piece::Pawn, Piece::White);
}

void ChessBoard::setPiece(int x, int y, Piece::PieceType type, Piece::Color color)
{
    m_Board[y][x] = Piece {.x = x, .y = y, .type = type, .color = color };
}

void ChessBoard::render() const
{
    for (auto& y : m_renderData){
        for (auto& x : y){
            x = '-';
        }
    }
        renderPawns();

    for (auto& y : m_renderData){
        for (auto& x : y){
            
            std::cout << x;
        }
       std::cout <<"\n";
    }
}

void ChessBoard::renderPawns() const 
{
    for (int y = 0; y < m_Board.size(); y++){
        for(int x = 0; x < m_Board[y].size(); ++x){
            char c;
            switch (m_Board[y][x].type)
            {
            case Piece::King:
                c = 'k';
                break;
            
            case Piece::Queen:
                c = 'q';
                break;

            case Piece::Bishop:
                c = 'k';
                break;

            case Piece::Knight:
                c = 'k';
                break;

            case Piece::Rook:
                c = 'r';
                break;
            
            case Piece::Pawn:
                c = 'p';
                break;

            default:
                c = '-';
                break;
            }
            c = (m_Board[y][x].color == Piece::White) ? std::toupper(c) : c;
            m_renderData[y][x] = c;
        }
    }
}

bool ChessBoard::borderCheck(int coord)
{ 
    return 0 <= coord && coord < 8; 
};

bool ChessBoard::checkInput(const std::string& move)
{ 
    return move.size() == 4 && borderCheck(move[0] - 'a') && 
    borderCheck(move[1] - '1') &&
    borderCheck(move[2] - 'a') && borderCheck(move[3] - '1');
}

