#pragma once

class CMyString
{
public:
	CMyString();

	// ��ȯ ������
	explicit CMyString(const char *pszParam);

	// ���� ������
	CMyString(const CMyString &rhs);

	// �̵� ������
	CMyString(CMyString &&rhs);

	~CMyString();

private:
	// ���ڿ��� �����ϱ� ���� ���� �Ҵ��� �޸𸮸� ����Ű�� ������
	char* m_pszData;

	// ����� ���ڿ��� ����
	int m_nLength;

public:
	int SetString(const char* pszParam);

	// ��� �б⸸ �����ϹǷ� �޼��带 ���ȭ�Ѵ�.
	const char* GetString() const;

	void Release();
	CMyString& operator=(const CMyString &rhs);

	operator char*() const
	{
		return m_pszData;
	}

	int GetLength() const;
	int Append(const char * pszParam);
	CMyString operator+(const CMyString & rhs);
	CMyString& operator+=(const CMyString & rhs);
	char& operator[](int nIndex);
	char operator[](int nIndex) const;
	int operator==(const CMyString &rhs);
	int operator!=(const CMyString &rhs);
};