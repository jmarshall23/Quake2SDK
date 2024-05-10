/*
Copyright (C) 1997-2001 Id Software, Inc.

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  

See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

*/
// Quake is a trademark of Id Software, Inc., (c) 1996 Id Software, Inc. All
// rights reserved.

#include <windows.h>
#include "../client/client.h"

extern	HWND	cl_hwnd;

static qboolean cdValid = false;
static qboolean	playing = false;
static qboolean	wasPlaying = false;
static qboolean	initialized = false;
static qboolean	enabled = false;
static qboolean playLooping = false;
static byte 	remap[100];
static byte		cdrom;
static byte		playTrack;
static byte		maxTrack;

cvar_t *cd_nocd;
cvar_t *cd_loopcount;
cvar_t *cd_looptrack;

UINT	wDeviceID;
int		loopcounter;


void CDAudio_Pause(void);

static void CDAudio_Eject(void)
{

}


static void CDAudio_CloseDoor(void)
{

}


static int CDAudio_GetAudioDiskInfo(void)
{
	return 0;
}



void CDAudio_Play2(int track, qboolean looping)
{
	
}


void CDAudio_Play(int track, qboolean looping)
{

}

void CDAudio_Stop(void)
{

}


void CDAudio_Pause(void)
{

}


void CDAudio_Resume(void)
{

}


static void CD_f (void)
{
	
}


LONG CDAudio_MessageHandler(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	return 0;
}


void CDAudio_Update(void)
{

}


int CDAudio_Init(void)
{
	return -1;
}


void CDAudio_Shutdown(void)
{

}

/*
===========
CDAudio_Activate

Called when the main window gains or loses focus.
The window have been destroyed and recreated
between a deactivate and an activate.
===========
*/
void CDAudio_Activate (qboolean active)
{
	if (active)
		CDAudio_Resume ();
	else
		CDAudio_Pause ();
}
