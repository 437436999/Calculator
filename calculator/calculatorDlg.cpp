
// calculatorDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "calculator.h"
#include "calculatorDlg.h"
#include "afxdialogex.h"
#include <string>
#include <stack>

using std::string;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CcalculatorDlg 对话框



CcalculatorDlg::CcalculatorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CALCULATOR_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CcalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CcalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON4, &CcalculatorDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON0, &CcalculatorDlg::OnBnClickedButton0)
	ON_COMMAND(ID_32772, &CcalculatorDlg::CreaDigAbout)
	ON_BN_CLICKED(IDC_BUTTON1, &CcalculatorDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CcalculatorDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CcalculatorDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON5, &CcalculatorDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CcalculatorDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CcalculatorDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CcalculatorDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CcalculatorDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTONB, &CcalculatorDlg::OnBnClickedButtonb)
	ON_BN_CLICKED(IDC_BUTTONC, &CcalculatorDlg::OnBnClickedButtonc)
	ON_BN_CLICKED(IDC_BUTTOND, &CcalculatorDlg::OnBnClickedButtond)
	ON_BN_CLICKED(IDC_BUTTONE, &CcalculatorDlg::OnBnClickedButtone)
	ON_BN_CLICKED(IDC_BUTTONF, &CcalculatorDlg::OnBnClickedButtonf)
	ON_BN_CLICKED(IDC_BUTTONG, &CcalculatorDlg::OnBnClickedButtong)
	ON_BN_CLICKED(IDC_BUTTONA, &CcalculatorDlg::OnBnClickedButtona)
	ON_BN_CLICKED(IDC_BUTTON19, &CcalculatorDlg::OnBnClickedButton19)
	ON_BN_CLICKED(IDC_BUTTON18, &CcalculatorDlg::OnBnClickedButton18)
END_MESSAGE_MAP()


// CcalculatorDlg 消息处理程序

BOOL CcalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CcalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CcalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CcalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}




void CcalculatorDlg::OnBnClickedButton0()
{
	// TODO: 在此添加控件通知处理程序代码
	CString cs;
	GetDlgItemText(IDC_EDIT1, cs);
	SetDlgItemText(IDC_EDIT1, cs + _T( "0"));
}


void CcalculatorDlg::CreaDigAbout()
{
	// TODO: 在此添加命令处理程序代码
}


void CcalculatorDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CString cs;
	GetDlgItemText(IDC_EDIT1, cs);
	SetDlgItemText(IDC_EDIT1, cs + _T("1"));
}


void CcalculatorDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	CString cs;
	GetDlgItemText(IDC_EDIT1, cs);
	SetDlgItemText(IDC_EDIT1, cs + _T("2"));
}


void CcalculatorDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	CString cs;
	GetDlgItemText(IDC_EDIT1, cs);
	SetDlgItemText(IDC_EDIT1, cs + _T("3"));
}


void CcalculatorDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	CString cs;
	GetDlgItemText(IDC_EDIT1, cs);
	SetDlgItemText(IDC_EDIT1, cs + _T("4"));
}

void CcalculatorDlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	CString cs;
	GetDlgItemText(IDC_EDIT1, cs);
	SetDlgItemText(IDC_EDIT1, cs + _T("5"));
}


void CcalculatorDlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	CString cs;
	GetDlgItemText(IDC_EDIT1, cs);
	SetDlgItemText(IDC_EDIT1, cs + _T("6"));
}


void CcalculatorDlg::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
	CString cs;
	GetDlgItemText(IDC_EDIT1, cs);
	SetDlgItemText(IDC_EDIT1, cs + _T("7"));
}


void CcalculatorDlg::OnBnClickedButton8()
{
	// TODO: 在此添加控件通知处理程序代码
	CString cs;
	GetDlgItemText(IDC_EDIT1, cs);
	SetDlgItemText(IDC_EDIT1, cs + _T("8"));
}


void CcalculatorDlg::OnBnClickedButton9()
{
	// TODO: 在此添加控件通知处理程序代码
	CString cs;
	GetDlgItemText(IDC_EDIT1, cs);
	SetDlgItemText(IDC_EDIT1, cs + _T("9"));
}


void CcalculatorDlg::OnBnClickedButtonb()
{
	// TODO: 在此添加控件通知处理程序代码
	CString cs;
	GetDlgItemText(IDC_EDIT1, cs);
	if (cs.GetLength()!=0 && (cs.GetAt(cs.GetLength() - 1) >= _T('0') && cs.GetAt(cs.GetLength() - 1) <= _T('9') || cs.GetAt(cs.GetLength() - 1) == _T(')'))) {
		SetDlgItemText(IDC_EDIT1, cs + _T("+"));
	}
	return;
}


void CcalculatorDlg::OnBnClickedButtonc()
{
	// TODO: 在此添加控件通知处理程序代码
	CString cs;
	GetDlgItemText(IDC_EDIT1, cs);
	if (cs.GetLength() == 0
		|| (cs.GetAt(cs.GetLength() - 1) >= _T('0') && cs.GetAt(cs.GetLength() - 1) <= _T('9'))
		|| cs.GetAt(cs.GetLength() - 1) == _T('(') || cs.GetAt(cs.GetLength() - 1) == _T(')')) {
		SetDlgItemText(IDC_EDIT1, cs + _T("-"));
	}
	return;
}


