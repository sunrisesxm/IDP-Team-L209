using namespace std;

// IR receiver class
class IRReceiver {
public:
    int get_code(); // Gets beacon code from hardware timer, reads until two sequential readings are the same
private:
    int get_counter(); // Gets current counter reading
};
