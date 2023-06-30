/*
 * This is the abstract class above all the sensors
 */

#ifndef RENNSMOTORSPORT_IO_H
#define RENNSMOTORSPORT_IO_H


class IO {
public:
    IO(){ alive = enable = false; }
    bool isAlive(){ return alive; }
    bool isEnabled(){ return enable; }
private:
    bool alive;
    bool enable;
};


#endif //RENNSMOTORSPORT_IO_H
