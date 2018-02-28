0using namespace std;

enum MicroSwitchType {COLLECTION, COLOUR_SENSOR};

// Distance sensor class
class MicroSwitch {
public:
    bool catch_switch();
    MicroSwitchType type;
private:
    void read();
};

