nvidia-overlay-hijack from Calvin-LLC/nvidia-overlay-hijack.

I did fix some few things such as:

- Added set_mouse_passthrough when menu is opened or not. ( allow seeing the mouse inside the game over the overlay menu ).
- Added Show/hide cursor and toggle mouse passthrough when menu state changes ( Only allow mouse input when menu is open )
- Added a Check if game process is still running, If handle is invalid, also exit (unload).
- Added Ensure mouse passthrough is disabled on exit (unload).
