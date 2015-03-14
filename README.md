# HD3D-Marked-Shutter
Overlay for AMD HD3D to add a shutter mark to sync custom glasses circuits on.

This repo needs to be cleaned up, which will happen shortly! But the 2010 sln works. Also, a debug version is already compiled in the Debug folder.

When put into the folder of an executable, this DLL will render a shutter mark (alternating black/white for each eye, looks grey to the naked eye) in the top left corner of the screen for any app that goes into AMD HD3D display mode (DirectX9, 32-bit only).

Tested with:
- AMD's Stereo3D DirectX9 example (comes with their HD3D sdk)
- Tridef in HD3D mode, running Flatout 2
