
#ifndef __SPI_FLASH_H
#define __SPI_FLASH_H

#include <stdint.h>


#define FLASH_CSEN() 			HAL_GPIO_WritePin(SPI1_CS_GPIO_Port, SPI1_CS_Pin, GPIO_PIN_RESET)
#define FLASH_CSDIS() 		HAL_GPIO_WritePin(SPI1_CS_GPIO_Port, SPI1_CS_Pin, GPIO_PIN_SET)



#define READ_DATA                      0x03       //
#define HIGH_SPEED_REDA_DATA           0x0B       //ٶģʽ
#define SECTOR_ERACE_4KB               0x20       //
#define PAGE_PROGRAM                   0x02       //ҳ
#define READ_STATUS_REGISTER           0x05       //ȡ״̬Ĵ
#define ENABLE_WRITE_STATUS_REGISTER   0x50
#define WRITE_STATUS_REGISTER          0x01       //д״̬Ĵ
#define WRITE_ENABLE                   0x06       //дʹ
#define WRITE_DISABLE                  0x04       //дֹ
#define DUMMY_BYTE                     0xff       //0xA5

#define READ_FLASH_ID                  0X90       //0xA5


#define W25Qx_TIMEOUT_VALUE 1000

#define SPI_FLASH_SECTOR_SIZE  (4*1024)
#define SPI_FLASH_SIZE         0x7fffff /* 64Mb/KByte */
#define SPI_FLASH_PAGE_SIZE    256
#define SPI_SECTOR_SIZE        0x1000 /* 4K */



#define SPI_OK            ((uint8_t)0x00)
#define SPI_ERROR         ((uint8_t)0x01)
#define SPI_BUSY          ((uint8_t)0x02)
#define SPI_TIMEOUT				((uint8_t)0x03)




void hal_spi_init(void);


uint16_t  flash_read_id(void);
uint8_t flash_write_en(void);


uint8_t flash_read_Status(void);
uint8_t flash_wait_busy(void);
uint8_t flash_sector_erase_4KByte(uint32_t WriteAddr) ;
uint8_t flash_read_data(uint32_t ReadAddr, uint8_t *pBuffer,  uint16_t length);
uint8_t flash_write_page(uint32_t WriteAddr, uint8_t *pBuffer, uint16_t  WriteBytesNum );


uint8_t  spi_flash_write_data(uint32_t WriteAddr, uint8_t* pBuffer, uint16_t NumByteToWrite);

uint8_t  spi_flash_sector_write_4KByte(uint32_t WriteAddr, uint8_t* pBuffer, uint16_t NumByteToWrite);
uint8_t  spi_flash_sector_read_4KByte(uint32_t WriteAddr, uint8_t* pBuffer, uint16_t NumByteToWrite);

#endif

