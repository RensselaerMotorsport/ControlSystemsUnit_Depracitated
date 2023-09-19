/*
 * This is the abstract class above all the sensors
 */

#ifndef RENNSMOTORSPORT_IO_H
#define RENNSMOTORSPORT_IO_H


class IO {
public:
    IO(){ alive = enabled = false; }

    //Setters:
    void revive() { alive = true; }
    void kill() { alive = false; } //TODO: Can a sensor be enabled but not alive?
    void enable() { enabled = true; }
    void disable() { enabled = false; }

    //Getters:
    bool isAlive(){ return alive; }
    bool isEnabled(){ return enabled; }
private:
    bool alive;
    bool enabled;
};


#endif //RENNSMOTORSPORT_IO_H
