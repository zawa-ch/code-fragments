//最初のほうは適当に何とかする
#include <16F886.h>
#fuses INTRC_IO,NOWDT,NOPROTECT,PUT,NOMCLR,NOLVP,BROWNOUT
#use delay(CLOCK=8000000)
#use RS232(BAUD=9600,RCV=PIN_C7,XMIT=PIN_C6,ERRORS,FORCE_SW)

#define LED0 
#define LED1 
#define LED2 
#define LED3 
#define LED4 
#define LED5 
#define LED6 
#define LED7 
#define LED8 
#define LED9 
#define LEDa 
#define LEDb 
#define LEDc 
#define LEDd 
#define LEDe 
#define LEDf 

/*"led_pmwout" - LEDのPWM出力
	本来IとOの2種類の出力のみのLEDをPWM(PulseWidthModule)を用いて調光できるようにします
	え？なぜ"PWM"ではなく"PMW"なのかって?それは気にした人の負け。
*/
void led_pmwout(int pin,int br,int frame){
	int io;
	if(frame<br){
		pin_output(pin,high);
	}else{
		pin_output(pin,low);
	}
}

void led_test(){
	pin_output(LED0,low);
	pin_output(LED1,low);
	pin_output(LED2,low);
	pin_output(LED3,low);
	pin_output(LED4,low);
	pin_output(LED5,low);
	pin_output(LED6,low);
	pin_output(LED7,low);
	pin_output(LED8,low);
	pin_output(LED9,low);
	pin_output(LEDa,low);
	pin_output(LEDb,low);
	pin_output(LEDc,low);
	pin_output(LEDd,low);
	pin_output(LEDe,low);
	pin_output(LEDf,low);
	delay_ms(5000);
	pin_output(LED0,high);
	pin_output(LED1,high);
	pin_output(LED2,high);
	pin_output(LED3,high);
	pin_output(LED4,high);
	pin_output(LED5,high);
	pin_output(LED6,high);
	pin_output(LED7,high);
	pin_output(LED8,high);
	pin_output(LED9,high);
	pin_output(LEDa,high);
	pin_output(LEDb,high);
	pin_output(LEDc,high);
	pin_output(LEDd,high);
	pin_output(LEDe,high);
	pin_output(LEDf,high);
	pin_output(LED0,low);delay_ms(200);pin_output(LED0,high);
	pin_output(LED1,low);delay_ms(200);pin_output(LED1,high);
	pin_output(LED2,low);delay_ms(200);pin_output(LED2,high);
	pin_output(LED3,low);delay_ms(200);pin_output(LED3,high);
	pin_output(LED4,low);delay_ms(200);pin_output(LED4,high);
	pin_output(LED5,low);delay_ms(200);pin_output(LED5,high);
	pin_output(LED6,low);delay_ms(200);pin_output(LED6,high);
	pin_output(LED7,low);delay_ms(200);pin_output(LED7,high);
	pin_output(LED8,low);delay_ms(200);pin_output(LED8,high);
	pin_output(LED9,low);delay_ms(200);pin_output(LED9,high);
	pin_output(LEDa,low);delay_ms(200);pin_output(LEDa,high);
	pin_output(LEDb,low);delay_ms(200);pin_output(LEDb,high);
	pin_output(LEDc,low);delay_ms(200);pin_output(LEDc,high);
	pin_output(LEDd,low);delay_ms(200);pin_output(LEDd,high);
	pin_output(LEDe,low);delay_ms(200);pin_output(LEDe,high);
	pin_output(LEDf,low);delay_ms(200);pin_output(LEDf,high);
	delay_ms(3000);
}

