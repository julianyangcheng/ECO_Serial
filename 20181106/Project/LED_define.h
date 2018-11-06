#define LED1_GPIO_PORT GPIOB
#define LED1_GPIO_CLK RCC_APB2Periph_GPIOB
#define LED1_GPIO_PIN GPIO_Pin_12

#define DigitialHigh(p,i) {p->BSRR=i;}
#define Digitial Low(p,i) {p->BRR=i;}
#define DigitialToggle(p,i) {p->ODR ^= i;}

#define LED1_On DigitialHigh(LED1_GPIO_POR,LED1_GPIO_PIN)
#define LED1_Off DigitialLow(LED1_GPIO_POR,LED1_GPIO_PIN)
#define LED1_Toggle DigitialToggle(LED1_GPIO_POR,LED1_GPIO_PIN)