void CcalculatorDlg::OnBnClickedButtond()
{
	// TODO: 在此添加控件通知处理程序代码
	CString cs;
	GetDlgItemText(IDC_EDIT1, cs);
	if (cs.GetLength() != 0 && (cs.GetAt(cs.GetLength() - 1) >= _T('0') && cs.GetAt(cs.GetLength() - 1) <= _T('9') || cs.GetAt(cs.GetLength() - 1) == _T(')'))) {
		SetDlgItemText(IDC_EDIT1, cs + _T("×"));
	}
	return;
}


void CcalculatorDlg::OnBnClickedButtone()
{
	// TODO: 在此添加控件通知处理程序代码
	CString cs;
	GetDlgItemText(IDC_EDIT1, cs);
	if (cs.GetLength() != 0 && (cs.GetAt(cs.GetLength() - 1) >= _T('0') && cs.GetAt(cs.GetLength() - 1) <= _T('9') || cs.GetAt(cs.GetLength() - 1) == _T(')'))) {
		SetDlgItemText(IDC_EDIT1, cs + _T("÷"));
	}
	return;
}


void CcalculatorDlg::OnBnClickedButtonf()
{
	// TODO: 在此添加控件通知处理程序代码
	CString cs;
	GetDlgItemText(IDC_EDIT1, cs);
	if(cs.GetLength() == 0 || cs.GetAt(cs.GetLength() - 1) == _T('+') || cs.GetAt(cs.GetLength() - 1) == _T('-')
		|| cs.GetAt(cs.GetLength() - 1) == _T('×') || cs.GetAt(cs.GetLength() - 1) == _T('÷') 
		|| cs.GetAt(cs.GetLength() - 1) == _T('('))
		SetDlgItemText(IDC_EDIT1, cs + _T("("));
}


void CcalculatorDlg::OnBnClickedButtong()
{
	// TODO: 在此添加控件通知处理程序代码
	CString cs;
	GetDlgItemText(IDC_EDIT1, cs);
	if (cs.GetLength() != 0 && (
		(cs.GetAt(cs.GetLength() - 1) >= _T('0') && cs.GetAt(cs.GetLength() - 1) <= _T('9') )
		|| cs.GetAt(cs.GetLength() - 1) == _T(')')))
	SetDlgItemText(IDC_EDIT1, cs + _T(")"));
}

bool PopOne(std::stack<int> &num, std::stack<TCHAR>& ope) {
	if (ope.empty() || ope.top() == _T('('))return 0;
	int a = num.top();
	num.pop();
	int b = num.top();
	num.pop();
	switch(ope.top()){
		case _T('+'): {
			num.push(a + b);
			break;
		}
		case _T('-'): {
			num.push(b - a);
			break;
		}
		case _T('×'): {
			num.push(a * b);
			break;
		}
		case _T('÷'): {
			num.push(b / a);
			break;
		}
	}
	ope.pop();
	return 1;
}

int NumOperate(CString cs, int &n) {
	int num = 0;
	while (cs.GetAt(n) >= _T('0') && cs.GetAt(n) <= _T('9')) {
		num *= 10;
		num += cs.GetAt(n) - _T('0');
		n++;
	}
	return num;
}

void Operate(std::stack<int>& num,std::stack<TCHAR>& ope, CString &cs,int n,int &neg) {
	TCHAR cx = cs.GetAt(n);
	switch (cx) {
		case _T('+'): {
			if(ope.empty())
				ope.push(cx);
			else {
				while (PopOne(num, ope));
				ope.push(cx);
			}
			break;
		}
		case _T('-'): {
			if (n == 0 || cs.GetAt(n - 1) == _T('(')) {
				neg = -1;
				break;
			}
			if (ope.empty())
				ope.push(cx);
			else {
				while (PopOne(num, ope));
				ope.push(cx);
			}
			break;
		}
		case _T('×'): {
			if (ope.empty()||ope.top()== _T('-')||ope.top()== _T('+'))
				ope.push(cx);
			else {
				while (ope.top() != _T('-') && ope.top() && _T('+') && PopOne(num, ope));
				ope.push(cx);
			}
			break;
		}
		case _T('÷'): {
			if (ope.empty() || ope.top() == _T('-') || ope.top() == _T('+'))
				ope.push(cx);
			else {
				while (ope.top() != _T('-') && ope.top() && _T('+') && PopOne(num, ope));
				ope.push(cx);
			}
			break;
		}
		case _T('('): {
			ope.push(cx);
			break;
		}
		case _T(')'): {
			while (PopOne(num, ope));
			ope.pop();
			break;
		}
	}
}

void CcalculatorDlg::OnBnClickedButtona()
{
	// TODO: 在此添加控件通知处理程序代码
	CString cs;
	GetDlgItemText(IDC_EDIT1, cs);
	std::stack<int> num;
	std::stack<TCHAR> ope;
	int count = cs.GetLength();
	int neg = 1;
	int n = 0;
	while (n != count) {
		if (cs.GetAt(n) >= _T('0') && cs.GetAt(n) <= _T('9')) {
			num.push(neg * NumOperate(cs,n));
			if (neg == -1)neg = 1;
		}
		else {
			Operate(num ,ope ,cs ,n ,neg );
			n++;
		}
	}
	while (PopOne(num, ope));
	cs.Format(_T("%d"), num.top());
	SetDlgItemText(IDC_EDIT1, cs);

}


void CcalculatorDlg::OnBnClickedButton19()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CcalculatorDlg::OnBnClickedButton18()
{
	// TODO: 在此添加控件通知处理程序代码
	CString cs;
	GetDlgItemText(IDC_EDIT1, cs);
	if (cs.GetLength() != 0) {
		cs.Delete(cs.GetLength() - 1);
		SetDlgItemText(IDC_EDIT1, cs);
	}
	return;
}
