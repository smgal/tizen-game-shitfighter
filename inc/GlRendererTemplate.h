#ifndef _GLRENDERERTEMPLATE_H_
#define _GLRENDERERTEMPLATE_H_

#include <gl.h>
#include <FGrpIGlRenderer.h>
#include <FGrpGlPlayer.h>
#include <FUiControl.h>

class GlRendererTemplate :
	public Tizen::Graphics::Opengl::IGlRenderer
{
public:
	GlRendererTemplate(Tizen::Ui::Control* pControl, Tizen::Graphics::Opengl::GlPlayer* pPlayer);
	~GlRendererTemplate(void);

	virtual bool InitializeGl(void);
	virtual bool TerminateGl(void);

	virtual bool Draw(void);

	virtual bool Pause(void);
	virtual bool Resume(void);

	virtual int GetTargetControlWidth(void);
	virtual int GetTargetControlHeight(void);
	virtual void SetTargetControlWidth(int width);
	virtual void SetTargetControlHeight(int height);

private:
	int __controlWidth;
	int __controlHeight;
	Tizen::Ui::Control* __pAssociatedControl;
	Tizen::Graphics::Opengl::GlPlayer* __pAssociatedPlayer;
};

#endif /* _GLRENDERERTEMPLATE_H_ */
