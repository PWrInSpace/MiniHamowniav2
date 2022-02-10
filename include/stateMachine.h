#ifndef STATE_MACHINE_HH
#define STATE_MACHINE_HH

#include "FreeRTOS.h"

#define Rx_QUEUE_LENGTH 5
#define Tx_QUEUE_LENGTH 10

enum State{
    DISCONNECTED = 0,
    IDLE,
    COUNTDOWN,
    STATIC_FIRE,
    ABORT
};

typedef struct StateMachine{
    State state = DISCONNECTED;
    TaskHandle_t btRxTask = NULL;
    TaskHandle_t btTxTask = NULL;
    TaskHandle_t mainTask = NULL;
    QueueHandle_t btRxQueue = NULL;
    QueueHandle_t btTxQueue = NULL;
    QueueHandle_t dataQueue = NULL;
    
} StateMachine;


#endif