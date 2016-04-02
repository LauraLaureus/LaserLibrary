//
//  LaserManager.hpp
//  LaserLibrary
//
//  Created by Laura del Pino Díaz on 23/3/16.
//  Copyright © 2016 Laura del Pino Díaz. All rights reserved.
//

#ifndef LaserManager_hpp
#define LaserManager_hpp

#include <iostream>
#include "Urg_driver.h"
#include "Connection_information.h"
#include "math_utilities.h"

class PlanePoint{

public:
    long x;
    long y;
    PlanePoint(long x , long y){
        this->x = x;
        this->y = y;
    }
    
};




class LaserManager{
    static qrk::Connection_information information;
    static int vertex [3];
    static qrk::Urg_driver urg;
    
public:
    
    
    LaserManager(int argc, char** argv);
    
    static void open();
    static void setWorkSpaceVertex(int right,int height,int left);
    static PlanePoint readLaser();
    
};

#endif /* LaserManager_hpp */
