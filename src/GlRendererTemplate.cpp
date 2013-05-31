
#include "GlRendererTemplate.h"

////////////////////////////////////////////////////////////////////////////////
// Game callback

#define TIME_OUT  10
#define USE_LANDSCAPE_MODE

void* g_hNativeWindow      = 0;
int   g_nativeWindowWidth  = 0;
int   g_nativeWindowHeight = 0;

extern bool g_Game_Initialize(void);
extern void g_Game_Finalize(void);
extern bool g_Game_Process(void);

namespace avej_launcher
{
	bool Initialize(int app_id, void* handle, int screen_width, int screen_height)
	{
		g_hNativeWindow      = handle;
		g_nativeWindowWidth  = screen_width;
		g_nativeWindowHeight = screen_height;

		return g_Game_Initialize();
	}

	void Finalize(void)
	{
		if (g_hNativeWindow)
		{
			g_Game_Finalize();
			g_hNativeWindow = null;
		}
	}

	bool Process(void)
	{
		return g_Game_Process();
	}
}

void TerminateApp(void);

////////////////////////////////////////////////////////////////////////////////
//

GlRendererTemplate::GlRendererTemplate(Tizen::Ui::Control* pControl, Tizen::Graphics::Opengl::GlPlayer* pPlayer)
	: __controlWidth(0)
	, __controlHeight(0)
	, __pAssociatedControl(pControl)
	, __pAssociatedPlayer(pPlayer)
{
}

GlRendererTemplate::~GlRendererTemplate(void)
{

}

bool
GlRendererTemplate::InitializeGl(void)
{
	avej_launcher::Initialize(0, (void*)__pAssociatedControl, 1280, 720);

	return true;
}

bool
GlRendererTemplate::TerminateGl(void)
{
	// TODO:
	// Terminate and reset GL status. 
	avej_launcher::Finalize();

	return true;
}

bool
GlRendererTemplate::Draw(void)
{
	// TODO:
	// Draw a scene and perform what to be necessary for each scene.

	if (!avej_launcher::Process())
	{
		__pAssociatedPlayer->Stop();

		TerminateApp();

		return false;
	}

	return true;
}

bool
GlRendererTemplate::Pause(void)
{
	// TODO:
	// Do something necessary when Plyaer is paused. 

	return true;
}

bool
GlRendererTemplate::Resume(void)
{
	// TODO:
	// Do something necessary when Plyaer is resumed. 

	return true;
}

int
GlRendererTemplate::GetTargetControlWidth(void)
{
	// TODO:
	// Return target control width

	return __controlWidth;
}

int
GlRendererTemplate::GetTargetControlHeight(void)
{
	// TODO:
	// Return target control height

	return __controlHeight;
}

void
GlRendererTemplate::SetTargetControlWidth(int width)
{
	// TODO:
	// Assign target control width

	__controlWidth = width;
}

void
GlRendererTemplate::SetTargetControlHeight(int height)
{
	// TODO:
	// Assign target control height

	__controlHeight = height;
}
