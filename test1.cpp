#include <iostream>
#include <string>
#include <SerialPort.h> 

int main() {
    std::string portName = "/dev/ttyACM0"; 
    int baudRate = 9600; 

    
    SerialPort arduino(portName, baudRate);

    if (arduino.isConnected()) {
        std::cout << "Connection established with Arduino on " << portName << std::endl;
    } else {
        std::cerr << "Failed to connect to Arduino on " << portName << std::endl;
        return 1;
    }

    
    while (true) {
        std::string dataToSend;
        std::cout << "Enter data to send to Arduino (or 'exit' to quit): ";
        std::getline(std::cin, dataToSend);

        if (dataToSend == "exit") {
            break;
        }

        
        arduino.writeLine(dataToSend);
    }

    
    arduino.closePort();
    std::cout << "Serial communication closed." << std::endl;

    return 0;
}
