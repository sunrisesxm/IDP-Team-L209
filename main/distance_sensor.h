using namespace std;

// Distance sensor class
class DistanceSensor {
public:
    double distance;
    void update();
private:
    static const double reference = 3.1;
    double convert_voltage_to_distance(double);

}
