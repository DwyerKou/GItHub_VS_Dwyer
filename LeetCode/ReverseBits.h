/*
	Reverse bits of a given 32 bits unsigned integer.

For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000).

Follow up:
If this function is called many times, how would you optimize it?

Related problem: Reverse Integer
*/
#include "LeetCode.h"
class ReverseBits {
public:
	/*
		λ����
		һ���
		4ms
		���
		��Ϊ��λ���� ���õ������
	*/
	uint32_t reverseBits(uint32_t n) {
		uint32_t re = 0;
		int i = 0;
		while (i++<32){
			if (n % 2)
				re = (re << 1) + 1;
			else
				re = re << 1;
			n = n >> 1;
		}
		return re;
	}
};