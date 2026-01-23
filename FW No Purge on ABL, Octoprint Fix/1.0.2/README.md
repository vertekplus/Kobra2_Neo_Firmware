# Kobra2 Neo Firmware 1.0.2

## Author
- Marc L

## Changelog

### 1.0.2
- Added `PROBING_PART_COOLING_FAN` flag (default off) to prevent the part cooling fan from toggling during probing.
- Guarded part cooling fan on/off calls in `Probe::probe_at_point` and multi-probe flow behind the new flag.
- Updated firmware version/author strings to show V1.0.2 and Marc L.