void main(){
//初期化作業
	setup_oscillator(OSC_8MHZ);
	set_tris_a(0x00);
	set_tris_b(0x00);
	set_tris_c(0x00);
	port_b_pullups (0x00);

	unsigned int fr=0,tick=0;
	signed int brg
	led_test();

	while(1){
//松明のLED設定
		switch(tick%18){
			case 1:
			case 3:
			case 7:
			case 9:
			case 11:
				brg=3;
				break;
			
			case 0:
			case 2:
			case 4:
			case 8:
			case 10:
			case 12
			case 14:
				brg=7;
				break;
			
			case 5:
			case 17:
				brg=11;
				break;
			
			case 6:
			case 16:
				brg=15;
				break;
		}
		led_pmwout(,brg,fr);
		
//かまどのLED設定
		if(tick%400<=200){
			brg=16;
		}else{
			brg=0;
		}
		led_pmwout(,brg,fr);
		
//レッドストーンランプのLED設定 R
		switch((tick/4)%45){
			case 0:
				brg=15;
				break;
			case 1:
			case 44:
				brg=14;
				break;
			case 2:
			case 43:
				brg=13;
				break;
			case 3:
			case 42:
				brg=12;
				break;
			case 4:
			case 41:
				brg=11;
				break;
			case 5:
			case 40:
				brg=10;
				break;
			case 6:
			case 39:
				brg=9;
				break;
			case 7:
			case 38:
				brg=8;
				break;
			case 8:
			case 37:
				brg=7;
				break;
			case 9:
			case 36:
				brg=6;
				break;
			case 10:
			case 35:
				brg=5;
				break;
			case 11:
			case 34:
				brg=4;
				break;
			case 12:
			case 33:
				brg=3;
				break;
			case 13:
			case 32:
				brg=2;
				break;
			case 14:
			case 31:
				brg=1;
				break;
			case default:
				brg=0;
				break;
		}
		led_pmwout(,brg,fr);
		
//レッドストーンランプのLED設定 G
		switch((tick/4)%45){
			case 15:
				brg=15;
				break;
			case 16:
			case 14:
				brg=14;
				break;
			case 17:
			case 13:
				brg=13;
				break;
			case 18:
			case 12:
				brg=12;
				break;
			case 19:
			case 11:
				brg=11;
				break;
			case 20:
			case 10:
				brg=10;
				break;
			case 21:
			case 9:
				brg=9;
				break;
			case 22:
			case 8:
				brg=8;
				break;
			case 23:
			case 7:
				brg=7;
				break;
			case 24:
			case 6:
				brg=6;
				break;
			case 25:
			case 5:
				brg=5;
				break;
			case 26:
			case 4:
				brg=4;
				break;
			case 27:
			case 3:
				brg=3;
				break;
			case 28:
			case 2:
				brg=2;
				break;
			case 29:
			case 1:
				brg=1;
				break;
			case default:
				brg=0;
				break;
		}
		led_pmwout(,brg,fr);
		
//レッドストーンランプのLED設定 B
		switch((tick/4)%45){
			case 30:
				brg=15;
				break;
			case 31:
			case 29:
				brg=14;
				break;
			case 32:
			case 28:
				brg=13;
				break;
			case 33:
			case 27:
				brg=12;
				break;
			case 34:
			case 26:
				brg=11;
				break;
			case 35:
			case 25:
				brg=10;
				break;
			case 36:
			case 24:
				brg=9;
				break;
			case 37:
			case 23:
				brg=8;
				break;
			case 38:
			case 22:
				brg=7;
				break;
			case 39:
			case 21:
				brg=6;
				break;
			case 40:
			case 20:
				brg=5;
				break;
			case 41:
			case 19:
				brg=4;
				break;
			case 42:
			case 18:
				brg=3;
				break;
			case 43:
			case 17:
				brg=2;
				break;
			case 44:
			case 16:
				brg=1;
				break;
			case default:
				brg=0;
				break;
		}
		led_pmwout(,brg,fr);
		
//TNTのLED設定
		if(tick%20<=10){
			brg=16;
		}else{
			brg=0;
		}
		led_pmwout(,brg,fr);

//レッドストーンのLED設定
		brg=10;
		led_pmwout(,brg,fr);
		
//frame,tickの処理
		delay_us(3125);
		fr++;
		if(fr<=16){
			fr=0;
			tick++;
		}
	}
}