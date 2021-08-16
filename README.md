# STM32-BME280-Code
Lightweight, reusable, and portable code to interface the Bosch Sensortec BME280 sensor with STM32F1 microcontrollers.  
# Requirements
1.) ARM Keil uVision 5 MDK  
2.) STM32F1 microcontroller e.g. STM32F103C8T6 (STM32 Blue pill board) used in the sample code    
3.) Bosch Sensortec BME280 sensor  
4.) Breadboard  
5.) Connectors (M-M, F-F)  
6.) ST-Link/V2 programmer  
# Connections  

|  N   |  BME280     | STM32                           |  
| :------: | :------: | :------: |  
1   |   VIN       |  3.3v                           |   
2   |   GND       |  GND                            |   
3   |   SDA       |  SDA ( sample code uses PB7 )   |  
4   |   SCL       |  SCL ( sample code uses PB6 )   |  
# Software Architecture  
The program is divided into 3 layers of software. These layers are:  
1.) The Low Layer API  
2.) The High Layer API  
3.) The Main Application  

Low Layer APIs are functions that directly interface with the STM32F1 hardware e.g. GPIO drivers, I2C drivers, SysTick drivers, and RCC drivers etc.  

High Layer APIs are functions that access the hardware through Low Layer APIs thereby creating a level of abstraction. e.g. BME280 drivers, and System drivers etc.

The Main Application is a layer of software that is intended to reflect the logic behind the project without knowing much about the hardware. It is the highest level of abstraction and it calls High Layer APIs in order to perform operations.    
# Description of sample code  
The humidity and temperature readings of the BME280 sensor (in % and Celsius respectively) are contained in a variable of type   
**bme280_t** whose address is passed as an argument to the **BME280_Get_Data()** function. For demonstration purposes, the structure variable that contains the sensor data is named **bme280Data** and declared (in the **main** function) as follows:  

    bme280_t bme280Data;  
 
 # Checking the sensor's readings using Keil uVision debugger  
 Steps:  
 1.) Open the Keil uVision debugger and ensure the active window is the **main.c**  
 2.) Set a breakpoint on the line in which the **System_Timer_DelayMs()** function is called in the **while(1) loop**  
 3.) Run the debugger  
 4.) When the debugger stops, check the **bme280Data**'s humidity and temperature structure members for the BME280 sensor's readings.  
 # Additional resources  
 1.) RM0008 Reference manual  
 2.) STM32F103x8 datasheet  
 3.) BME280 Datasheet  
 # Note  
 To use the project in a plug-and-play manner, follow the connections and instructions above and run the sample code on an STM32 Blue Pill.  
 
    
