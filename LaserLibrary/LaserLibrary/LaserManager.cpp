//
//  LaserManager.cpp
//  LaserLibrary
//
//  Created by Laura del Pino Díaz on 23/3/16.
//  Copyright © 2016 Laura del Pino Díaz. All rights reserved.
//

#include "LaserManager.hpp"

char* fake[1];
int LaserManager::vertex[3];
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

void LaserManager::setWorkSpaceVertex(int right, int height, int left){
    LaserManager::vertex[0] =right;
    LaserManager::vertex[1] = height;
    LaserManager::vertex[2] = left;
  
}


//TODO calculate centroide
//TODO calculate x and y values for every point in data.
PlanePoint LaserManager::readLaser(){
    std::vector<long> data;
    long time_stamp = 0;
    
    if (!LaserManager::urg.get_distance(data, &time_stamp)) {
        std::cout << "Urg_driver::get_distance(): " << urg.what() << std::endl;
        return *new PlanePoint(0,0);
    }
    return *new PlanePoint(0,0);
}

