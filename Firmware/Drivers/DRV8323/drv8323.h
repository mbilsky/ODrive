#ifndef _DRV8323_H_
#define _DRV8323_H_
#ifdef __cplusplus
 extern "C" {
#endif

#include "stdbool.h"
#include "stdint.h"
#include "stm32f4xx_hal.h"

//legacy from ODrive people

#define ADR_FAULT_STAT      (0x00)
#define ADR_VGS_STAT        (0x01)
#define ADR_DRV_CTRL        (0x02)
#define ADR_GATE_DRV_HS     (0x03)
#define ADR_GATE_DRV_LS     (0x04)
#define ADR_OCP_CTRL        (0x05)
#define ADR_CSA_CTRL        (0x06)

//including code from: https://github.com/jonnyando/myBLDC/blob/master/inc/drv8323.h

typedef struct
{
    uint16_t fault_status_1;
    uint16_t fault_status_2;
    uint16_t driver_control;
    uint16_t gate_drive_HS;
    uint16_t gate_drive_LS;
    uint16_t OCP_control;
    uint16_t CSA_control;
    SPI_TypeDef *spi;
} drv8323_TypeDef;

typedef enum
{
    FAULT_CODE_NONE = 0,
    FAULT_CODE_DRV,
    FAULT_CODE_OVERVOLTAGE,
    FAULT_CODE_UNDERVOLTAGE
} drv_fault_TypeDef;




/**************  Register Address Definitions  **************/
#define DRV_FAULT_STATUS_1          (0x0U << 11)
#define DRV_FAULT_STATUS_2          (0x1U << 11) // AKA VGS status 2
#define DRV_DRIVER_CONTROL          (0x2U << 11)
#define DRV_GATE_DRIVE_HS           (0x3U << 11)
#define DRV_GATE_DRIVE_LS           (0x4U << 11)
#define DRV_OCP_CONTROL             (0x5U << 11)
#define DRV_CSA_CONTROL             (0x6U << 11)


/*******  Bit definitions for Fault Status 1 register  *******/
#define FS1_FAULT_Pos                  10U
#define FS1_FAULT_Msk                  (0x1U << FS1_FAULT_Pos)
#define FS1_FAULT                      FS1_FAULT_Msk
#define FS1_VDS_OCP_Pos                9U
#define FS1_VDS_OCP_Msk                (0x1U << FS1_VDS_OCP_Pos)
#define FS1_VDS_OCP                    FS1_VDS_OCP_Msk
#define FS1_GDF_Pos                    (8U)
#define FS1_GDF_Msk                    (0x1U << FS1_GDF_Pos)
#define FS1_GDF                        FS1_GDF_Msk
#define FS1_UVLO_Pos                   (7U)
#define FS1_UVLO_Msk                   (0x1U << FS1_UVLO_Pos)
#define FS1_UVLO                       FS1_UVLO_Msk
#define FS1_OTSD_Pos                   (6U)
#define FS1_OTSD_Msk                   (0x1U << FS1_OTSD_Pos)
#define FS1_OTSD                       FS1_OTSD_Msk
#define FS1_VDS_HA_Pos                 (5U)
#define FS1_VDS_HA_Msk                 (0x1U << FS1_VDS_HA_Pos)
#define FS1_VDS_HA                     FS1_VDS_HA_Msk
#define FS1_VDS_LA_Pos                 (4U)
#define FS1_VDS_LA_Msk                 (0x1U << FS1_VDS_LA_Pos)
#define FS1_VDS_LA                     FS1_VDS_LA_Msk
#define FS1_VDS_HB_Pos                 (3U)
#define FS1_VDS_HB_Msk                 (0x1U << FS1_VDS_HB_Pos)
#define FS1_VDS_HB                     FS1_VDS_HB_Msk
#define FS1_VDS_LB_Pos                 (2U)
#define FS1_VDS_LB_Msk                 (0x1U << FS1_VDS_LB_Pos)
#define FS1_VDS_LB                     FS1_VDS_LB_Msk
#define FS1_VDS_HC_Pos                 (1U)
#define FS1_VDS_HC_Msk                 (0x1U << FS1_VDS_HC_Pos)
#define FS1_VDS_HC                     FS1_VDS_HC_Msk
#define FS1_VDS_LC_Pos                 (0U)
#define FS1_VDS_LC_Msk                 (0x1U << FS1_VDS_LC_Pos)
#define FS1_VDS_LC                     FS1_VDS_LC_Msk

/*******  Bit definitions for VGS Status 2 register  *********/
#define FS2_SA_OC_Pos		(10U)
#define FS2_SA_OC_Msk		(0x1U << FS2_SA_OC_Pos)
#define FS2_SA_OC			FS2_SA_OC_Msk
#define FS2_SB_OC_Pos		(9U)
#define FS2_SB_OC_Msk		(0x1U << FS2_SB_OC_Pos)
#define FS2_SB_OC			FS2_SB_OC_Msk
#define FS2_SC_OC_Pos		(8U)
#define FS2_SC_OC_Msk		(0x1U << FS2_SC_OC_Pos)
#define FS2_SC_OC			FS2_SC_OC_Msk
#define FS2_OTW_Pos		    (7U)
#define FS2_OTW_Msk		    (0x1U << FS2_OTW_Pos)
#define FS2_OTW			    FS2_OTW_Msk
#define FS2_CPUV_Pos		(6U)
#define FS2_CPUV_Msk		(0x1U << FS2_CPUV_Pos)
#define FS2_CPUV			FS2_CPUV_Msk
#define FS2_VGS_HA_Pos		(5U)
#define FS2_VGS_HA_Msk		(0x1U << FS2_VGS_HA_Pos)
#define FS2_VGS_HA			FS2_VGS_HA_Msk
#define FS2_VGS_LA_Pos		(4U)
#define FS2_VGS_LA_Msk		(0x1U << FS2_VGS_LA_Pos)
#define FS2_VGS_LA			FS2_VGS_LA_Msk
#define FS2_VGS_HB_Pos		(3U)
#define FS2_VGS_HB_Msk		(0x1U << FS2_VGS_HB_Pos)
#define FS2_VGS_HB			FS2_VGS_HB_Msk
#define FS2_VGS_LB_Pos		(2U)
#define FS2_VGS_LB_Msk		(0x1U << FS2_VGS_LB_Pos)
#define FS2_VGS_LB			FS2_VGS_LB_Msk
#define FS2_VGS_HC_Pos		(1U)
#define FS2_VGS_HC_Msk		(0x1U << FS2_VGS_HC_Pos)
#define FS2_VGS_HC			FS2_VGS_HC_Msk
#define FS2_VGS_LC_Pos		(0U)
#define FS2_VGS_LC_Msk		(0x1U << FS2_VGS_LC_Pos)
#define FS2_VGS_LC			FS2_VGS_LC_Msk


/*******  Bit definitions for Driver Control register  *******/
#define DRV_CTRL_DIS_CPUV_Pos          (9U)
#define DRV_CTRL_DIS_CPUV_Msk          (0x1U << DRV_CTRL_DIS_CPUV_Pos)
#define DRV_CTRL_DIS_CPUV              DRV_CTRL_DIS_CPUV_Msk
#define DRV_CTRL_DIS_GDF_Pos           (8U)
#define DRV_CTRL_DIS_GDF_Msk           (0x1U << DRV_CTRL_DIS_GDF_Pos)
#define DRV_CTRL_DIS_GDF               DRV_CTRL_DIS_GDF_Msk
#define DRV_CTRL_OTW_REP_Pos           (7U)
#define DRV_CTRL_OTW_REP_Msk           (0x1U << DRV_CTRL_OTW_REP_Pos)
#define DRV_CTRL_OTW_REP               DRV_CTRL_OTW_REP_Msk

#define DRV_CTRL_PWM_MODE_Pos          (5U)
#define DRV_CTRL_PWM_MODE_Msk          (0x3U << DRV_CTRL_PWM_MODE_Pos)
#define DRV_CTRL_PWM_MODE              DRV_CTRL_PWM_MODE_Msk
#define DRV_CTRL_PWM_MODE_0            (0x1U << DRV_CTRL_PWM_MODE_Pos)
#define DRV_CTRL_PWM_MODE_1            (0x2U << DRV_CTRL_PWM_MODE_Pos)
#define DRV_CTRL_PWM_MODE_6x           (0x0U << DRV_CTRL_PWM_MODE_Pos)
#define DRV_CTRL_PWM_MODE_3x           (0x1U << DRV_CTRL_PWM_MODE_Pos)
#define DRV_CTRL_PWM_MODE_1x           (0x2U << DRV_CTRL_PWM_MODE_Pos)
#define DRV_CTRL_PWM_MODE_IND          (0x3U << DRV_CTRL_PWM_MODE_Pos)

#define DRV_CTRL_1PWM_COM_Pos          (4U)
#define DRV_CTRL_1PWM_COM_Msk          (0x1U << DRV_CTRL_1PWM_COM_Pos)
#define DRV_CTRL_1PWM_COM              DRV_CTRL_1PWM_COM_Msk
#define DRV_CTRL_1PWM_DIR_Pos          (3U)
#define DRV_CTRL_1PWM_DIR_Msk          (0x1U <<DRV_CTRL_1PWM_DIR_Pos)
#define DRV_CTRL_1PWM_DIR              DRV_CTRL_1PWM_DIR_Msk
#define DRV_CTRL_COAST_Pos             (2U)
#define DRV_CTRL_COAST_Msk             (0x1U << DRV_CTRL_COAST_Pos)
#define DRV_CTRL_COAST                 DRV_CTRL_COAST_Msk
#define DRV_CTRL_BRAKE_Pos             (1U)
#define DRV_CTRL_BRAKE_Msk             (0x1U << DRV_CTRL_BRAKE_Pos)
#define DRV_CTRL_BRAKE                 DRV_CTRL_BRAKE_Msk
#define DRV_CTRL_CLR_FLT_Pos           (0U)
#define DRV_CTRL_CLR_FLT_Msk           (0x1U << DRV_CTRL_CLR_FLT_Pos)
#define DRV_CTRL_CLR_FLT               DRV_CTRL_CLR_FLT_Msk

/*******  Bit definitions for Gate Drive HS register  ********/
#define GATE_DRV_HS_LOCK_Pos           (8U)
#define GATE_DRV_HS_LOCK_Msk           (0x7U << GATE_DRV_HS_LOCK_Pos)
#define GATE_DRV_HS_LOCK               GATE_DRV_HS_LOCK_Msk
#define GATE_DRV_HS_LOCK_0             (0x1U << GATE_DRV_HS_LOCK_Pos)
#define GATE_DRV_HS_LOCK_1             (0x2U << GATE_DRV_HS_LOCK_Pos)
#define GATE_DRV_HS_LOCK_2             (0x4U << GATE_DRV_HS_LOCK_Pos)

#define GATE_DRV_HS_IDRIVEP_HS_Pos     (4U)
#define GATE_DRV_HS_IDRIVEP_HS_Msk     (0xFU << GATE_DRV_HS_IDRIVEP_HS_Pos)
#define GATE_DRV_HS_IDRIVEP_HS         GATE_DRV_HS_IDRIVEP_HS_Msk
#define GATE_DRV_HS_IDRIVEP_HS_0       (0x1U << GATE_DRV_HS_IDRIVEP_HS_Pos)
#define GATE_DRV_HS_IDRIVEP_HS_1       (0x2U << GATE_DRV_HS_IDRIVEP_HS_Pos)
#define GATE_DRV_HS_IDRIVEP_HS_2       (0x4U << GATE_DRV_HS_IDRIVEP_HS_Pos)
#define GATE_DRV_HS_IDRIVEP_HS_3       (0x8U << GATE_DRV_HS_IDRIVEP_HS_Pos)
#define GATE_DRV_HS_IDRIVEP_HS_10mA    (0x0U << GATE_DRV_HS_IDRIVEP_HS_Pos)
#define GATE_DRV_HS_IDRIVEP_HS_30mA    (0x1U << GATE_DRV_HS_IDRIVEP_HS_Pos)
#define GATE_DRV_HS_IDRIVEP_HS_60mA    (0x2U << GATE_DRV_HS_IDRIVEP_HS_Pos)
#define GATE_DRV_HS_IDRIVEP_HS_80mA    (0x3U << GATE_DRV_HS_IDRIVEP_HS_Pos)
#define GATE_DRV_HS_IDRIVEP_HS_120mA   (0x4U << GATE_DRV_HS_IDRIVEP_HS_Pos)
#define GATE_DRV_HS_IDRIVEP_HS_140mA   (0x5U << GATE_DRV_HS_IDRIVEP_HS_Pos)
#define GATE_DRV_HS_IDRIVEP_HS_170mA   (0x6U << GATE_DRV_HS_IDRIVEP_HS_Pos)
#define GATE_DRV_HS_IDRIVEP_HS_190mA   (0x7U << GATE_DRV_HS_IDRIVEP_HS_Pos)
#define GATE_DRV_HS_IDRIVEP_HS_260mA   (0x8U << GATE_DRV_HS_IDRIVEP_HS_Pos)
#define GATE_DRV_HS_IDRIVEP_HS_330mA   (0x9U << GATE_DRV_HS_IDRIVEP_HS_Pos)
#define GATE_DRV_HS_IDRIVEP_HS_370mA   (0xAU << GATE_DRV_HS_IDRIVEP_HS_Pos)
#define GATE_DRV_HS_IDRIVEP_HS_440mA   (0xBU << GATE_DRV_HS_IDRIVEP_HS_Pos)
#define GATE_DRV_HS_IDRIVEP_HS_570mA   (0xCU << GATE_DRV_HS_IDRIVEP_HS_Pos)
#define GATE_DRV_HS_IDRIVEP_HS_680mA   (0xDU << GATE_DRV_HS_IDRIVEP_HS_Pos)
#define GATE_DRV_HS_IDRIVEP_HS_820mA   (0xEU << GATE_DRV_HS_IDRIVEP_HS_Pos)
#define GATE_DRV_HS_IDRIVEP_HS_1000mA  (0xFU << GATE_DRV_HS_IDRIVEP_HS_Pos)

#define GATE_DRV_HS_IDRIVEN_HS_Pos     (0U)
#define GATE_DRV_HS_IDRIVEN_HS_Msk     (0xFU << GATE_DRV_HS_IDRIVEN_HS_Pos)
#define GATE_DRV_HS_IDRIVEN_HS         GATE_DRV_HS_IDRIVEN_HS_Msk
#define GATE_DRV_HS_IDRIVEN_HS_0       0x1U << GATE_DRV_HS_IDRIVEN_HS_Pos
#define GATE_DRV_HS_IDRIVEN_HS_1       0x2U << GATE_DRV_HS_IDRIVEN_HS_Pos
#define GATE_DRV_HS_IDRIVEN_HS_2       0x4U << GATE_DRV_HS_IDRIVEN_HS_Pos
#define GATE_DRV_HS_IDRIVEN_HS_3       0x8U << GATE_DRV_HS_IDRIVEN_HS_Pos
#define GATE_DRV_HS_IDRIVEN_HS_20mA    0x0U << GATE_DRV_HS_IDRIVEN_HS_Pos
#define GATE_DRV_HS_IDRIVEN_HS_60mA    0x1U << GATE_DRV_HS_IDRIVEN_HS_Pos
#define GATE_DRV_HS_IDRIVEN_HS_120mA   0x2U << GATE_DRV_HS_IDRIVEN_HS_Pos
#define GATE_DRV_HS_IDRIVEN_HS_160mA   0x3U << GATE_DRV_HS_IDRIVEN_HS_Pos
#define GATE_DRV_HS_IDRIVEN_HS_240mA   0x4U << GATE_DRV_HS_IDRIVEN_HS_Pos
#define GATE_DRV_HS_IDRIVEN_HS_280mA   0x5U << GATE_DRV_HS_IDRIVEN_HS_Pos
#define GATE_DRV_HS_IDRIVEN_HS_340mA   0x6U << GATE_DRV_HS_IDRIVEN_HS_Pos
#define GATE_DRV_HS_IDRIVEN_HS_380mA   0x7U << GATE_DRV_HS_IDRIVEN_HS_Pos
#define GATE_DRV_HS_IDRIVEN_HS_520mA   0x8U << GATE_DRV_HS_IDRIVEN_HS_Pos
#define GATE_DRV_HS_IDRIVEN_HS_660mA   0x9U << GATE_DRV_HS_IDRIVEN_HS_Pos
#define GATE_DRV_HS_IDRIVEN_HS_740mA   0xAU << GATE_DRV_HS_IDRIVEN_HS_Pos
#define GATE_DRV_HS_IDRIVEN_HS_880mA   0xBU << GATE_DRV_HS_IDRIVEN_HS_Pos
#define GATE_DRV_HS_IDRIVEN_HS_1140mA  0xCU << GATE_DRV_HS_IDRIVEN_HS_Pos
#define GATE_DRV_HS_IDRIVEN_HS_1360mA  0xDU << GATE_DRV_HS_IDRIVEN_HS_Pos
#define GATE_DRV_HS_IDRIVEN_HS_1640mA  0xEU << GATE_DRV_HS_IDRIVEN_HS_Pos
#define GATE_DRV_HS_IDRIVEN_HS_2000mA  0xFU << GATE_DRV_HS_IDRIVEN_HS_Pos

/*******  Bit definitions for Gate Drive LS register  ********/
#define GATE_DRV_LS_CBC_Pos            (10U)
#define GATE_DRV_LS_CBC_Msk            (0x7U << GATE_DRV_LS_LOCK_Pos)
#define GATE_DRV_LS_CBC                GATE_DRV_LS_LOCK_Msk
#define GATE_DRV_LS_TDRIVE_Pos         (8U)
#define GATE_DRV_LS_TDRIVE_Msk         (0x7U << GATE_DRV_LS_LOCK_Pos)
#define GATE_DRV_LS_TDRIVE             GATE_DRV_LS_LOCK_Msk
#define GATE_DRV_LS_TDRIVE_0           (0x1U << GATE_DRV_LS_TDRIVE_Pos)
#define GATE_DRV_LS_TDRIVE_1           (0x2U << GATE_DRV_LS_TDRIVE_Pos)
#define GATE_DRV_LS_TDRIVE_500ns       (0x0U << GATE_DRV_LS_TDRIVE_Pos)
#define GATE_DRV_LS_TDRIVE_1000ns      (0x1U << GATE_DRV_LS_TDRIVE_Pos)
#define GATE_DRV_LS_TDRIVE_2000ns      (0x2U << GATE_DRV_LS_TDRIVE_Pos)
#define GATE_DRV_LS_TDRIVE_4000ns      (0x3U << GATE_DRV_LS_TDRIVE_Pos)

#define GATE_DRV_LS_IDRIVEP_LS_Pos     (4U)
#define GATE_DRV_LS_IDRIVEP_LS_Msk     (0xF << GATE_DRV_LS_IDRIVEP_LS_Pos)
#define GATE_DRV_LS_IDRIVEP_LS         GATE_DRV_LS_IDRIVEP_LS_Msk
#define GATE_DRV_LS_IDRIVEP_LS_0       (0x1U << GATE_DRV_LS_IDRIVEP_LS_Pos)
#define GATE_DRV_LS_IDRIVEP_LS_1       (0x2U << GATE_DRV_LS_IDRIVEP_LS_Pos)
#define GATE_DRV_LS_IDRIVEP_LS_2       (0x4U << GATE_DRV_LS_IDRIVEP_LS_Pos)
#define GATE_DRV_LS_IDRIVEP_LS_3       (0x8U << GATE_DRV_LS_IDRIVEP_LS_Pos)
#define GATE_DRV_LS_IDRIVEP_LS_10mA    (0x0U << GATE_DRV_LS_IDRIVEP_LS_Pos)
#define GATE_DRV_LS_IDRIVEP_LS_30mA    (0x1U << GATE_DRV_LS_IDRIVEP_LS_Pos)
#define GATE_DRV_LS_IDRIVEP_LS_60mA    (0x2U << GATE_DRV_LS_IDRIVEP_LS_Pos)
#define GATE_DRV_LS_IDRIVEP_LS_80mA    (0x3U << GATE_DRV_LS_IDRIVEP_LS_Pos)
#define GATE_DRV_LS_IDRIVEP_LS_120mA   (0x4U << GATE_DRV_LS_IDRIVEP_LS_Pos)
#define GATE_DRV_LS_IDRIVEP_LS_140mA   (0x5U << GATE_DRV_LS_IDRIVEP_LS_Pos)
#define GATE_DRV_LS_IDRIVEP_LS_170mA   (0x6U << GATE_DRV_LS_IDRIVEP_LS_Pos)
#define GATE_DRV_LS_IDRIVEP_LS_190mA   (0x7U << GATE_DRV_LS_IDRIVEP_LS_Pos)
#define GATE_DRV_LS_IDRIVEP_LS_260mA   (0x8U << GATE_DRV_LS_IDRIVEP_LS_Pos)
#define GATE_DRV_LS_IDRIVEP_LS_330mA   (0x9U << GATE_DRV_LS_IDRIVEP_LS_Pos)
#define GATE_DRV_LS_IDRIVEP_LS_370mA   (0xAU << GATE_DRV_LS_IDRIVEP_LS_Pos)
#define GATE_DRV_LS_IDRIVEP_LS_440mA   (0xBU << GATE_DRV_LS_IDRIVEP_LS_Pos)
#define GATE_DRV_LS_IDRIVEP_LS_570mA   (0xCU << GATE_DRV_LS_IDRIVEP_LS_Pos)
#define GATE_DRV_LS_IDRIVEP_LS_680mA   (0xDU << GATE_DRV_LS_IDRIVEP_LS_Pos)
#define GATE_DRV_LS_IDRIVEP_LS_820mA   (0xEU << GATE_DRV_LS_IDRIVEP_LS_Pos)
#define GATE_DRV_LS_IDRIVEP_LS_1000mA  (0xFU << GATE_DRV_LS_IDRIVEP_LS_Pos)

#define GATE_DRV_LS_IDRIVEN_LS_Pos     (0U)
#define GATE_DRV_LS_IDRIVEN_LS_Msk     (0xFU << GATE_DRV_LS_IDRIVEN_LS_Pos)
#define GATE_DRV_LS_IDRIVEN_LS         GATE_DRV_LS_IDRIVEN_LS_Msk
#define GATE_DRV_LS_IDRIVEN_LS_0       (0x1U << GATE_DRV_LS_IDRIVEN_LS_Pos)
#define GATE_DRV_LS_IDRIVEN_LS_1       (0x2U << GATE_DRV_LS_IDRIVEN_LS_Pos)
#define GATE_DRV_LS_IDRIVEN_LS_2       (0x4U << GATE_DRV_LS_IDRIVEN_LS_Pos)
#define GATE_DRV_LS_IDRIVEN_LS_3       (0x8U << GATE_DRV_LS_IDRIVEN_LS_Pos)
#define GATE_DRV_LS_IDRIVEN_LS_20mA    (0x0U << GATE_DRV_LS_IDRIVEN_LS_Pos)
#define GATE_DRV_LS_IDRIVEN_LS_60mA    (0x1U << GATE_DRV_LS_IDRIVEN_LS_Pos)
#define GATE_DRV_LS_IDRIVEN_LS_120mA   (0x2U << GATE_DRV_LS_IDRIVEN_LS_Pos)
#define GATE_DRV_LS_IDRIVEN_LS_160mA   (0x3U << GATE_DRV_LS_IDRIVEN_LS_Pos)
#define GATE_DRV_LS_IDRIVEN_LS_240mA   (0x4U << GATE_DRV_LS_IDRIVEN_LS_Pos)
#define GATE_DRV_LS_IDRIVEN_LS_280mA   (0x5U << GATE_DRV_LS_IDRIVEN_LS_Pos)
#define GATE_DRV_LS_IDRIVEN_LS_340mA   (0x6U << GATE_DRV_LS_IDRIVEN_LS_Pos)
#define GATE_DRV_LS_IDRIVEN_LS_380mA   (0x7U << GATE_DRV_LS_IDRIVEN_LS_Pos)
#define GATE_DRV_LS_IDRIVEN_LS_520mA   (0x8U << GATE_DRV_LS_IDRIVEN_LS_Pos)
#define GATE_DRV_LS_IDRIVEN_LS_660mA   (0x9U << GATE_DRV_LS_IDRIVEN_LS_Pos)
#define GATE_DRV_LS_IDRIVEN_LS_740mA   (0xAU << GATE_DRV_LS_IDRIVEN_LS_Pos)
#define GATE_DRV_LS_IDRIVEN_LS_880mA   (0xBU << GATE_DRV_LS_IDRIVEN_LS_Pos)
#define GATE_DRV_LS_IDRIVEN_LS_1140mA  (0xCU << GATE_DRV_LS_IDRIVEN_LS_Pos)
#define GATE_DRV_LS_IDRIVEN_LS_1360mA  (0xDU << GATE_DRV_LS_IDRIVEN_LS_Pos)
#define GATE_DRV_LS_IDRIVEN_LS_1640mA  (0xEU << GATE_DRV_LS_IDRIVEN_LS_Pos)
#define GATE_DRV_LS_IDRIVEN_LS_2000mA  (0xFU << GATE_DRV_LS_IDRIVEN_LS_Pos)

/*******  Bit definitions for OCP Control register  **********/

#define OCP_CTRL_TRETRY_Pos         (10U)
#define OCP_CTRL_TRETRY_Msk         (0x1U << OCP_CTRL_TRETRY_Pos)
#define OCP_CTRL_TRETRY             OCP_CTRL_TRETRY_Msk
#define OCP_CTRL_TRETRY_4ms         (0x0U << OCP_CTRL_TRETRY_Pos)

#define OCP_CTRL_DEAD_TIME_Pos      (8U)
#define OCP_CTRL_DEAD_TIME_Msk      (0x3U << OCP_CTRL_DEAD_TIME_Pos)
#define OCP_CTRL_DEAD_TIME          OCP_CTRL_DEAD_TIME_Msk
#define OCP_CTRL_DEAD_TIME_0        (0x1U << OCP_CTRL_DEAD_TIME_Pos)
#define OCP_CTRL_DEAD_TIME_1        (0x2U << OCP_CTRL_DEAD_TIME_Pos)
#define OCP_CTRL_DEAD_TIME_50ns     (0x0U << OCP_CTRL_DEAD_TIME_Pos)
#define OCP_CTRL_DEAD_TIME_100ns    (0x1U << OCP_CTRL_DEAD_TIME_Pos)
#define OCP_CTRL_DEAD_TIME_200ns    (0x2U << OCP_CTRL_DEAD_TIME_Pos)
#define OCP_CTRL_DEAD_TIME_400ns    (0x3U << OCP_CTRL_DEAD_TIME_Pos)

#define OCP_CTRL_OCP_MODE_Pos       (6U)
#define OCP_CTRL_OCP_MODE_Msk       (0x3U << OCP_CTRL_OCP_MODE_Pos)
#define OCP_CTRL_OCP_MODE           OCP_CTRL_OCP_MODE_Msk
#define OCP_CTRL_OCP_MODE_0         (0x1U << OCP_CTRL_OCP_MODE_Pos)
#define OCP_CTRL_OCP_MODE_1         (0x2U << OCP_CTRL_OCP_MODE_Pos)
#define OCP_CTRL_OCP_MODE_LATCH     (0x0U << OCP_CTRL_OCP_MODE_Pos)
#define OCP_CTRL_OCP_MODE_RETRY     (0x1U << OCP_CTRL_OCP_MODE_Pos)
#define OCP_CTRL_OCP_MODE_REPORT    (0x2U << OCP_CTRL_OCP_MODE_Pos)
#define OCP_CTRL_OCP_MODE_NO_ACT    (0x3U << OCP_CTRL_OCP_MODE_Pos)

#define OCP_CTRL_OCP_DEG_Pos        (4U)
#define OCP_CTRL_OCP_DEG_Msk        (0x3U << OCP_CTRL_OCP_DEG_Pos)
#define OCP_CTRL_OCP_DEG            OCP_CTRL_OCP_DEG_Msk
#define OCP_CTRL_OCP_DEG_0          (0x1U << OCP_CTRL_OCP_DEG_Pos)
#define OCP_CTRL_OCP_DEG_1          (0x2U << OCP_CTRL_OCP_DEG_Pos)
#define OCP_CTRL_OCP_DEG_2us        (0x0U << OCP_CTRL_OCP_DEG_Pos)
#define OCP_CTRL_OCP_DEG_4us        (0x1U << OCP_CTRL_OCP_DEG_Pos)
#define OCP_CTRL_OCP_DEG_6us        (0x2U << OCP_CTRL_OCP_DEG_Pos)
#define OCP_CTRL_OCP_DEG_8us        (0x3U << OCP_CTRL_OCP_DEG_Pos)

#define OCP_CTRL_VDS_LVL_Pos        (0U)
#define OCP_CTRL_VDS_LVL_Msk        (0xFU << OCP_CTRL_VDS_LVL_Pos)
#define OCP_CTRL_VDS_LVL            OCP_CTRL_VDS_LVL_Msk
#define OCP_CTRL_VDS_LVL_0          (0x1U << OCP_CTRL_VDS_LVL_Pos)
#define OCP_CTRL_VDS_LVL_1          (0x2U << OCP_CTRL_VDS_LVL_Pos)
#define OCP_CTRL_VDS_LVL_2          (0x4U << OCP_CTRL_VDS_LVL_Pos)
#define OCP_CTRL_VDS_LVL_3          (0x8U << OCP_CTRL_VDS_LVL_Pos)
#define OCP_CTRL_VDS_LVL_0_06V      (0x0U << OCP_CTRL_VDS_LVL_Pos)
#define OCP_CTRL_VDS_LVL_0_13V      (0x1U << OCP_CTRL_VDS_LVL_Pos)
#define OCP_CTRL_VDS_LVL_0_20V      (0x2U << OCP_CTRL_VDS_LVL_Pos)
#define OCP_CTRL_VDS_LVL_0_26V      (0x3U << OCP_CTRL_VDS_LVL_Pos)
#define OCP_CTRL_VDS_LVL_0_31V      (0x4U << OCP_CTRL_VDS_LVL_Pos)
#define OCP_CTRL_VDS_LVL_0_45V      (0x5U << OCP_CTRL_VDS_LVL_Pos)
#define OCP_CTRL_VDS_LVL_0_53V      (0x6U << OCP_CTRL_VDS_LVL_Pos)
#define OCP_CTRL_VDS_LVL_0_60V      (0x7U << OCP_CTRL_VDS_LVL_Pos)
#define OCP_CTRL_VDS_LVL_0_68V      (0x8U << OCP_CTRL_VDS_LVL_Pos)
#define OCP_CTRL_VDS_LVL_0_75V      (0x9U << OCP_CTRL_VDS_LVL_Pos)
#define OCP_CTRL_VDS_LVL_0_94V      (0xAU << OCP_CTRL_VDS_LVL_Pos)
#define OCP_CTRL_VDS_LVL_1_13V      (0xBU << OCP_CTRL_VDS_LVL_Pos)
#define OCP_CTRL_VDS_LVL_1_30V      (0xCU << OCP_CTRL_VDS_LVL_Pos)
#define OCP_CTRL_VDS_LVL_1_50V      (0xDU << OCP_CTRL_VDS_LVL_Pos)
#define OCP_CTRL_VDS_LVL_1_70V      (0xEU << OCP_CTRL_VDS_LVL_Pos)
#define OCP_CTRL_VDS_LVL_1_88V      (0xFU << OCP_CTRL_VDS_LVL_Pos)

/*******  Bit definitions for CSA Control register  **********/
#define CSA_CTRL_CSA_FET_Pos        (10U)
#define CSA_CTRL_CSA_FET_Msk        (0x1U << CSA_CTRL_CSA_FET_Pos)
#define CSA_CTRL_CSA_FET            CSA_CTRL_CSA_FET_Msk
#define CSA_CTRL_CSA_FET_SPx        (0x0U << CSA_CTRL_CSA_FET_Pos)


#define CSA_CTRL_VREF_DIV_Pos       (9U)
#define CSA_CTRL_VREF_DIV_Msk       (0x1U << CSA_CTRL_VREF_DIV_Pos)
#define CSA_CTRL_VREF_DIV           CSA_CTRL_VREF_DIV_Msk
#define CSA_CTRL_VREF_DIV_2         (0x1U << CSA_CTRL_VREF_DIV_Pos)

#define CSA_CTRL_LS_REF_Pos         (8U)
#define CSA_CTRL_LS_REF_Msk         (0x1U << CSA_CTRL_LS_REF_Pos)
#define CSA_CTRL_LS_REF             CSA_CTRL_LS_REF_Msk
#define CSA_CTRL_LS_REF_Spx         (0x0U << CSA_CTRL_LS_REF_Pos)

///CSA GAIN Settings
#define CSA_CTRL_CSA_GAIN_Pos       (6U)
#define CSA_CTRL_CSA_GAIN_Msk       (0x3U << CSA_CTRL_CSA_GAIN_Pos)
#define CSA_CTRL_CSA_GAIN           CSA_CTRL_CSA_GAIN_Msk

typedef enum 
{
CSA_CTRL_CSA_GAIN_0     =    (0x1U << CSA_CTRL_CSA_GAIN_Pos),
CSA_CTRL_CSA_GAIN_1     =    (0x2U << CSA_CTRL_CSA_GAIN_Pos),
CSA_CTRL_CSA_GAIN_5VV   =    (0x0U << CSA_CTRL_CSA_GAIN_Pos),
CSA_CTRL_CSA_GAIN_10VV  =    (0x1U << CSA_CTRL_CSA_GAIN_Pos),
CSA_CTRL_CSA_GAIN_20VV  =    (0x2U << CSA_CTRL_CSA_GAIN_Pos),
CSA_CTRL_CSA_GAIN_40VV  =    (0x3U << CSA_CTRL_CSA_GAIN_Pos)

} DRV8323_ShuntAmpGain_e;

#define CSA_CTRL_DIS_EN_Pos         (5U)
#define CSA_CTRL_DIS_EN_Msk         (0x1U << CSA_CTRL_DIS_EN_Pos)
#define CSA_CTRL_DIS_EN             CSA_CTRL_DIS_EN_Msk
#define CSA_CTRL_DIS_EN_0         (0x0U << CSA_CTRL_DIS_EN_Pos)


#define CSA_CTRL_CSA_CAL_A_Pos      (4U)
#define CSA_CTRL_CSA_CAL_A_Msk      (0x1U << CSA_CTRL_CSA_CAL_A_Pos)
#define CSA_CTRL_CSA_CAL_A          CSA_CTRL_CSA_CAL_A_Msk
#define CSA_CTRL_CSA_CAL_B_Pos      (3U)
#define CSA_CTRL_CSA_CAL_B_Msk      (0x1U << CSA_CTRL_CSA_CAL_B_Pos)
#define CSA_CTRL_CSA_CAL_B          CSA_CTRL_CSA_CAL_B_Msk
#define CSA_CTRL_CSA_CAL_C_Pos      (2U)
#define CSA_CTRL_CSA_CAL_C_Msk      (0x1U << CSA_CTRL_CSA_CAL_C_Pos)
#define CSA_CTRL_CSA_CAL_C          CSA_CTRL_CSA_CAL_C_Msk

#define CSA_CTRL_SEN_LVL_Pos        (0U)
#define CSA_CTRL_SEN_LVL_Msk        (0x3U << CSA_CTRL_SEN_LVL_Pos)
#define CSA_CTRL_SEN_LVL            CSA_CTRL_SEN_LVL_Msk
#define CSA_CTRL_SEN_LVL_0          (0x1U << CSA_CTRL_SEN_LVL_Pos)
#define CSA_CTRL_SEN_LVL_1          (0x2U << CSA_CTRL_SEN_LVL_Pos)
#define CSA_CTRL_SEN_LVL_0_25V      (0x0U << CSA_CTRL_SEN_LVL_Pos)
#define CSA_CTRL_SEN_LVL_0_50V      (0x1U << CSA_CTRL_SEN_LVL_Pos)
#define CSA_CTRL_SEN_LVL_0_75V      (0x2U << CSA_CTRL_SEN_LVL_Pos)
#define CSA_CTRL_SEN_LVL_1_00V      (0x3U << CSA_CTRL_SEN_LVL_Pos)




/************************************************ */
// Port
typedef SPI_HandleTypeDef* SPI_Handle;
typedef GPIO_TypeDef* GPIO_Handle;
typedef uint16_t GPIO_Number_e;

//! \brief Defines the DRV8323 object
//!
typedef struct _DRV8323_Obj_
{
  SPI_Handle       spiHandle;                  //!< the handle for the serial peripheral interface
  GPIO_Handle      EngpioHandle;               //!< the gpio handle that is connected to the drv8301 enable pin
  GPIO_Number_e    EngpioNumber;               //!< the gpio number that is connected to the drv8301 enable pin
  GPIO_Handle      nCSgpioHandle;              //!< the gpio handle that is connected to the drv8301 nCS pin
  GPIO_Number_e    nCSgpioNumber;               //!< the gpio number that is connected to the drv8301 nCS pin
  bool             RxTimeOut;                  //!< the timeout flag for the RX fifo
  bool             enableTimeOut;              //!< the timeout flag for drv8301 enable
  bool             SPIenabled;
  bool             lastCheckOutcome;
  uint16_t         failCounter;
  uint32_t         lastCheckTime;
} DRV8323_Obj;


//! \brief Defines the DRV8323 handle
//!
typedef struct _DRV8323_Obj_ *DRV8323_Handle;


void DRV8323_enable(DRV8323_Handle handle);
uint16_t DRV8323_readSpi(DRV8323_Handle handle, uint8_t regAdr);
void DRV8323_writeSpi(DRV8323_Handle handle, uint8_t regAdr, uint16_t regVal);
void DRV8323_setupSpi(DRV8323_Handle handle);
uint16_t get_spi_fail_count();

#ifdef __cplusplus
}
#endif
#endif //_DRV8323_H_
