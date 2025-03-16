#include <iostream>
#include<vector>
using namespace std;

class MediaFile
{
protected:
    string filePath;
    int size;

public:
    MediaFile(string f, int s) : filePath(f), size(s) {}
    virtual void play()
    {
        cout << "Playing media from " << filePath << endl;
    }
    virtual void stop()
    {
        cout << "Media playing stopped" << endl;
    }
};

class Imagefile : virtual public MediaFile
{
protected:
    int resolution;

public:
    Imagefile(string f, int s, int r) : MediaFile(f, s)
    {
        resolution = r;
    }
    void play()
    {
        cout << "Displaying image: " << filePath << " at " << size << "p resolution." << endl;
    }
    void displayResolution()
    {
        cout << "Resolution: " << resolution << endl;
    }
};

class AudioMedia : virtual public MediaFile
{
protected:
    int sampleRate;

public:
    AudioMedia(string f, int s, int rate) : MediaFile(f, s)
    {
        sampleRate = rate;
    }
    void play()
    {
        cout << "Playing audio file: " << filePath << " at " << sampleRate << " Hz." << endl;
    }

    void displaySampleRate()
    {
        cout << "Sample Rate: " << sampleRate << endl;
    }
};

class VideoFile : public Imagefile, public AudioMedia
{
    float duration;

public:
    VideoFile(string path, int s, int res, int rate, float dur) : MediaFile(path, s), Imagefile(path, s, res), AudioMedia(path, s, rate), duration(dur)
    {
    }
    void play()
    {
        cout << "Playing video file: " << filePath << endl;
        cout << "Resolution: " << resolution << "p, Sample Rate: " << sampleRate
             << " Hz, Duration: " << duration << " min." << endl;
    }
    void stop()
    {
        cout << "Stopping video playback for " << filePath << endl;
    }

    void showVideoDetails()
    {
        cout << "--------VIDEO DETAILS-----------------------" << endl;
        cout << "Path: " << filePath << endl;
        cout << "Size: " << size << " MB" << endl;
        cout << "Resolution: " << resolution << endl;
        cout << "Sample Rate: " << sampleRate << endl;
        cout << "Duration: " << duration << endl;
    }
};

int main() {
    VideoFile video("video.mp4", 500, 1080, 44100, 120.5);
    Imagefile image("picture.jpg", 10, 720);
    AudioMedia audio("song.mp3", 50, 48000);

    vector<MediaFile*> mediaLibrary;
    mediaLibrary.push_back(&video);
    mediaLibrary.push_back(&image);
    mediaLibrary.push_back(&audio);

    for (MediaFile* media : mediaLibrary) {
        media->play(); 
        media->stop();
        cout << "--------------------------------" << endl;
    }

    return 0;
}