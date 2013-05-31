#ifndef _SHITFIGHTERTIZENFRAME_H_
#define _SHITFIGHTERTIZENFRAME_H_

#include <FBase.h>
#include <FUi.h>

class ShitFighterTizenFrame
	: public Tizen::Ui::Controls::Frame
{
public:
	ShitFighterTizenFrame(void);
	virtual ~ShitFighterTizenFrame(void);

public:
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);
};

#endif  //_SHITFIGHTERTIZENFRAME_H_
