/*
*  This file is part of RawTherapee.
*
*  Copyright (c) 2010 Oliver Duis <www.oliverduis.de>
*
*  RawTherapee is free software: you can redistribute it and/or modify
*  it under the terms of the GNU General Public License as published by
*  the Free Software Foundation, either version 3 of the License, or
*  (at your option) any later version.
*
*  RawTherapee is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*  GNU General Public License for more details.
*
*  You should have received a copy of the GNU General Public License
*  along with RawTherapee.  If not, see <http://www.gnu.org/licenses/>.
*
*/

#include <soundman.h>

#ifdef WIN32
#include <windows.h>
#include <mmsystem.h>
#endif

// Plays a sound in async mode to not block the main thread
// param is either file name or name of the system event on Windows (e.g. "SystemAsterisk" or "SystemDefault").
void SoundManager::playSoundAsync(const Glib::ustring &sound)
{
     if (sound.empty()) return;

#ifdef WIN32
    DWORD sndParam=SND_ASYNC | SND_NODEFAULT;

    if (sound.find('.')!=Glib::ustring::npos) {
        // contain dot, so it's a filename
        sndParam|=SND_FILENAME;
    } else {
        // no dot, so it's a system event
        sndParam|=SND_ALIAS;
    }

    PlaySound(safe_filename_from_utf8(sound).c_str(), NULL, sndParam);
#else
    // TODO: Add code for other OSes here
    printf("Sound not supported on your OS (yet)\n");
#endif
}