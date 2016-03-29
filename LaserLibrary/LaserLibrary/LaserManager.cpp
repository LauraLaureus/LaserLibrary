//
//  LaserManager.cpp
//  LaserLibrary
//
//  Created by Laura del Pino Díaz on 23/3/16.
//  Copyright © 2016 Laura del Pino Díaz. All rights reserved.
//

#include "LaserManager.hpp"

char* fake[1];
int LaserManager::vertex[4];
qrk::Connection_information LaserManager::information(1, fake);
qrk::Urg_driver LaserManager::urg;

using namespace std;


void LaserManager::open(){
    if(!LaserManager::urg.open(
                           LaserManager::information.device_or_ip_name(),
                           LaserManager::information.baudrate_or_port_number(),
                           LaserManager::information.connection_type()
                               ))
       cout << "Not opened" << endl;
     urg.set_scanning_parameter(urg.deg2step(-90), urg.deg2step(+90), 0);
    urg.start_measurement(qrk::Urg_driver::Distance, qrk::Urg_driver::Infinity_times, 0);
    
}

void LaserManager::setWorkSpaceVertex(int rightDown, int rightUp, int leftUp, int leftDown){
    LaserManager::vertex[0] =rightDown;
    LaserManager::vertex[1] = rightUp;
    LaserManager::vertex[2] = leftUp;
    LaserManager::vertex[3] = leftDown;
}

PlanePoint LaserManager::readLaser(){
    std::vector<long> data;
    long time_stamp = 0;
    
    if (!LaserManager::urg.get_distance(data, &time_stamp)) {
        std::cout << "Urg_driver::get_distance(): " << urg.what() << std::endl;
        return *new PlanePoint(0,0);
    }
    return *new PlanePoint(0,0);
}
