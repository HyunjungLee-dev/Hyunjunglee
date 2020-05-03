#pragma once
#include"Piece.h"
class ChessPiece : public Piece
{
private:
	COLOR m_ePieceColor;
	vector<Piece*> ChessPieceList;
public:
	//�ʱ� ����
	void Init(int x, int y, COLOR color);
	void SetPieceListPos(int x, int y);
	Piece* AddPiece(PIECETYPE Type);
	virtual void SetImgColor(COLOR color) { m_ePieceColor = color; }
	void SetColor(int index);

	//�׸���
	void PieceListDraw(HDC hdc);

	//��ȸ
	bool SearchPiecePos(POINT point);
	bool SearchKing(POINT point);
	
	void UpgradePawn();

	//Getter 
	vector<Piece*> GetPiece() { return ChessPieceList; }
	POINT GetPiecePos(int index);
	int GetListSize() { return ChessPieceList.size(); }

	//Setter
	Piece* SetMoveRange(POINT point, vector<Piece*> v);


	//
	virtual void SetMoveRange(vector<Piece*> v) {};
	virtual void SetMovableRange(vector<Piece*> v) { };

	//����
	void ErasePiece(Piece* piece);
	void ClearPiece();
	ChessPiece();
	~ChessPiece();
};

