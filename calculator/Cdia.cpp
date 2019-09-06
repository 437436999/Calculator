// Cdia.cpp: 实现文件
//

#include "pch.h"
#include "calculator.h"
#include "Cdia.h"
#include "afxdialogex.h"


// Cdia 对话框

IMPLEMENT_DYNAMIC(Cdia, CDialogEx)

Cdia::Cdia(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ABOUTBOX, pParent)
{

}

Cdia::~Cdia()
{
}

void Cdia::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Cdia, CDialogEx)
END_MESSAGE_MAP()


// Cdia 消息处理程序
