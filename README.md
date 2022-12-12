· The Visual C++ Redistributable and OpenCV 4.6.0 need to be installed
for the .exe in the project to run. 
· They can be found in the links below:

    ·The Visual C++ Redistributable for x64:
        https://learn.microsoft.com/en-us/cpp/windows/latest-supported-vc-redist?view=msvc-140


    ·OpenCV 4.6.0 which should be added to your environment variables in the Path system variable.
        https://opencv.org/releases/
        n:\..\..\..\opencv\build\x64\vc15\bin is the path to be added.

· It should be noted; my USB camera records at 10FPS so if you want to
test with a higher FPS camera; change line 37+15 (in main.cpp) from 10(fps) to
whatever number you want and rebuild. If I have any plans on making this
project better in the future it would be to let the user pick the FPS as
well as picking the camera from a list of attached devices. Also, I
would add more error checking.

· Test the .exe :)
