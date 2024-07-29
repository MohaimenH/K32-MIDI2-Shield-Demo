//#include <stdlib.h>
//#include <stdio.h>
//#include <string.h>
//
//#include "bsp/board_api.h"
//#include "tusb.h"
//#include "K32L2B31A.h"
//
//#define MASK(x) (1UL << (x))
//
//// Define pins for buttons and potentiometers
//#define BUTTON1_PIN 3   // D3
//#define BUTTON2_PIN 12  // A12
//#define BUTTON3_PIN 4   // A4
//#define POT1_PIN 1      // B1
//#define POT2_PIN 0      // B0
//
//#define ADC_CHANNEL_POT1 9  // ADC0_SE9 is connected to PTB1
//#define ADC_CHANNEL_POT2 8  // ADC0_SE8 is connected to PTB0
//
//// Button states
//static bool button1_pressed = false;
//static bool button2_pressed = false;
//static bool button3_pressed = false;
//
//// Blink pattern
//enum {
//    BLINK_NOT_MOUNTED = 250,
//    BLINK_MOUNTED = 1000,
//    BLINK_SUSPENDED = 2500,
//};
//
//static uint32_t blink_interval_ms = BLINK_NOT_MOUNTED;
//
//// Function prototypes
//void led_blinking_task(void);
//void ump_task(void);
//void init_gpio(void);
//void init_adc(void);
//void read_inputs(void);
//uint16_t read_adc(uint8_t channel);
//uint32_t scale_adc_to_midi(uint16_t adc_value);
//void print_adc_values(void);
//void adc_task(void);
//
//void init_gpio(void) {
//    // Enable clock for PORTB, PORTD, and PORTA
//    SIM->SCGC5 |= SIM_SCGC5_PORTB_MASK | SIM_SCGC5_PORTD_MASK | SIM_SCGC5_PORTA_MASK;
//
//    // Configure buttons as inputs with pull-ups
//    PORTD->PCR[BUTTON1_PIN] = PORT_PCR_MUX(1) | PORT_PCR_PE_MASK | PORT_PCR_PS_MASK;
//    PORTA->PCR[BUTTON2_PIN] = PORT_PCR_MUX(1) | PORT_PCR_PE_MASK | PORT_PCR_PS_MASK;
//    PORTA->PCR[BUTTON3_PIN] = PORT_PCR_MUX(1) | PORT_PCR_PE_MASK | PORT_PCR_PS_MASK;
//
//    // Configure potentiometer pins as analog inputs
//    PORTB->PCR[POT1_PIN] = PORT_PCR_MUX(0);
//    PORTB->PCR[POT2_PIN] = PORT_PCR_MUX(0);
//}
//
//void init_adc(void) {
//    // Enable clock for ADC0
//    SIM->SCGC6 |= SIM_SCGC6_ADC0_MASK;
//
//    // Configure ADC
//    ADC0->CFG1 = ADC_CFG1_MODE(3) |     // 16-bit conversion
//                 ADC_CFG1_ADICLK(0) |   // Bus clock
//                 ADC_CFG1_ADIV(3);      // Divide ratio = 8 (slower but more accurate)
//
//    ADC0->SC3 = ADC_SC3_AVGE_MASK |     // Hardware average enable
//                ADC_SC3_AVGS(3);        // 32 samples averaged
//
//    // Perform ADC calibration
//    ADC0->SC3 |= ADC_SC3_CAL_MASK;
//    while (ADC0->SC3 & ADC_SC3_CAL_MASK);
//
//    if (ADC0->SC3 & ADC_SC3_CALF_MASK) {
//        printf("ADC calibration failed\r\n");
//    } else {
//        printf("ADC calibration successful\r\n");
//    }
//
//    // Use software trigger
//    ADC0->SC2 = 0;
//}
//
//void read_inputs(void) {
//    // Read button states (active low due to pull-ups)
//    button1_pressed = !(PTD->PDIR & MASK(BUTTON1_PIN));
//    button2_pressed = !(PTA->PDIR & MASK(BUTTON2_PIN));
//    button3_pressed = !(PTA->PDIR & MASK(BUTTON3_PIN));
//}
//
//uint16_t read_adc(uint8_t channel) {
//    // Configure for single-ended mode
//    ADC0->SC1[0] = ADC_SC1_ADCH(channel) & ~ADC_SC1_DIFF_MASK;
//
//    // Wait for conversion to complete
//    while (!(ADC0->SC1[0] & ADC_SC1_COCO_MASK));
//
//    // Read and return result
//    return ADC0->R[0];
//}
//
//uint32_t scale_adc_to_midi(uint16_t adc_value) {
//    return (uint32_t)(((uint64_t)adc_value * 4294967295ULL) / 65535ULL);
//}
//
//void print_adc_values(void) {
//    uint16_t pot1_value = read_adc(ADC_CHANNEL_POT1);
//    uint16_t pot2_value = read_adc(ADC_CHANNEL_POT2);
//
//    printf("POT1 (PTB1): %u, POT2 (PTB0): %u\r\n", pot1_value, pot2_value);
//}
//
//void adc_task(void) {
//    static uint32_t last_read_time = 0;
//    uint32_t current_time = board_millis();
//
//    // Read ADC values every 100ms
//    if (current_time - last_read_time >= 100) {
//        print_adc_values();
//        last_read_time = current_time;
//    }
//}
//
//void ump_task(void) {
//    static uint32_t start_ms = 0;
//    uint8_t const cable_num = 0;
//
//    // Read inputs
//    read_inputs();
//
//    // Handle incoming MIDI messages
//    #define NUM_WORDS 2
//    uint32_t packet[NUM_WORDS];
//    while (tud_ump_n_available(cable_num)) tud_ump_read(cable_num, packet, NUM_WORDS);
//
//    // Check if enough time has passed
//    if (board_millis() - start_ms < 10) return; // 10ms debounce time
//    start_ms = board_millis();
//
//    // Send Note On when BUTTON2 is pressed
//    if (button2_pressed) {
//        uint32_t note_on_packet[2];
//        note_on_packet[0] = 0b01000000100100000011110001100000; // Group 0, Note On (1001), Note 60 (middle C)
//        note_on_packet[1] = 0b00000000011000000000000000000000; // Velocity 96 (32-bit resolution)
//        tud_ump_write(cable_num, note_on_packet, 2);
//        printf("Note On sent\r\n");
//    }
//
//    // Send Pitch Bend when BUTTON1 is pressed, use POT1 for value
//    if (button1_pressed) {
//        uint16_t pot1_value = read_adc(ADC_CHANNEL_POT1);
//        uint32_t pitch_bend_value = scale_adc_to_midi(pot1_value);
//
//        uint32_t pitch_bend_packet[2];
//        pitch_bend_packet[0] = 0b01000001111000000011110000000000;  // Group 0, Pitch Bend (1110), 32-bit message
//        pitch_bend_packet[1] = pitch_bend_value;
//        tud_ump_write(cable_num, pitch_bend_packet, 2);
//        printf("Pitch Bend sent: %lu\r\n", pitch_bend_value);
//    }
//
//    // Send Poly Pressure when BUTTON3 is pressed, use POT2 for value
//    if (button3_pressed) {
//        uint16_t pot2_value = read_adc(ADC_CHANNEL_POT2);
//        uint32_t pressure_value = scale_adc_to_midi(pot2_value);
//
//        uint32_t poly_pressure_packet[2];
//        poly_pressure_packet[0] = 0b01000001101000000011110000000000; // Group 0, Poly Pressure (1010), 32-bit message
//        poly_pressure_packet[1] = pressure_value;
//        tud_ump_write(cable_num, poly_pressure_packet, 2);
//        printf("Poly Pressure sent: %lu\r\n", pressure_value);
//    }
//}
//
//void led_blinking_task(void) {
//    static uint32_t start_ms = 0;
//    static bool led_state = false;
//
//    // Blink every interval ms
//    if (board_millis() - start_ms < blink_interval_ms) return; // not enough time
//    start_ms += blink_interval_ms;
//
//    board_led_write(led_state);
//    led_state = 1 - led_state; // toggle
//}
//
////int main(void) {
////    board_init();
////    init_gpio();  // Initialize GPIO for buttons and potentiometers
////    init_adc();   // Initialize ADC
////
////    // init device stack on configured roothub port
////    tud_init(BOARD_TUD_RHPORT);
////
////    if (board_init_after_tusb) {
////        board_init_after_tusb();
////    }
////
////    while (1) {
////        tud_task(); // tinyusb device task
////        led_blinking_task();
////        ump_task();
////        adc_task();
////    }
////}
//
//// Device callbacks
//void tud_mount_cb(void) {
//    blink_interval_ms = BLINK_MOUNTED;
//}
//
//void tud_umount_cb(void) {
//    blink_interval_ms = BLINK_NOT_MOUNTED;
//}
//
//void tud_suspend_cb(bool remote_wakeup_en) {
//    (void) remote_wakeup_en;
//    blink_interval_ms = BLINK_SUSPENDED;
//}
//
//void tud_resume_cb(void) {
//    blink_interval_ms = tud_mounted() ? BLINK_MOUNTED : BLINK_NOT_MOUNTED;
//}
