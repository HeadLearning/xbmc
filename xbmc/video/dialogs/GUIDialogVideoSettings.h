#pragma once

/*
 *      Copyright (C) 2005-2008 Team XBMC
 *      http://www.xbmc.org
 *
 *  This Program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This Program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with XBMC; see the file COPYING.  If not, write to
 *  the Free Software Foundation, 51 Franklin Street, Suite 500, Boston, MA 02110, USA.
 *  http://www.gnu.org/copyleft/gpl.html
 *
 */

#include "settings/GUIDialogSettings.h"

class CGUIDialogVideoSettings :
      public CGUIDialogSettings
{
public:
  CGUIDialogVideoSettings(void);
  virtual ~CGUIDialogVideoSettings(void);

  static CStdString FormatInteger(float value, float minimum);
  static CStdString FormatFloat(float value, float minimum);

protected:
  virtual void CreateSettings();
  virtual void OnSettingChanged(SettingInfo &setting);
};

