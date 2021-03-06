#include<16f877.h>

#device ADC = 8;

#use delay(clock = 4000000)

#use fast_io(a)
#use fast_io(b)
#use fast_io(c)

#define use_portb_lcd TRUE
#include<lcd.c>

unsigned int deger;
float voltaj;

void main(){
setup_psp(PSP_DISABLED);
setup_timer_1(T1_DISABLED);
setup_ccp2(CCP_OFF);

setup_timer_2(T2_DIV_BY_4,255,1);
setup_CCP1(CCP_PWM); // PWM kullanaca??m?z i?in PWM dedik.

setup_adc(adc_clock_div_32);
setup_adc_ports(ALL_ANALOG);

set_tris_a(0x20);
set_tris_b(0x00);
set_tris_c(0x00);

set_adc_channel(4); //AN4 kullan?yoruz.

output_c(0x00);

lcd_init();

set_pwm1_duty(0); //ccp1 kulland???m?z i?in pwm1. pwm hemen iletime ge?mesin diye 0 dedik.

while(true){

deger = read_adc();
voltaj = deger / 51.0; // 255/51 den 5V gelmesi i?in

output_high(pin_c3); // motor ileri
output_low(pin_c4); // motor geri



set_pwm1_duty(deger); // e?er de?er 255 ten b?y?kse 255 e e?itle ve onu pwm1 duty e yazd?r.

printf(lcd_putc,"\fVoltaj=%fV",voltaj);
lcd_gotoxy(1,2);
printf(lcd_putc,"Deger=%u",deger);
delay_ms(500);


}

}










