#include "Block.h"



Block::Block()
{
}


Block::~Block()
{
}

None::None()
{
	m_eblockType = BLOCKTYPE_NONE;
}

void None::DrawBlock(bool benter)
{
	if (benter == true)
		Bdraw.ErasePoint(m_ix + 1, m_iy + 1);
	else
		Bdraw.DrawPoint("бр", m_ix+1, m_iy+1);
}

void None::SetBlock(int x, int y)
{
	m_ix = x;
	m_iy = y;
}


None::~None()
{
}


Flag::Flag()
{
	m_eblockType = BLOCKTYPE_FLAG;
}

void Flag::DrawBlock(bool benter)
{
	if (benter == true)
		Bdraw.DrawPoint("б┌", m_ix+1, m_iy+1);
	else
		Bdraw.DrawPoint("бр", m_ix + 1, m_iy + 1);
}

void Flag::SetBlock(int x, int y)
{
	m_ix = x;
	m_iy = y;
}


Flag::~Flag()
{
}


Mine::Mine()
{
	m_eblockType = BLOCKTYPE_MINE;
}

void Mine::DrawBlock(bool benter)
{
	if (benter == true)
	 Bdraw.DrawPoint("б▌", m_ix+1 , m_iy+1 );
	else
		Bdraw.DrawPoint("бр", m_ix + 1, m_iy + 1);
}

void Mine::SetBlock(int x, int y)
{
	m_ix = x;
	m_iy = y;
}

Mine::~Mine()
{
}





