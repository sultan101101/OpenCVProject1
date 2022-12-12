/*****************************************************************************
*	USB Camera to .mp4 C++ program
*	Filename:	main.cpp
*	Author:		Mahomed Sultan
******************************************************************************/

//Including libraries
#include <opencv2/opencv.hpp> 
#include <iostream>


using namespace cv;  // Introduces all names from cv into global namespace.
using namespace std; // Introduces all names from std into global namespace.

const int fps = 10;  //Constant declared to be 10 for the fps we will use.



// A simple function below to demonstrate knowledge. It takes the passed parameters and writes to the .mp4.
void writeToMp4(VideoWriter passedWriter, Mat passedFrame)

{
	passedWriter.write(passedFrame); //Writes the passed frame to the .mp4.
}




int main()
{ 
	Mat frame; //Mat object named frame used to store the current frame from the USB Camera.
	VideoCapture video(0); //VideoCapture object named video is passed the default (0) USB Camera data.
	int frameWidth = video.get(CAP_PROP_FRAME_WIDTH); //Get and store width of the USB Camera frame.
	int frameHeight = video.get(CAP_PROP_FRAME_HEIGHT); //Get and store height of the USB Camera frame.

	//videoWriter object created and initialised to allow for .mp4 output.
	VideoWriter writer ("USBcam_Recording.mp4", VideoWriter::fourcc('m', 'p', '4', 'v'), 10, Size(frameWidth, frameHeight));
	
	//if statement below checks if the object video has sucessfully opened.
	if (!video.isOpened()) 
	{
		return 0; //Exit if not opened sucessfully.
	}
	else
	{
		//Send message on Terminal window informing user that recording has started.
		cout << "Video has started recording. Press any key in the USBcam window to Stop " << flush;
	}

	//While loop runs as long as we can succesfully read from the USB Camera.
	while (video.read(frame))
	{
		imshow("USBcam", frame); //Display the frame in a window titled USBcam.
		writeToMp4(writer, frame); //Call to writeToMp4 function to write the current frame to video file.

		/* waitKey function inside if statement checkes every 1000/fps(ms) if a
			key is pressed & refreshes the window if a key isn't pressed. waitKey will always
			return -1 as long as the user hasn't pressed a key on the keyboard. */
		if (waitKey(1000 / fps) >= 0)

		{
			//Code in this bracket runs if a key is pressed. If a key is pressed, we will break out of the while loop.
			break;
		}			
	}

	//Close the VideoCapture & VideoWriter objects we used then destroy all windows.
	writer.release();
	video.release();
	destroyAllWindows();

	//In C++, the line below is optional. The compiler adds it if we don't. Good practice to include however. 
	return 0; //Exit.

}



