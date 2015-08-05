//���������ģʽ
#pragma once
#include "../LeetCode.h"
class Singleton
{
public:
	Singleton();
	~Singleton();
	//��Ҫ�������������ж��ǲ��ǿ�
	static Singleton* instance() {
		if (m_instance == NULL) {
			//lock();  //Ҫ�� �����һ�û�㶮c++��lock
			if (m_instance == NULL) {
				m_instance = new Singleton();
			}
			//unlock();
		}
		return m_instance;
	}
	static Singleton* freeInstance() {
		delete m_instance;
		m_instance = NULL;
	}
private:
	static Singleton* m_instance;
};

