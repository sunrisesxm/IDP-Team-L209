using namespace std;

// Line sensors class
class LineSensors {
public:
    bool s1; // Left
    bool s2; // Centre
    bool s3; // Right
    bool s4; // Rear
    bool update_all();
};
