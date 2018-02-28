 using namespace std;

enum EggType {SMALL_BLUE, SMALL_YELLOW, BIG_YELLOW, BIG_BLUE}
    
}
// Colour sensor class
class ColourSensor {
public:
    EggType egg;
    double voltage_1;
    double voltage_1;
    void get_egg_type(); // Works out from voltage_1 and voltage_2 the type of egg
private:
    static const double reference = 3.3;
    void update(); // Updates sensor voltages
};
