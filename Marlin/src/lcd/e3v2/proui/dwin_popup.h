/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2021 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */
#pragma once

/**
 * DWIN Enhanced implementation for PRO UI
 * Author: Miguel A. Risco-Castillo (MRISCOC)
 * Version: 3.11.1
 * Date: 2022/02/28
 */

#include "dwinui.h"
#include "dwin.h"

typedef void (*popupDrawFunc_t)();
typedef void (*popupClickFunc_t)();
typedef void (*popupChangeFunc_t)(const bool state);
extern popupDrawFunc_t popupDraw;

void Draw_Select_Highlight(const bool sel, const uint16_t ypos);
inline void Draw_Select_Highlight(const bool sel) { Draw_Select_Highlight(sel, 280); };
void DWIN_Popup_Continue(const uint8_t icon, FSTR_P const fmsg1, FSTR_P const fmsg2);
void DWIN_Popup_ConfirmCancel(const uint8_t icon, FSTR_P const fmsg2);
void Goto_Popup(const popupDrawFunc_t fnDraw, const popupClickFunc_t fnClick=nullptr, const popupChangeFunc_t fnChange=nullptr);
void HMI_Popup();

inline void Draw_Popup_Bkgd() {
  dwinDrawRectangle(1, HMI_data.PopupBg_Color, 14, 60, 258, 330);
  dwinDrawRectangle(0, HMI_data.Highlight_Color, 14, 60, 258, 330);
}

template<typename T, typename U>
void dwinDrawPopup(const uint8_t icon, T amsg1=nullptr, U amsg2=nullptr, uint8_t button=0) {
  xy_uint8_t pos;
  switch (icon) {
    default: pos.set(81, 90); break;          // Icon  1 -  8, 90 - 91; (110 x 100)
    case 17 ... 24: pos.set(96, 90); break;   // Icon 17 - 24;          ( 80 x 100)
    case 78 ... 81: pos.set(100, 107); break; // Icon 78 - 81;          ( 73 x  66)
  }
  DWINUI::clearMainArea();
  drawPopupBkgd();
  if (icon) DWINUI::drawIcon(icon, pos.x, pos.y);
  if (amsg1) DWINUI::drawCenteredString(hmiData.colorPopupTxt, 210, amsg1);
  if (amsg2) DWINUI::drawCenteredString(hmiData.colorPopupTxt, 240, amsg2);
  if (button) DWINUI::drawButton(button, 86, 280);
}

template<typename T, typename U>
void DWIN_Show_Popup(const uint8_t icon, T amsg1=nullptr, U amsg2=nullptr, uint8_t button=0) {
  DWIN_Draw_Popup(icon, amsg1, amsg2, button);
  dwinUpdateLCD();
}

template<typename T, typename U>
void DWIN_Popup_Confirm(const uint8_t icon, T amsg1, U amsg2) {
  HMI_SaveProcessID(WaitResponse);
  DWIN_Draw_Popup(icon, amsg1, amsg2, BTN_Confirm);  // Button Confirm
  dwinUpdateLCD();
}

