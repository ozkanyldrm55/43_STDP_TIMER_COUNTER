#include "stm32f4xx.h"
#include "stm32f4_discovery.h"

TIM_TimeBaseInitTypeDef TIM_InitStruct;

int count = 0;

/*   SN = ((periyod +1) * (prescaler +1)) / clock speed   */

void Timer_Config() {
	// eger herhangi bir bu hatti icin prescaler oranı 1 den farklı ise o hattin calisma frekansi 2 katina cikar.
	// bu bilgiye src -> system_stm32f4xx.c den bakabiliriz. cube mx den deneme yapabiliriz.
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);

	TIM_InitStruct.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_InitStruct.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_InitStruct.TIM_Period = 1999; // timer in max saydigi deger
	TIM_InitStruct.TIM_Prescaler = 41999;
	TIM_InitStruct.TIM_RepetitionCounter = 0;
	
	// SN = ((periyod +1) * (prescaler +1)) / clock speed
	// 1 = ((1999 + 1) * (41999 + 1)) / 84 000 000 , yani her 1sn de 1999 a kadar sayacak.

	TIM_TimeBaseInit(TIM2 ,&TIM_InitStruct);
	TIM_Cmd(TIM2 , ENABLE);
}

int main(void) {
	Timer_Config();
  while (1) {
	count = TIM_GetCounter(TIM2);
  }
}


void EVAL_AUDIO_TransferComplete_CallBack(uint32_t pBuffer, uint32_t Size){
  /* TODO, implement your code here */
  return;
}

/*
 * Callback used by stm324xg_eval_audio_codec.c.
 * Refer to stm324xg_eval_audio_codec.h for more info.
 */
uint16_t EVAL_AUDIO_GetSampleCallBack(void){
  /* TODO, implement your code here */
  return -1;
}
