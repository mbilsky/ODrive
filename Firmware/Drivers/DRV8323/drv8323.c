#include "drv8323.h"

#include "assert.h"
#include <math.h>
#include "cmsis_os.h"
#include "utils.hpp"



extern SPI_HandleTypeDef hspi3;

//default values for the DRV8323 registers
uint16_t DRV8323regDrvCtrl =
  0 << 9  | //DIS_CPUV
  1 << 8  | //DIS_GDF
  0 << 7  | //OTW_REP
  0 << 5  | //PWM_MODE
  0 << 4  | //1PWM_COM
  0 << 3  | //1PWM_DIR
  0 << 2  | //COAST
  0 << 1  | //BRAKE
  0;        //CLR_FLT

uint16_t DRV8323regGateDrvHS =
  3 << 8  | //LOCK
  11 << 4 | //IDRIVEP_HS
  15;       //IDRIVEN_HS			

uint16_t DRV8323regGateDrvLS =
  1 << 10 | //CBC
  2 << 8  | //TDRIVE
  15 << 4 | //IDRIVEP_LS
  15;       //IDRIVEN_LS			

uint16_t DRV8323regOcpCtrl =
  0 << 10 | //TRETRY
  1 << 8  | //DEAD_TIME
  1 << 6  | //OCP_MODE
  2 << 4  | //OCP_DEG
  0;        //VDS_LVL			

uint16_t DRV8323regCsaCtrl =
  1 << 10 | //CSA_FET
  1 << 9  | //VREF_DIV
  0 << 8  | //LS_REF
  2 << 6  | //CSA_GAIN
  0 << 5  | //DIS_SEN
  0 << 4  | //CSA_CAL_A
  0 << 3  | //CCSA_CAL_B
  0 << 2  | //CCSA_CAL_C
  3;        //CSEN_LVL	

void DRV8323_enable(DRV8323_Handle handle)
{

  //Enable driver
  HAL_GPIO_WritePin(handle->EngpioHandle, handle->EngpioNumber, GPIO_PIN_SET);

  //Wait for driver to come online
  osDelay(10);

  // Make sure the Fault bit is not set during startup
  //while((DRV8301_readSpi(handle,DRV8301_RegName_Status_1) & DRV8301_STATUS1_FAULT_BITS) != 0);

  // Wait for the DRV8301 registers to update
  osDelay(1);

  return;
}




uint16_t DRV8323_readSpi(DRV8323_Handle handle, uint8_t regAdr)
{
    //uint16_t zerobuff = 0;
	uint16_t controlword = 0x8000 | (regAdr & 0x7) << 11; //MSbit =1 for read, address is 3 bits (MSbit is always 0), data is 11 bits
	uint16_t recbuff = 0xbeef;
	
  delay_us(1);
	//HAL_GPIO_WritePin(GPIOC, GPIO_PIN_14, GPIO_PIN_RESET);
	 HAL_GPIO_WritePin(handle->nCSgpioHandle, handle->nCSgpioNumber, GPIO_PIN_RESET);
  delay_us(1);
  //HAL_SPI_TransmitReceive(&hspi3, (uint8_t*)(&controlword), (uint8_t*)(&recbuff), 1, 1000);
 HAL_SPI_TransmitReceive(handle->spiHandle, (uint8_t*)(&controlword), (uint8_t*)(&recbuff), 1, 1000);
 delay_us(1);
  //HAL_GPIO_WritePin(GPIOC, GPIO_PIN_14, GPIO_PIN_SET);
  HAL_GPIO_WritePin(handle->nCSgpioHandle, handle->nCSgpioNumber, GPIO_PIN_SET);
  delay_us(1);
	return (0x7ff&recbuff);
}

void DRV8323_writeSpi(DRV8323_Handle handle, uint8_t regAdr, uint16_t regVal)
{
	uint16_t controlword = (regAdr & 0x7) << 11 | (regVal & 0x7ff); //MSbit =0 for write, address is 3 bits (MSbit is always 0), data is 11 bits
	delay_us(1);
	//HAL_GPIO_WritePin(GPIOC, GPIO_PIN_14, GPIO_PIN_RESET);
HAL_GPIO_WritePin(handle->nCSgpioHandle, handle->nCSgpioNumber, GPIO_PIN_RESET);

delay_us(1);

//	HAL_SPI_Transmit(&hspi3, (uint8_t*)(&controlword), 1, 1000);
   HAL_SPI_Transmit(handle->spiHandle, (uint8_t*)(&controlword), 1, 1000);
  
  
  
  delay_us(1);

	//HAL_GPIO_WritePin(GPIOC, GPIO_PIN_14, GPIO_PIN_SET);
HAL_GPIO_WritePin(handle->nCSgpioHandle, handle->nCSgpioNumber, GPIO_PIN_SET); 


	delay_us(1);
  return;
}

void DRV8323_setupSpi(DRV8323_Handle handle)
{
  //  volatile uint16_t temp;
   // HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_SET); //PB12 is enable to motor controller

	
  //enable the drv
  DRV8323_enable(handle);




  

	return;
}

