// https://www.youtube.com/watch?v=QFXK7RvDT-Y
// https://aninternetofsoftthings.com/blog/photon-publish-and-subscription-events/
int led = D6; // selected pin for led

void setup() {
    pinMode(led,OUTPUT); // make led pin an output pin
    
    // subscribe to an event named "Deakin_RIOT_SIT210_Photon_Buddy" from MY_DEVICES 
    // and trigger wave(const char *event, const char *data) once event is detected.
    Particle.subscribe("Deakin_RIOT_SIT210_Photon_Buddy", handler);//, MY_DEVICES); 
    //Particle.subscribe("Deakin_RIOT_SIT210_Photon_Buddy", pat, MY_DEVICES); 
}

void loop() {

}
//void toggleled(const char *event, const char *data) // didn't need to use

void handler(String event, String data)
{
    if (data == "wave"){ // if data equals "wave" run this code
        // blink led 3 times
        for(int i = 0; i<3;++i){
            digitalWrite(led,HIGH); // turn led on
            delay(200); // keep on for __ milliseconds
            digitalWrite(led,LOW); // turn led off
            delay(200); // keep off for __ milliseconds
        }
    }
    if (data == "pat"){ // this is confusing but data must equal wave to run code
        // blink led once
        digitalWrite(led,HIGH); // turn led on
        delay(200); // keep on for __ milliseconds
        digitalWrite(led,LOW); // turn led off
        delay(200); // keep off for __ milliseconds
    }
    
}