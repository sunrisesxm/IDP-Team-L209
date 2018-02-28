using namespace std;

// Distance sensor class
class MicroSwitch {
public:
    void activate();
private:
    static const double reference = 3.1;
    double convert_voltage_to_distance(double);
    
}

