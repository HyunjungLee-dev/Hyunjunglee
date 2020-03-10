#pragma once
#include "Student.h"

class Std_manager 
{
	Student* std[30];

private : static Std_manager * m_instance; // 외부에서 생성 막기
public:
	static Std_manager* GetInstance()
	{
		if (m_instance == NULL)
			m_instance = new Std_manager;
		return m_instance;
	}

	Std_manager();
	void display();
	void setStudent();
	void showStudent();
	void findNumber();
	void findname();
	void findClass();
	~Std_manager()
	{
		for (int i = 0; i < 30; i++)
		{
			delete std[i];
		}
	}

};

