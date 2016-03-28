//
//  LaserManager.hpp
//  LaserLibrary
//
//  Created by Laura del Pino Díaz on 23/3/16.
//  Copyright © 2016 Laura del Pino Díaz. All rights reserved.
//

#ifndef LaserManager_hpp
#define LaserManager_hpp

#include <stdio.h>
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

private:
    int vertex [4];
    void* callback (int,int); //function to call when there is something.

public:
    /* Constructor initializes Connection Information and URG_Driver*/
    LaserManager();
    /*Open conection and starts thread (thread will be stopped till run call is done)*/
    void setWorkSpaceVertex(int rightDown,int rightUp,int leftUp,int leftDown);
    /*Function to be called by Timer event*/
    PlanePoint readLaser();
    
};

#endif /* LaserManager_hpp */
