#include "../include/facedetect.hpp"

using namespace cv;
using namespace std;


bool GetDirectoryContents(const std::string & sPath, list<std::string> &sContents){
    
    struct dirent **namelist;
    int n;

    //system call...
    n = scandir(sPath.c_str(), &namelist, 0, alphasort);

    if (n < 0)
    {
        fprintf(stderr,"\n    :: Error! GetDirectoryContents(...) - failed to read directory %s\n",sPath.c_str());
        exit(-1);
    }
    else
    {
        while(n--)
        {

            std::string sName(namelist[n]->d_name);
            std::string sFullName = sPath+"/"+sName;

            //ask a few pertinent questions.
            struct stat FileStatus;
            stat(sFullName.c_str(),&FileStatus);

            //look to remove . and ..
            if(sName!="." && sName!="..")
            {
                if(S_ISREG(FileStatus.st_mode))
                {
                    //only want to get regular files
                    sContents.push_front(sName);
                }
            }
            //C-like clean up..
            free(namelist[n]);
        }
        //C-like clean up
        free(namelist);
    }

    return true;
}

int main(int, char**){
    std::string sVideoPath = "../media/";
    list<std::string> sContents;
    list<std::string>::iterator i;
    GetDirectoryContents(sVideoPath,sContents);

    std::string videoFilename;
    
    i = sContents.begin();
    int size = sContents.size();
    namedWindow("Video",1);
    moveWindow("Video", 0, 0);

    while( i != sContents.end()) {
        videoFilename = *i; ++i;

        VideoCapture cap(sVideoPath+ videoFilename); // open the default camera
        if(!cap.isOpened())  // check if we succeeded
            return -1;

        Mat frame;

        int frameNb = cap.get(CV_CAP_PROP_FRAME_COUNT);
        for(int j =0; j < frameNb; ++i) {
            cap >> frame;
            imshow("Video", frame);
            if(waitKey(20) >= 0) break;
        }

    }
    destroyAllWindows();
    return 0;
}