#include <Alarm.h>
#include <ButtonControl.h>
#include <Service.h>
#include <Client.h>

const int PIN_BUTTON_UP = 8;
const int PIN_BUTTON_SELECT = 9;
const int PIN_BUTTON_DOWN = 10;
const int ALARM_TIMES = 2;

long int delayTimeAlarm = 1000;

Client *client;
Alarm alarm(LED_BUILTIN, delayTimeAlarm);
ButtonControl buttonControl(PIN_BUTTON_UP, PIN_BUTTON_SELECT, PIN_BUTTON_DOWN);
Service serviceClient(client);

void setup() {
    alarm.activate(ALARM_TIMES);
    Serial.begin(9600);
}

void loop() {
    if(!buttonControl.getMenuState()){
        buttonControl.readButtonStates();
        Serial.println("->" + buttonControl.getSize());
    }else{
        Serial.print("Size Selected->" + buttonControl.getSize());
        Serial.println("Sending Data....");
        serviceClient.setMessage("status=" + buttonControl.getValueSize());
        serviceClient.request("https://luisherrera.dev");
    }
    delay(1000);
}

