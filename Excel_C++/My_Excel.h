
#ifndef My_Excel_H_INCLUDED
#define My_Excel_H_INCLUDED

#pragma once

#include "CApplication.h"
#include "CBorders.h"
#include "CColorFormat.h"
#include "CFont0.h"
#include "CRange.h"
#include "CRanges.h"
#include "CShape.h"
#include "CShapes.h"
#include "CWorkbook.h"
#include "CWorksheet.h"
#include "CWorkbooks.h"
#include "CWorksheets.h"
#include "Cnterior.h"

#include <string>
#include <vector>

#define DllExport __declspec(dllexport)

using namespace std;

class DllExport CMyExcel
{
public:
	CMyExcel();
	~CMyExcel();

	//�½�Excel
	bool CreateExcel(bool isVisible = false, string inSheetName = "Sheet1");

	//��Excel
	bool OpenExcel(string inExcelName, bool isVisible = false);

	//���Excel
	bool SaveAs(string inSavePath, bool isReplace = true);

	//����Excel
	bool SaveExcel();

	//�ر�Excel
	void CloseExcel();

	//��ӹ����� ���뵽inIndex֮��
	bool AddWorkSheet(string inSheetname, int inIndex = 1);

	//ɾ��������
	bool DeleteWorkSheet(string inSheetname);

	//������������
	bool RenameExcelSheet(string inOldSheetName, string inNewSheetName);

	//��ȡ��Ԫ������
	string GetCellInfor(string inSheetName, int inRow, int inColumn);
	string GetCellInfor(string inSheetName, int inRow, char inColumn);

	//���õ�Ԫ���ֵ
	void SetCellValue(string inSheetName, int inRow, int inColumn, string inValue);
	void SetCellValue(string inSheetName, int inRow, char inColumn, string inValue);

	//���ù�����ָ���е��и�
	void SetRowHeight(string inSheetName, int inRow, int inHeightValue = 20);

	//���ù�����ָ���е��п�
	void SetColumnWidth(string inSheetName, int inColumn, int inWidthValue = 15);
	void SetColumnWidth(string inSheetName, char inColumn, int inWidthValue = 15);

	//����һ��
	void InsertRow(string inSheetName, int inRow);

	//����һ��
	void InsertColumn(string inSheetName, int inColumn);
	void InsertColumn(string inSheetName, char inColumn);

	//�ϲ���Ԫ��
	void CombineRanges(string inSheetName, string left_top, string right_low);
	void CombineRanges(string inSheetName, string left_top, string right_low, string inValue);

	//���õ�Ԫ��ĵ�ɫ
	void SetCellColor(string inSheetName, int inRow, int inColumn, char inRGBY);
	void SetCellColor(string inSheetName, int inRow, char inColumn, char inRGBY);

	//�ı���ָ����Ԫ��������ɫ
	void ChangeCellTextColor(string inSheetName, int inRow, int inColumn, char inRGBY);
	void ChangeCellTextColor(string inSheetName, int inRow, char inColumn, char inRGBY);

	//����ͼƬ��ָ����Ԫ��/����
	void InsertPicture(string inSheetName, int inRow, int inColumn, string inPicturePath, bool isDelete = true);
	void InsertPicture(string inSheetName, int inRow, char inColumn, string inPicturePath, bool isDelete = true);
	void InsertPicture(string inSheetName, string left_top, string right_low, string inPicturePath, bool isDelete = true);

	//���õ�Ԫ��Ϊ�ı�����
	void SetRangeFormat(string inSheetName, int inRow, int inColumn);
	void SetRangeFormat(string inSheetName, int inRow, char inColumn);
	void SetRangeFormat(string inSheetName, string left_top, string right_low);

	//���õ�Ԫ��/���� ����Ӵ�
	void SetFontBold(string inSheetName, int inRow, int inColumn, bool isBold = true);
	void SetFontBold(string inSheetName, int inRow, char inColumn, bool isBold = true);
	void SetFontBold(string inSheetName, string left_top, string right_low, bool isBold = true);

private:
	// 1, 2, 3, 4, 5, 6, 7, 8
	CApplication	m_ExcelApp;
	CWorkbook		m_Excelbook;
	CWorkbooks		m_Excelbooks;
	CWorksheet		m_Excelsheet;
	CWorksheets		m_Excelsheets;
	CRange			m_Excelrange;
	
	string m_filename;
	LPDISPATCH lpDisp;//��Excel·��
	std::vector<string> m_Sheetnames;//������й���������

	//�����ĸ�������ʱ���ų�������Ҫ��ʱ�������ʱ����Ϊpublic��������������GetWorkbookRC()
	int m_StartRow ;//�û���ʼ��
	int m_StartCol;//�û���ʼ��
	int m_UseRows;//��ʹ�õ�����, �����
	int m_UseCols;//��ʹ�õ�����, �����

	//��ʼ��
	bool InitExcel(bool isVisible);

	//�ж��Ƿ���vector��
	bool IsIntoVector( string inString, std::vector<string> inStringVector);

	//���Excel���е�Sheet����
	std::vector<string> GetExcelSheetNames();

	//��ù�������ʹ�õ�������
	bool GetWorkbookRC(string inSheetName);
};

#endif

