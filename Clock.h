//---------------------------------------------------------------------------

#ifndef ClockH
#define ClockH
//---------------------------------------------------------------------------
#include <System.SysUtils.hpp>
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class PACKAGE TClock : public TShape
{
private:
	TDateTime unixtime;			// ������� ���� � ����� � ������� unix
	TTimer *timer; 				// ������ ��� ������� ������
	bool display_date;  		// ����, ���������� �� ����
	int clock_view_index;		// ������ ���� ����������
	int date_format_index;		// ������ ������� ����
	int hours;       			// ����
	int minutes;            	// ������
	int seconds;            	// �������
	int day;                	// ���� ������
	int month;              	// ���������� ����� ������
	UnicodeString month_title;	// ������������ ������
	int year;                   // ���������� ����� ����
protected:
	void __fastcall TicTac(TObject* Sender);
	void __fastcall SetDisplayDate(bool flag);
	bool __fastcall GetDisplayDate();
public:
	__fastcall TClock(TComponent* Owner);
__published:
	__property bool Display_date = {read = GetDisplayDate, write = SetDisplayDate};
};
//---------------------------------------------------------------------------
#endif
