#include "gd32f4xx.h"
#include "systick.h"
#include <stdio.h>
#include "main.h"

#include "math.h"
#include "arm_math.h"

#include "bsp_nvic.h"

#include "gpio.h"
#include "dma.h"
#include "dac.h"
#include "adc.h"
#include "tim.h"
#include "spi.h"

#include "bsp_led.h"
#include "bsp_key.h"
#include "bsp_usart.h"
#include "tim.h"
// #include "bsp_pwm.h"
#include "bsp_lcd.h"
#include "bsp_sdram_exmc.h"
#include "bsp_norflash_spi.h"
// #include "retarget.h"

#include "bl1555.h"
#include "pga113.h"

#ifdef USE_FREERTOS
#include "FreeRTOS.h"
#include "task.h"
#endif
#include "my_app.h"

__attribute__((section("CCMRAM"))) uint8_t ucHeap[configTOTAL_HEAP_SIZE];

void bsp_Init(void)
{
    /* 开启系统配置时钟 */
    rcu_periph_clock_enable(RCU_SYSCFG);
    nvic_config();
    systick_config();
    gpio_config();
    bsp_key_config();
    dma_config();
    dac_config();
    adc_config();
    bsp_spi_config();
    bsp_init_extsdram(EXMC_SDRAM_DEVICE0);

    bl1555_config();
    PAout(8) = 1;
    pga11x_config();
    pga113_set_gain(PGA11X_CMD_WRITE | PGA11X_GAIN1 << 4 | PGA11X_CH1);
    PAout(15) = 1;

    timer_clk_config();
    tim2_enable();
    tim3_enable();
    tim5_config(240, 10);  // 1M 1 100->10k 1M 10 100->1k
    tim6_config(240, 100); // 100us
    usart_gpio_config();
    LCD_Init();
    delay_1ms(10);
    printf("BSP Init Complete.\n");
}

/**
 * @brief 主函数
 *
 * @return int
 */
int main(void)
{

    /*
     在启动调度前，为了防止初始化 STM32 外设时有中断服务程序执行，这里禁止全局中断(除了 NMI 和 HardFault)。
     这样做的好处是：
     1. 防止执行的中断服务程序中有 FreeRTOS 的 API 函数。
     2. 保证系统正常启动，不受别的中断影响。
     3. 关于是否关闭全局中断，大家根据自己的实际情况设置即可。
     在移植文件 port.c 中的函数 prvStartFirstTask 中会重新开启全局中断。通过指令 cpsie i 开启，__set_PRIMASK(1)
     和 cpsie i 是等效的。
     */
    // __set_PRIMASK(1);

    /* 硬件初始化 */
    bsp_Init();
    // bsp_sdram_test();
    /* 进入FreeRTOS */
    app_main();

    // bsp_spi_norflash_init();
    //    basic_timer_config(24000, 10000);
    // pwm_config(240, 10000);
    // bsp_init_extsdram(EXMC_SDRAM_DEVICE0);
    // printf("Initialization Complate!\n");
    // printf("Get Flash ID: %X\n", norflash_read_JEDEC_ID());

    /*
    如果系统正常启动是不会运行到这里的，运行到这里极有可能是用于定时器任务或者空闲任务的
    heap 空间不足造成创建失败，此要加大 FreeRTOSConfig.h 文件中定义的 heap 大小：
    #define configTOTAL_HEAP_SIZE ( ( size_t ) ( 30 * 1024 ) )
    */
    while (1) {
        printf("Error Soft Process. Check FreeRTOS Heap.");
        delay_1ms(1000);
    }
}

void __aeabi_assert(const char *err, const char *file, int line)
{
    /* 输出内容自己定 */
    printf("Wrong parameters value: file %s on line %d\r\n", file, line);
}