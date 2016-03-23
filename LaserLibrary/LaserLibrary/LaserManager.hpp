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
#include <pthread.h>

class LaserManager{

private:
    pthread_t thread_id;
    pthread_cond_t thread_cond_variable;
    pthread_mutex_t thread_cond_variable_mutex;
    int vertex [4];
    void* callback (int,int); //function to call when there is something.
    void* threadMain(void* args); //main function of the thread.

public:
    /* Constructor initializes Connection Information and URG_Driver*/
    LaserManager();
    /*Open conection and starts thread (thread will be stopped till run call is done)*/
    void open();
    /* Resumes thread execution */
    void run();
    /*Sets vertex of WorksSpace*/
    void setWorkSpaceVertex(int rightDown,int rightUp,int leftUp,int leftDown);
    /*Sets callback function which will be called when there is something on Workspace*/
    void setOnEvent(void* callbackFunction (int x, int y));
    
    
};

#endif /* LaserManager_hpp */
