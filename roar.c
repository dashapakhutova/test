#ifdef _CODE_ROAR
#else
#define _CODE_ROAR

uint8_t roar = false;

void
initRoar
( void )
{
  initPin_PP(GPIOA,4);
  RCC -> APB2ENR |= RCC_APB2ENR_TIM17EN;
  TIM17 -> CR1 &= ~TIM_CR1_CEN;
  TIM17 -> CNT = 0;
  TIM17 -> ARR = 4100;
  TIM17 -> PSC = (10-1);
  TIM17 -> DIER |= TIM_DIER_UIE;
  TIM17 -> CR1 |= TIM_CR1_CEN;
  NVIC_EnableIRQ(TIM1_TRG_COM_TIM17_IRQn);
  NVIC_SetPriority(TIM1_TRG_COM_TIM17_IRQn,15);
}

void
TIM1_TRG_COM_TIM17_IRQHandler
( void )
{
  if ( roar ) {
    setPin_PP(GPIOA,4,TOGGLE);
  }
  TIM17 -> SR &= ~TIM_SR_UIF;
}

#endif
