# Kobra2 Neo Firmware

Custom Marlin firmware variants for the Anycubic Kobra 2 Neo focused on OctoPrint stability and probing quality-of-life improvements.

## Firmware Variants
- 1.0.0: Stock printer firmware with added OctoPrint stability (based on @that-ambuj guide).
  - README: `1.0.0/README.md`
- 1.0.1: Removes ABL purge by gating purge moves behind a toggle.
  - README: `1.0.1/README.md`
- 1.0.2: Adds `PROBING_PART_COOLING_FAN` flag to prevent part cooling fan toggles during probing and updates version/author strings.
  - README: `1.0.2/README.md`

## Key Changes
- MEATPACK enabled for smoother serial streaming.
- BAUD_RATE_GCODE enabled (default 115200) for on-the-fly baud tweaks.
- Serial buffer sizes increased (BUFSIZE 8, TX_BUFFER_SIZE 4).
- HOST_ACTION_COMMANDS and HOST_PROMPT_SUPPORT enabled for OctoPrint QoL.
- ABL purge disabled behind a toggle in `Marlin/src/HAL/STM32/autoGetZoffset.cpp`.
- Optional probing fan control via `PROBING_PART_COOLING_FAN` in `Marlin/Configuration.h`.

## Build Notes
- Use PlatformIO in VS Code (Marlin project root).
- If you adjust version/author strings: `Marlin/Configuration.h`, `Marlin/src/lcd/menu/menu.h`, `Marlin/src/inc/Version.h`.

## Credits
- Original guide and OctoPrint stability features: https://github.com/that-ambuj/Kobra2_Neo
- Firmware author: Marc L
