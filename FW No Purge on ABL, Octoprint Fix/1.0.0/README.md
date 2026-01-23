# Kobra2 Neo Firmware 1.0.0

## Notes
- Guide/source: https://github.com/that-ambuj/Kobra2_Neo
- Thanks to the guide provided there, I was able to compile the firmware and enable features to reduce stuttering. The guide is in Russian but can be translated and understood.

## Features (in order of usefulness)
- MEATPACK
- BAUD_RATE_GCODE (keeps default 115200; allows changing baudrate without reflashing, lower baudrate reduces stutters, higher may worsen; only lightly tested)
- BUFSIZE increased to 8 from 4 and TX_BUFFER_SIZE to 4 from 0
- HOST_ACTION_COMMANDS and HOST_PROMPT_SUPPORT (OctoPrint QoL; M600 still unreliable, use `M118 A1 action:pause` for filament change)

## Changelog

### 1.0.0
- Stock printer firmware with added OctoPrint stability, provided by @that-ambuj.
