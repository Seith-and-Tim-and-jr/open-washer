const int button1Pin    = 2;    // pushbutton 1 pin
const int button2Pin    = 3;    // pushbutton 2 pin
const int waterLevelPin = 4;    // waterLevelPin gives a read out of the water level

const int washMoterPin  = 13;   // wash moter spinns the wash head
const int spinMoterPin  = 12;   // spins the carraige to force out water
const int pumpMoterPin  = 11;   // the pump moter pumps water out
const int drainValvePin = 10;   // the drain valve seals the drain keeping water in
const int fillValvePin  = 19;   // the fill valve seals the in pipe keeping water out

void setup()
{
    // Set up the pushbutton pins to be an input:
    pinMode(button1Pin, INPUT);
    pinMode(button2Pin, INPUT);
    pinMode(waterLevelPin, INPUT);
    
    // Set up outputs:
    pinMode(washMoterPin, OUTPUT);
    pinMode(spinMoterPin, OUTPUT);
    pinMode(pumpMoterPin, OUTPUT);
    pinMode(drainValvePin, OUTPUT);
    pinMode(fillValvePin, OUTPUT);
}

int washCycle(int loadSize, int washTime, int drainTime, int spinDryTime);{ //washCycle funcition
if (button1State == LOW){                       //start button pressed
    while (button2State == LOW) {               //door is closed 
        while (waterLevel <= loadSize){         //filling with water
            digitalWrite(drainValvePin, LOW);
            digitalWrite(fillValvePin, HIGH);
        }
            digitalWrite(fillValvePin, LOW);
            
        for (int i = 1; i <= washtime; i++){ //washing
            digitalWrite(drainValvePin, LOW);
            digitalWrite(washMotorPin, HIGH);
            delay(1000)
        }
            digitalWrite(washMotorPin, LOW);
            
        for (int i = 1; i <= drainTime; i++){ //static draining
            digitalWrite(drainValvePin, HIGH);
            delay(1000)
        }
            
        for (int i = 1; i <= spinDryTime; i++){ //spin drying
            digitalWrite(drainValvePin, HIGH);
            digitalWrite(spinDryMotorPin, HIGH);
            delay(1000)
        }
            digitalWrite(spinDryMotorPin, LOW);
    }
  }
}
    
    
void loop()
{
    int button1State, button2State;  // variables to hold the pushbutton states

    button1State = digitalRead(button1Pin);
    button2State = digitalRead(button2Pin);

    washcycle(5, 1800, 60, 300);
}

main() function

