using namespace std;

// Distance sensor class
class DistanceSensor {
public:
    double distance;
    bool update();
private:
    double voltage;
    static const double reference = 3.1;
    double convert_voltage_to_distance(double);

}
