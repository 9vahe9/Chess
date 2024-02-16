// ChessBoard.h
#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <array>

class ChessBoard {
public:
    ChessBoard();
    void movePiece(int fromX, int fromY, int toX, int toY);
    void displayBoard() const;

private:
    struct Piece {
        enum PieceType { None, Pawn, Bishop, Knight, Rook, King, Queen };
        enum Color { White, Black };

        int x, y;
        PieceType type;
        Color color;

        void printPiece() const;
    };

    std::array<std::array<Piece, 8>, 8> m_Board{};
    void setPiece(int x, int y, Piece::PieceType type, Piece::Color color);
    mutable std::array<std::array<char, 8>, 8> m_renderData{}; //
public:
    void render() const;
    void renderPawns() const;
    
private:
    bool checkInput(const std::string& move);
    bool borderCheck(int coord);
};

#endif 
