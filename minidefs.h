#include <stdint.h>

#define WDOG_UNLOCK             *(volatile uint16_t *)0x4005200E // Watchdog Unlock register
#define WDOG_UNLOCK_SEQ1                (uint16_t)0xC520
#define WDOG_UNLOCK_SEQ2                (uint16_t)0xD928
#define WDOG_STCTRLH            *(volatile uint16_t *)0x40052000 // Watchdog Status and Control Register High
#define WDOG_STCTRLH_ALLOWUPDATE        (uint16_t)0x0010

#define SIM_SCGC5               *(volatile uint32_t *)0x40048038 // System Clock Gating Control Register 5

#define MCG_C4                  *(volatile uint8_t  *)0x40064003 // MCG Control 4 Register

#define GPIOA_PDOR              *(volatile uint32_t *)0x400FF000 // Port Data Output Register
#define GPIOA_PSOR              *(volatile uint32_t *)0x400FF004 // Port Set Output Register
#define GPIOA_PCOR              *(volatile uint32_t *)0x400FF008 // Port Clear Output Register
#define GPIOA_PTOR              *(volatile uint32_t *)0x400FF00C // Port Toggle Output Register
#define GPIOA_PDIR              *(volatile uint32_t *)0x400FF010 // Port Data Input Register
#define GPIOA_PDDR              *(volatile uint32_t *)0x400FF014 // Port Data Direction Register
#define GPIOB_PDOR              *(volatile uint32_t *)0x400FF040 // Port Data Output Register
#define GPIOB_PSOR              *(volatile uint32_t *)0x400FF044 // Port Set Output Register
#define GPIOB_PCOR              *(volatile uint32_t *)0x400FF048 // Port Clear Output Register
#define GPIOB_PTOR              *(volatile uint32_t *)0x400FF04C // Port Toggle Output Register
#define GPIOB_PDIR              *(volatile uint32_t *)0x400FF050 // Port Data Input Register
#define GPIOB_PDDR              *(volatile uint32_t *)0x400FF054 // Port Data Direction Register
#define GPIOC_PDOR              *(volatile uint32_t *)0x400FF080 // Port Data Output Register
#define GPIOC_PSOR              *(volatile uint32_t *)0x400FF084 // Port Set Output Register
#define GPIOC_PCOR              *(volatile uint32_t *)0x400FF088 // Port Clear Output Register
#define GPIOC_PTOR              *(volatile uint32_t *)0x400FF08C // Port Toggle Output Register
#define GPIOC_PDIR              *(volatile uint32_t *)0x400FF090 // Port Data Input Register
#define GPIOC_PDDR              *(volatile uint32_t *)0x400FF094 // Port Data Direction Register
#define GPIOD_PDOR              *(volatile uint32_t *)0x400FF0C0 // Port Data Output Register
#define GPIOD_PSOR              *(volatile uint32_t *)0x400FF0C4 // Port Set Output Register
#define GPIOD_PCOR              *(volatile uint32_t *)0x400FF0C8 // Port Clear Output Register
#define GPIOD_PTOR              *(volatile uint32_t *)0x400FF0CC // Port Toggle Output Register
#define GPIOD_PDIR              *(volatile uint32_t *)0x400FF0D0 // Port Data Input Register
#define GPIOD_PDDR              *(volatile uint32_t *)0x400FF0D4 // Port Data Direction Register
#define GPIOE_PDOR              *(volatile uint32_t *)0x400FF100 // Port Data Output Register
#define GPIOE_PSOR              *(volatile uint32_t *)0x400FF104 // Port Set Output Register
#define GPIOE_PCOR              *(volatile uint32_t *)0x400FF108 // Port Clear Output Register
#define GPIOE_PTOR              *(volatile uint32_t *)0x400FF10C // Port Toggle Output Register
#define GPIOE_PDIR              *(volatile uint32_t *)0x400FF110 // Port Data Input Register
#define GPIOE_PDDR              *(volatile uint32_t *)0x400FF114 // Port Data Direction Register

