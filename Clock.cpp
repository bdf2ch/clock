//---------------------------------------------------------------------------

#include <vcl.h>

#pragma hdrstop

#include "Clock.h"
#pragma package(smart_init)
USERES("Package1_resources.res");
//---------------------------------------------------------------------------
// ValidCtrCheck is used to assure that the components created do not have
// any pure virtual functions.
//

static inline void ValidCtrCheck(TClock *)
{
	new TClock(NULL);
}
//---------------------------------------------------------------------------
__fastcall  TClock::TClock(TComponent* Owner)
	: TShape(Owner)
{
	Brush -> Color = clRed;
	Pen -> Color = clWhite;
	Canvas -> MoveTo(0, 0);
	Canvas -> LineTo(10, 10);
	Width = 200;
	Height = 60;
	timer = new TTimer(this);
	timer -> Interval = 1000;
	timer -> OnTimer = TicTac;
	timer -> Enabled = true;
}
//---------------------------------------------------------------------------
namespace Clock
{
	void __fastcall PACKAGE Register()
	{
		TComponentClass classes[1] = {__classid(TClock)};
		RegisterComponents(L"Clock", classes, 0);
	}
}
//---------------------------------------------------------------------------
/* �������, ����������� ��� ������� ������� */
void __fastcall TClock::TicTac(TObject* Sender) {
  if(!ComponentState.Contains(csDestroying))
  {
	unixtime = Date();
  }
}

/* ���������� �������� ���������, ���������� �� ���� */
bool __fastcall TClock::GetDisplayDate () {
	return display_date;
};


void __fastcall TClock::SetDisplayDate (bool flag) {
	display_date = flag;
};