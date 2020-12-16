# WinWand
**WinWand** is a tool that can manage hidden window parameters via Windows API.
## Syntax
`winwand [help|visiblity|rtl|min|max|resize|dialog|sysmenu|top|caption] [window [window ...]]`
- help: Show a help message
- visiblity: Toggle visiblity
- rtl: Change system buttons position. May cause unexpected behavior, like mouse position mirroring, window mirroring or something bad.
- min: Toggle Minimize button
- max: Toggle Maximize button
- resize: Toggle resizing
- toolbar: Toggle toolbar UI. May cause unexpected behavior when minimizing the window.
- sysmenu: Toggle system menu
- top: Pins window to the foreground
- caption: Toggle caption
## Example
```c
winwand top "Command Prompt"
winwand caption "Command Prompt"
winwand resize "Command Prompt"
```
![A simple console, like a widget.](img/cmdscreenshot.png)
