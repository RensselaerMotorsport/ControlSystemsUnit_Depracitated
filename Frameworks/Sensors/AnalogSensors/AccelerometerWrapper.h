/*
 *                       _                               _         __          __
 *     /\               | |                             | |        \ \        / /
 *    /  \   ___ ___ ___| | ___ _ __ ___  _ __ ___   ___| |_ ___ _ _\ \  /\  / / __ __ _ _ __  _ __   ___ _ __
 *   / /\ \ / __/ __/ _ \ |/ _ \ '__/ _ \| '_ ` _ \ / _ \ __/ _ \ '__\ \/  \/ / '__/ _` | '_ \| '_ \ / _ \ '__|
 *  / ____ \ (_| (_|  __/ |  __/ | | (_) | | | | | |  __/ ||  __/ |   \  /\  /| | | (_| | |_) | |_) |  __/ |
 * /_/    \_\___\___\___|_|\___|_|  \___/|_| |_| |_|\___|\__\___|_|    \/  \/ |_|  \__,_| .__/| .__/ \___|_|
 *                                                                                      | |   | |
 *                                                                                      |_|   |_|
 *
 * Each coordinate in the accelerometer is its own sensor
 * This class is for when calculations require the use of all three axes.
 */

#ifndef CONTROLSYSTEMSUNIT_ACCELEROMETERWRAPPER_H
#define CONTROLSYSTEMSUNIT_ACCELEROMETERWRAPPER_H

#include "Accelerometer.h"

class AccelerometerWrapper {
public:
    AccelerometerWrapper(Accelerometer ax, Accelerometer ay, Accelerometer az) { x = ax; y = ay; z = az; }

private:
    Accelerometer x;
    Accelerometer y;
    Accelerometer z;
};


#endif //CONTROLSYSTEMSUNIT_ACCELEROMETERWRAPPER_H
