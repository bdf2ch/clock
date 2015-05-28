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
	TDateTime unixtime;			// Текущая дата и время в формате unix
	TTimer *timer; 				// Таймер для отсчета секунд
	bool display_date;  		// Флаг, показывать ли дату
	int clock_view_index;		// Индекс вида циферблата
	int date_format_index;		// Индекс формата даты
	int hours;       			// Часы
	int minutes;            	// Минуты
	int seconds;            	// Секунды
	int day;                	// День месяца
	int month;              	// Порядковый номер месяца
	UnicodeString month_title;	// Наименование месяца
	int year;                   // Порядковый номер года
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
