#include "motor.h"
#include "usart.h"
#include "ldr.h"
#include "led.h"
#include "lcd.h"
#include "ultrasonic.h"
#define MINIMUM_OBSTACLE_DISTANCE 40
void LCD_intro()
{
	LCD_clearScreen();
	LCD_displayString("         Roll Your Eyes To Move!");
	LCD_goToRowColumn(1,0);
	LCD_displayString("             Blink to Stop! ");
}

uint8_t receive_flag = 0;
uint16_t receive_data; 

void UART_callback(uint16 data)
{
	receive_flag = 1;
	receive_data = data;
}


int main(void)
{
	/* LCD Init */
	LCD_init();
	LCD_displayString("         Welcome to Move-Me!");
	
	/*Motor Init*/

	ST_MOTOR_config_t motor1 = {A,1,2};
	ST_MOTOR_config_t motor2 = {C,0,1};
			
	MOTOR_init(&motor1);
	MOTOR_init(&motor2);
		
	/*Led Init*/
	ST_LED_config_t led = {D,6};
	LED_init(&led);
		
	/*LDR Init*/
	LDR ldr = {0};
	LDR_init();
		
	/*USART Init*/
		
	Usart_ConfigType usart_config = {ON,EIGHT,DISABLED,ONE,9600};
	UART_init(&usart_config);
	UART_setCallBack(UART_callback);
	
	/* Enable Receiving by Interrupt */
	UART_receiveByte();
		
	/* Ultrasonic Init*/
		
	ULTRASONIC_init();
	
	/* To Hold Data Received by USART */
	uint8_t data ;
	/* To Hold Value Received from LDR */ 
	uint8_t value;
	/* To Hold Value Received from Ultrasonic*/
	int16_t COUNTA = 0;
	
	/* Delay For UI */
	_delay_ms(2000);
	
	uint8_t light_flag = 0;
	uint8_t loop_flag =0;
	while(1)
	{
		
// 		LCD_clearScreen();
// 		LCD_integerToString(COUNTA);
		
		/* LDR Module */
		
		/* Check Light Intensity */
		value = LDR_read(&ldr);
		
		if(value <5 && light_flag == 0 ) /* If Light Intensity is Low Open Led*/
		{
			light_flag = 1;
			loop_flag = 0;
			LED_write(&led,HIGH);
			LCD_clearScreen();
			LCD_displayString("               Light is ON!");
			_delay_ms(3000);
		}
		else if(value>=5 && light_flag == 1)/* If Light Intensity is High Close Led*/
		{
			light_flag = 0; 
			loop_flag = 0;
			LED_write(&led,LOW);
			LCD_clearScreen();
			LCD_displayString("               Light is OFF!");
			_delay_ms(3000);
		}
		
		if(loop_flag ==0)
		{
			loop_flag=1;
			LCD_intro();
		}
		else
		{
			/* Do Nothing*/
		}
		
		
		if(receive_flag == 1 )
		{
			loop_flag = 0 ;
			receive_flag = 0 ;
			data = receive_data ;
			
			/* Send Byte to the Virtual Terminal as a sort of Feedback */
			UART_sendByte(data);
			
			if(data=='W')       /* Move Forward   */
			{
				ULTRASONIC_trigger();
				_delay_ms(100);
				COUNTA = pulse/(58*8);
				
				if(COUNTA <=MINIMUM_OBSTACLE_DISTANCE ) /* Obstacle Detected */
				{
					MOTOR_stop(1);
					MOTOR_stop(2);
					LCD_clearScreen();
					LCD_displayString("         Obstacle Detected!");
					LCD_goToRowColumn(1,0);
					LCD_displayString("    Please Move in Another Direction..");
					_delay_ms(3000);
				}
				else /* No Obstacle Detected */
				{
					LCD_clearScreen();
					LCD_displayString("         Moving Forward...!");
					/* Stop the Motors First as not to break them due to moving in a direction
						and then sudden change the direction */ 
					MOTOR_stop(1);
					MOTOR_stop(2);
					_delay_ms(200);
					MOTOR_cw(1,60);
					MOTOR_cw(2,60);
					_delay_ms(3000);
				}
				
			}
			else if(data=='X')
			{
				LCD_clearScreen();
				LCD_displayString("         Moving Backward...!");
				/* Stop the Motors First as not to break them due to moving in a direction
					and then sudden change the direction */ 
				MOTOR_stop(1);
				MOTOR_stop(2);
				_delay_ms(200);
				MOTOR_ccw(1,60);
				MOTOR_ccw(2,60);
				_delay_ms(2000);
			}
			else if(data=='D')  /* Move Right */
			{
				LCD_clearScreen();
				LCD_displayString("         Moving Right...!");
				/* Stop the Motors First as not to break them due to moving in a direction
					and then sudden change the direction */ 
				MOTOR_stop(1);
				MOTOR_stop(2);
				_delay_ms(200);
				MOTOR_cw(1,60);
				MOTOR_ccw(2,60);
				_delay_ms(2000);
			
			}
			else if(data=='A')   /* Move Left */
			{
				LCD_clearScreen();
				LCD_displayString("         Moving Left...!");
				/* Stop the Motors First as not to break them due to moving in a direction
					and then sudden change the direction */ 
				MOTOR_stop(1);
				MOTOR_stop(2);
				_delay_ms(200);
				MOTOR_ccw(1,60);
				MOTOR_cw(2,60);
				_delay_ms(2000);
			}
			else if(data =='S') /* Stop */
			{   
				LCD_clearScreen();
				LCD_displayString("               Stopped...!");
				MOTOR_stop(1);
				MOTOR_stop(2);
				_delay_ms(2000);
			}
			else
			{
				/* Do Nothing */
			}
			
			
			
			
		}
		else
		{
			/* Do Nothing */
		}
		
		
		
		

	}
}
