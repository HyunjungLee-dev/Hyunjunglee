#include "Block.h"



Block::Block()
{
}

void Block::Setpos(int x, int y)
{
	m_pos.m_fX = x;
	m_pos.m_fY = y;
	m_bClick = false;
}

void Block::SetRect()
{
	float SizeX = m_pos.m_fX + BitmapManager::GetSingleton()->GetImg(m_eblockType)->GetSize().cx;
	float SizeY = m_pos.m_fY + BitmapManager::GetSingleton()->GetImg(m_eblockType)->GetSize().cy;

	m_blockRect.left = m_pos.m_fX;
	m_blockRect.right = SizeX;
	m_blockRect.top = m_pos.m_fY;
	m_blockRect.bottom = SizeY;
}

Block::~Block()
{
}



void None::DrawBlock(HDC hdc)	
{
	if (!m_bClick)
		BitmapManager::GetSingleton()->GetImg(IMG_BLOCK)->Draw(hdc, m_pos.m_fX, m_pos.m_fY);
	else
		BitmapManager::GetSingleton()->GetImg(IMG_BLOCK_CLICK)->Draw(hdc, m_pos.m_fX, m_pos.m_fY);
}



void Number::DrawBlock(HDC hdc)
{
	if (!m_bClick)
		BitmapManager::GetSingleton()->GetImg(IMG_BLOCK)->Draw(hdc, m_pos.m_fX, m_pos.m_fY);
	else
		BitmapManager::GetSingleton()->GetImg(m_eblockType)->Draw(hdc, m_pos.m_fX, m_pos.m_fY);
}


void Flag::DrawBlock(HDC hdc)
{
	BitmapManager::GetSingleton()->GetImg(IMG_FLAG)->Draw(hdc, m_pos.m_fX, m_pos.m_fY);
}

void Mine::DrawBlock(HDC hdc)
{
	if(!m_bClick)
		BitmapManager::GetSingleton()->GetImg(IMG_BLOCK)->Draw(hdc, m_pos.m_fX, m_pos.m_fY);
	else
		BitmapManager::GetSingleton()->GetImg(IMG_MINE)->Draw(hdc, m_pos.m_fX, m_pos.m_fY);
}

