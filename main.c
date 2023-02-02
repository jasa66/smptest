#include "FreeRTOS.h"
#include "main.h"
#include <stdio.h>
#include "pico/stdlib.h"

int main() {

  BaseType_t TaskReturned;
  UBaseType_t uxCoreAffinityMask;

  void HelloTask(void * params)
  {
    printf("HelloTask here\n");
  }

  void WorldTask(void * params)
  {
    printf("WorldTask here*\n");
  }

  TaskReturned = xTaskCreate(
                 HelloTask,          /* Function that implements the task. */
                 "HelloTask",        /* Text name for the task. */
                 512,                /* Stack size in words, not bytes. */
                 ( void * ) 0,       /* Parameter passed into the task. */
                 1,                  /* Priority at which the task is created. */
                 &HelloTaskHandle );   

  if (TaskReturned == errCOULD_NOT_ALLOCATE_REQUIRED_MEMORY)
  {
    while(1);
  } 
  uxCoreAffinityMask = ( 1 << 0  ); // Core0 used for modbus stack
	vTaskCoreAffinitySet( HelloTaskHandle, uxCoreAffinityMask );
 
  TaskReturned = xTaskCreate(
                 WorldTask,          /* Function that implements the task. */
                 "WorldTask",        /* Text name for the task. */
                 512,                /* Stack size in words, not bytes. */
                 ( void * ) 0,       /* Parameter passed into the task. */
                 2,                  /* Priority at which the task is created. */
                 &WorldTaskHandle );   
  if (TaskReturned  == errCOULD_NOT_ALLOCATE_REQUIRED_MEMORY)
  {
    while(1);
  } 
  
  uxCoreAffinityMask = ( 1 << 1  ); // Core1 used for modbus stack
	vTaskCoreAffinitySet( WorldTaskHandle, uxCoreAffinityMask );

  vTaskStartScheduler();

  while(1)
  {
    configASSERT(0);    /* We should never get here */
  }
}