// chapter 11: Port control and interrupts (PORT)
#define PORTA_PCR0              *(volatile uint32_t *)0x40049000 // Pin Control Register n
#define PORT_PCR_ISF                    (uint32_t)0x01000000            // Interrupt Status Flag
#define PORT_PCR_IRQC(n)                (uint32_t)(((n) & 15) << 16)    // Interrupt Configuration
#define PORT_PCR_IRQC_MASK              (uint32_t)0x000F0000
#define PORT_PCR_LK                     (uint32_t)0x00008000            // Lock Register
#define PORT_PCR_MUX(n)                 (uint32_t)(((n) & 7) << 8)      // Pin Mux Control
#define PORT_PCR_MUX_MASK               (uint32_t)0x00000700
#define PORT_PCR_DSE                    (uint32_t)0x00000040            // Drive Strength Enable
#define PORT_PCR_ODE                    (uint32_t)0x00000020            // Open Drain Enable
#define PORT_PCR_PFE                    (uint32_t)0x00000010            // Passive Filter Enable
#define PORT_PCR_SRE                    (uint32_t)0x00000004            // Slew Rate Enable
#define PORT_PCR_PE                     (uint32_t)0x00000002            // Pull Enable
#define PORT_PCR_PS                     (uint32_t)0x00000001            // Pull Select
#define PORTA_PCR1              *(volatile uint32_t *)0x40049004 // Pin Control Register n
#define PORTA_PCR2              *(volatile uint32_t *)0x40049008 // Pin Control Register n
#define PORTA_PCR3              *(volatile uint32_t *)0x4004900C // Pin Control Register n
#define PORTA_PCR4              *(volatile uint32_t *)0x40049010 // Pin Control Register n
#define PORTA_PCR5              *(volatile uint32_t *)0x40049014 // Pin Control Register n
#define PORTA_PCR6              *(volatile uint32_t *)0x40049018 // Pin Control Register n
#define PORTA_PCR7              *(volatile uint32_t *)0x4004901C // Pin Control Register n
#define PORTA_PCR8              *(volatile uint32_t *)0x40049020 // Pin Control Register n
#define PORTA_PCR9              *(volatile uint32_t *)0x40049024 // Pin Control Register n
#define PORTA_PCR10             *(volatile uint32_t *)0x40049028 // Pin Control Register n
#define PORTA_PCR11             *(volatile uint32_t *)0x4004902C // Pin Control Register n
#define PORTA_PCR12             *(volatile uint32_t *)0x40049030 // Pin Control Register n
#define PORTA_PCR13             *(volatile uint32_t *)0x40049034 // Pin Control Register n
#define PORTA_PCR14             *(volatile uint32_t *)0x40049038 // Pin Control Register n
#define PORTA_PCR15             *(volatile uint32_t *)0x4004903C // Pin Control Register n
#define PORTA_PCR16             *(volatile uint32_t *)0x40049040 // Pin Control Register n
#define PORTA_PCR17             *(volatile uint32_t *)0x40049044 // Pin Control Register n
#define PORTA_PCR18             *(volatile uint32_t *)0x40049048 // Pin Control Register n
#define PORTA_PCR19             *(volatile uint32_t *)0x4004904C // Pin Control Register n
#define PORTA_PCR20             *(volatile uint32_t *)0x40049050 // Pin Control Register n
#define PORTA_PCR21             *(volatile uint32_t *)0x40049054 // Pin Control Register n
#define PORTA_PCR22             *(volatile uint32_t *)0x40049058 // Pin Control Register n
#define PORTA_PCR23             *(volatile uint32_t *)0x4004905C // Pin Control Register n
#define PORTA_PCR24             *(volatile uint32_t *)0x40049060 // Pin Control Register n
#define PORTA_PCR25             *(volatile uint32_t *)0x40049064 // Pin Control Register n
#define PORTA_PCR26             *(volatile uint32_t *)0x40049068 // Pin Control Register n
#define PORTA_PCR27             *(volatile uint32_t *)0x4004906C // Pin Control Register n
#define PORTA_PCR28             *(volatile uint32_t *)0x40049070 // Pin Control Register n
#define PORTA_PCR29             *(volatile uint32_t *)0x40049074 // Pin Control Register n
#define PORTA_PCR30             *(volatile uint32_t *)0x40049078 // Pin Control Register n
#define PORTA_PCR31             *(volatile uint32_t *)0x4004907C // Pin Control Register n
#define PORTA_GPCLR             *(volatile uint32_t *)0x40049080 // Global Pin Control Low Register
#define PORTA_GPCHR             *(volatile uint32_t *)0x40049084 // Global Pin Control High Register
#define PORTA_ISFR              *(volatile uint32_t *)0x400490A0 // Interrupt Status Flag Register
#define PORTB_PCR0              *(volatile uint32_t *)0x4004A000 // Pin Control Register n
#define PORTB_PCR1              *(volatile uint32_t *)0x4004A004 // Pin Control Register n
#define PORTB_PCR2              *(volatile uint32_t *)0x4004A008 // Pin Control Register n
#define PORTB_PCR3              *(volatile uint32_t *)0x4004A00C // Pin Control Register n
#define PORTB_PCR4              *(volatile uint32_t *)0x4004A010 // Pin Control Register n
#define PORTB_PCR5              *(volatile uint32_t *)0x4004A014 // Pin Control Register n
#define PORTB_PCR6              *(volatile uint32_t *)0x4004A018 // Pin Control Register n
#define PORTB_PCR7              *(volatile uint32_t *)0x4004A01C // Pin Control Register n
#define PORTB_PCR8              *(volatile uint32_t *)0x4004A020 // Pin Control Register n
#define PORTB_PCR9              *(volatile uint32_t *)0x4004A024 // Pin Control Register n
#define PORTB_PCR10             *(volatile uint32_t *)0x4004A028 // Pin Control Register n
#define PORTB_PCR11             *(volatile uint32_t *)0x4004A02C // Pin Control Register n
#define PORTB_PCR12             *(volatile uint32_t *)0x4004A030 // Pin Control Register n
#define PORTB_PCR13             *(volatile uint32_t *)0x4004A034 // Pin Control Register n
#define PORTB_PCR14             *(volatile uint32_t *)0x4004A038 // Pin Control Register n
#define PORTB_PCR15             *(volatile uint32_t *)0x4004A03C // Pin Control Register n
#define PORTB_PCR16             *(volatile uint32_t *)0x4004A040 // Pin Control Register n
#define PORTB_PCR17             *(volatile uint32_t *)0x4004A044 // Pin Control Register n
#define PORTB_PCR18             *(volatile uint32_t *)0x4004A048 // Pin Control Register n
#define PORTB_PCR19             *(volatile uint32_t *)0x4004A04C // Pin Control Register n
#define PORTB_PCR20             *(volatile uint32_t *)0x4004A050 // Pin Control Register n
#define PORTB_PCR21             *(volatile uint32_t *)0x4004A054 // Pin Control Register n
#define PORTB_PCR22             *(volatile uint32_t *)0x4004A058 // Pin Control Register n
#define PORTB_PCR23             *(volatile uint32_t *)0x4004A05C // Pin Control Register n
#define PORTB_PCR24             *(volatile uint32_t *)0x4004A060 // Pin Control Register n
#define PORTB_PCR25             *(volatile uint32_t *)0x4004A064 // Pin Control Register n
#define PORTB_PCR26             *(volatile uint32_t *)0x4004A068 // Pin Control Register n
#define PORTB_PCR27             *(volatile uint32_t *)0x4004A06C // Pin Control Register n
#define PORTB_PCR28             *(volatile uint32_t *)0x4004A070 // Pin Control Register n
#define PORTB_PCR29             *(volatile uint32_t *)0x4004A074 // Pin Control Register n
#define PORTB_PCR30             *(volatile uint32_t *)0x4004A078 // Pin Control Register n
#define PORTB_PCR31             *(volatile uint32_t *)0x4004A07C // Pin Control Register n
#define PORTB_GPCLR             *(volatile uint32_t *)0x4004A080 // Global Pin Control Low Register
#define PORTB_GPCHR             *(volatile uint32_t *)0x4004A084 // Global Pin Control High Register
#define PORTB_ISFR              *(volatile uint32_t *)0x4004A0A0 // Interrupt Status Flag Register
#define PORTC_PCR0              *(volatile uint32_t *)0x4004B000 // Pin Control Register n
#define PORTC_PCR1              *(volatile uint32_t *)0x4004B004 // Pin Control Register n
#define PORTC_PCR2              *(volatile uint32_t *)0x4004B008 // Pin Control Register n
#define PORTC_PCR3              *(volatile uint32_t *)0x4004B00C // Pin Control Register n
#define PORTC_PCR4              *(volatile uint32_t *)0x4004B010 // Pin Control Register n
#define PORTC_PCR5              *(volatile uint32_t *)0x4004B014 // Pin Control Register n
#define PORTC_PCR6              *(volatile uint32_t *)0x4004B018 // Pin Control Register n
#define PORTC_PCR7              *(volatile uint32_t *)0x4004B01C // Pin Control Register n
#define PORTC_PCR8              *(volatile uint32_t *)0x4004B020 // Pin Control Register n
#define PORTC_PCR9              *(volatile uint32_t *)0x4004B024 // Pin Control Register n
#define PORTC_PCR10             *(volatile uint32_t *)0x4004B028 // Pin Control Register n
#define PORTC_PCR11             *(volatile uint32_t *)0x4004B02C // Pin Control Register n
#define PORTC_PCR12             *(volatile uint32_t *)0x4004B030 // Pin Control Register n
#define PORTC_PCR13             *(volatile uint32_t *)0x4004B034 // Pin Control Register n
#define PORTC_PCR14             *(volatile uint32_t *)0x4004B038 // Pin Control Register n
#define PORTC_PCR15             *(volatile uint32_t *)0x4004B03C // Pin Control Register n
#define PORTC_PCR16             *(volatile uint32_t *)0x4004B040 // Pin Control Register n
#define PORTC_PCR17             *(volatile uint32_t *)0x4004B044 // Pin Control Register n
#define PORTC_PCR18             *(volatile uint32_t *)0x4004B048 // Pin Control Register n
#define PORTC_PCR19             *(volatile uint32_t *)0x4004B04C // Pin Control Register n
#define PORTC_PCR20             *(volatile uint32_t *)0x4004B050 // Pin Control Register n
#define PORTC_PCR21             *(volatile uint32_t *)0x4004B054 // Pin Control Register n
#define PORTC_PCR22             *(volatile uint32_t *)0x4004B058 // Pin Control Register n
#define PORTC_PCR23             *(volatile uint32_t *)0x4004B05C // Pin Control Register n
#define PORTC_PCR24             *(volatile uint32_t *)0x4004B060 // Pin Control Register n
#define PORTC_PCR25             *(volatile uint32_t *)0x4004B064 // Pin Control Register n
#define PORTC_PCR26             *(volatile uint32_t *)0x4004B068 // Pin Control Register n
#define PORTC_PCR27             *(volatile uint32_t *)0x4004B06C // Pin Control Register n
#define PORTC_PCR28             *(volatile uint32_t *)0x4004B070 // Pin Control Register n
#define PORTC_PCR29             *(volatile uint32_t *)0x4004B074 // Pin Control Register n
#define PORTC_PCR30             *(volatile uint32_t *)0x4004B078 // Pin Control Register n
#define PORTC_PCR31             *(volatile uint32_t *)0x4004B07C // Pin Control Register n
#define PORTC_GPCLR             *(volatile uint32_t *)0x4004B080 // Global Pin Control Low Register
#define PORTC_GPCHR             *(volatile uint32_t *)0x4004B084 // Global Pin Control High Register
#define PORTC_ISFR              *(volatile uint32_t *)0x4004B0A0 // Interrupt Status Flag Register
#define PORTD_PCR0              *(volatile uint32_t *)0x4004C000 // Pin Control Register n
#define PORTD_PCR1              *(volatile uint32_t *)0x4004C004 // Pin Control Register n
#define PORTD_PCR2              *(volatile uint32_t *)0x4004C008 // Pin Control Register n
#define PORTD_PCR3              *(volatile uint32_t *)0x4004C00C // Pin Control Register n
#define PORTD_PCR4              *(volatile uint32_t *)0x4004C010 // Pin Control Register n
#define PORTD_PCR5              *(volatile uint32_t *)0x4004C014 // Pin Control Register n
#define PORTD_PCR6              *(volatile uint32_t *)0x4004C018 // Pin Control Register n
#define PORTD_PCR7              *(volatile uint32_t *)0x4004C01C // Pin Control Register n
#define PORTD_PCR8              *(volatile uint32_t *)0x4004C020 // Pin Control Register n
#define PORTD_PCR9              *(volatile uint32_t *)0x4004C024 // Pin Control Register n
#define PORTD_PCR10             *(volatile uint32_t *)0x4004C028 // Pin Control Register n
#define PORTD_PCR11             *(volatile uint32_t *)0x4004C02C // Pin Control Register n
#define PORTD_PCR12             *(volatile uint32_t *)0x4004C030 // Pin Control Register n
#define PORTD_PCR13             *(volatile uint32_t *)0x4004C034 // Pin Control Register n
#define PORTD_PCR14             *(volatile uint32_t *)0x4004C038 // Pin Control Register n
#define PORTD_PCR15             *(volatile uint32_t *)0x4004C03C // Pin Control Register n
#define PORTD_PCR16             *(volatile uint32_t *)0x4004C040 // Pin Control Register n
#define PORTD_PCR17             *(volatile uint32_t *)0x4004C044 // Pin Control Register n
#define PORTD_PCR18             *(volatile uint32_t *)0x4004C048 // Pin Control Register n
#define PORTD_PCR19             *(volatile uint32_t *)0x4004C04C // Pin Control Register n
#define PORTD_PCR20             *(volatile uint32_t *)0x4004C050 // Pin Control Register n
#define PORTD_PCR21             *(volatile uint32_t *)0x4004C054 // Pin Control Register n
#define PORTD_PCR22             *(volatile uint32_t *)0x4004C058 // Pin Control Register n
#define PORTD_PCR23             *(volatile uint32_t *)0x4004C05C // Pin Control Register n
#define PORTD_PCR24             *(volatile uint32_t *)0x4004C060 // Pin Control Register n
#define PORTD_PCR25             *(volatile uint32_t *)0x4004C064 // Pin Control Register n
#define PORTD_PCR26             *(volatile uint32_t *)0x4004C068 // Pin Control Register n
#define PORTD_PCR27             *(volatile uint32_t *)0x4004C06C // Pin Control Register n
#define PORTD_PCR28             *(volatile uint32_t *)0x4004C070 // Pin Control Register n
#define PORTD_PCR29             *(volatile uint32_t *)0x4004C074 // Pin Control Register n
#define PORTD_PCR30             *(volatile uint32_t *)0x4004C078 // Pin Control Register n
#define PORTD_PCR31             *(volatile uint32_t *)0x4004C07C // Pin Control Register n
#define PORTD_GPCLR             *(volatile uint32_t *)0x4004C080 // Global Pin Control Low Register
#define PORTD_GPCHR             *(volatile uint32_t *)0x4004C084 // Global Pin Control High Register
#define PORTD_ISFR              *(volatile uint32_t *)0x4004C0A0 // Interrupt Status Flag Register
#define PORTE_PCR0              *(volatile uint32_t *)0x4004D000 // Pin Control Register n
#define PORTE_PCR1              *(volatile uint32_t *)0x4004D004 // Pin Control Register n
#define PORTE_PCR2              *(volatile uint32_t *)0x4004D008 // Pin Control Register n
#define PORTE_PCR3              *(volatile uint32_t *)0x4004D00C // Pin Control Register n
#define PORTE_PCR4              *(volatile uint32_t *)0x4004D010 // Pin Control Register n
#define PORTE_PCR5              *(volatile uint32_t *)0x4004D014 // Pin Control Register n
#define PORTE_PCR6              *(volatile uint32_t *)0x4004D018 // Pin Control Register n
#define PORTE_PCR7              *(volatile uint32_t *)0x4004D01C // Pin Control Register n
#define PORTE_PCR8              *(volatile uint32_t *)0x4004D020 // Pin Control Register n
#define PORTE_PCR9              *(volatile uint32_t *)0x4004D024 // Pin Control Register n
#define PORTE_PCR10             *(volatile uint32_t *)0x4004D028 // Pin Control Register n
#define PORTE_PCR11             *(volatile uint32_t *)0x4004D02C // Pin Control Register n
#define PORTE_PCR12             *(volatile uint32_t *)0x4004D030 // Pin Control Register n
#define PORTE_PCR13             *(volatile uint32_t *)0x4004D034 // Pin Control Register n
#define PORTE_PCR14             *(volatile uint32_t *)0x4004D038 // Pin Control Register n
#define PORTE_PCR15             *(volatile uint32_t *)0x4004D03C // Pin Control Register n
#define PORTE_PCR16             *(volatile uint32_t *)0x4004D040 // Pin Control Register n
#define PORTE_PCR17             *(volatile uint32_t *)0x4004D044 // Pin Control Register n
#define PORTE_PCR18             *(volatile uint32_t *)0x4004D048 // Pin Control Register n
#define PORTE_PCR19             *(volatile uint32_t *)0x4004D04C // Pin Control Register n
#define PORTE_PCR20             *(volatile uint32_t *)0x4004D050 // Pin Control Register n
#define PORTE_PCR21             *(volatile uint32_t *)0x4004D054 // Pin Control Register n
#define PORTE_PCR22             *(volatile uint32_t *)0x4004D058 // Pin Control Register n
#define PORTE_PCR23             *(volatile uint32_t *)0x4004D05C // Pin Control Register n
#define PORTE_PCR24             *(volatile uint32_t *)0x4004D060 // Pin Control Register n
#define PORTE_PCR25             *(volatile uint32_t *)0x4004D064 // Pin Control Register n
#define PORTE_PCR26             *(volatile uint32_t *)0x4004D068 // Pin Control Register n
#define PORTE_PCR27             *(volatile uint32_t *)0x4004D06C // Pin Control Register n
#define PORTE_PCR28             *(volatile uint32_t *)0x4004D070 // Pin Control Register n
#define PORTE_PCR29             *(volatile uint32_t *)0x4004D074 // Pin Control Register n
#define PORTE_PCR30             *(volatile uint32_t *)0x4004D078 // Pin Control Register n
#define PORTE_PCR31             *(volatile uint32_t *)0x4004D07C // Pin Control Register n
#define PORTE_GPCLR             *(volatile uint32_t *)0x4004D080 // Global Pin Control Low Register
#define PORTE_GPCHR             *(volatile uint32_t *)0x4004D084 // Global Pin Control High Register
#define PORTE_ISFR              *(volatile uint32_t *)0x4004D0A0 // Interrupt Status Flag Register

