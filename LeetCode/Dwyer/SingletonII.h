//����Ƕ���ģʽ
#pragma once
class SingletonII
{
public:
	SingletonII();
	~SingletonII();
	const SingletonII* instance() {
		return m_instance;
	}
private:
	const SingletonII* SingletonII::m_instance = new SingletonII;
};

