#include <iostream>
using namespace std;
//题目：为下面的类CMyString的声明，添加赋值运算符。
class CMyString {
public:
	CMyString(char* pData = nullptr);
	CMyString(const CMyString& str);
	~CMyString(void);
	CMyString& operator=(const CMyString &);
private:
	char *m_pData;
};
//1.常规正确解法①
#pragma warning(disable:4996)
CMyString& CMyString::operator=(const CMyString& str) {
	if (this == &str) {
		return *this;
	}
	delete[]m_pData;
	m_pData = nullptr;
	m_pData = new char[strlen(str.m_pData) + 1];
	strcpy(m_pData, str.m_pData);
}
//2.优化解法②
//CMyString& CMyString::operator=(const CMyString& str) {
//	if (this != &str) {
//		CMyString strTemp(str);
//		char *pTemp = strTemp.m_pData;
//		strTemp.m_pData = m_pData;
//		m_pData = pTemp;
//	}
//	return *this;
//
//}