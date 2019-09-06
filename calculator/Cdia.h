#pragma once


// Cdia 对话框

class Cdia : public CDialogEx
{
	DECLARE_DYNAMIC(Cdia)

public:
	Cdia(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Cdia();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
