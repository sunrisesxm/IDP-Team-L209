using namespace std;

enum NestType {A,B};
enum Composition {S,B,SS,BB,SB,SSB,SBB,SSBB};

// Line sensors class
class LEDs {
public:
    bool LED1; // Nest type
    bool LED2; // Big
    bool LED3; // 2nd Big
    bool LED4; // Small
    bool LED5; // 2nd Small
    void update(NestType nest_type, Composition composition);
};

