#include<stdio.h>
#include<stdint.h>
#define C_TO_F(degC) degC * (9.0/5.0) + 32.0

typedef struct{
    uint8_t count; //1 byte // little endian=0x6F else 0x6F
    uint16_t data[2]; // 4 bytes little endian= 0x9E70, 0x9994 else: 0x709E, 0x9499
    uint32_t timestamp; // 4 bytes little endian=0xE632B2CA else 0xCAB232E6
} packet_S;

typedef enum{
    IDLE,
    READY,
    VENDING,
    FAULT
} state_E;

typedef enum{
    COIN,
    COIN_RETURN,
    BUTTON,
    VEND_COMPLETE,
    GENERIC_FAULT
} input_E;

state_E stateMachine(input_E input)
{
// // // // Answer: : TODO
    volatile state_E current=IDLE;
    if(current==IDLE &&input==COIN){
        current=READY;
        return READY;
    }else if (current==READY&&input==COIN_RETURN){
        current=IDLE;
        return IDLE;
    }else if(current==READY&&input==BUTTON){
        current=VENDING;
        return VENDING;
    }else if(current==VENDING && input==VEND_COMPLETE){
        current=IDLE;
        return IDLE;
    }else if(input==GENERIC_FAULT){
        current=FAULT;
        return FAULT;
    }else
        return FAULT;
}


volatile uint8_t ADC_RESULT;

uint16_t computeSquareADC(void){
    uint16_t retval = (uint16_t)ADC_RESULT * (uint16_t)ADC_RESULT;
    return retval;
 }

void flip_hi_lo(uint8_t *b)
{
    *b=(*b^1);
    printf("%x",*b);
    *b=(*b^(0x80));
    printf("\n%x",*b);
}

int main(){
        float farenhite=C_TO_F(12.1);
        //printf("Today's temperature: %f",farenhite);
        uint8_t a=8;
        //flip_hi_lo(&a);
        ADC_RESULT=0xFF;
        uint16_t result= computeSquareADC();
        //printf("%u", result);
        packet_S s={33,{32888,32888},120};
        printf("%lu\n",sizeof(s));

        unsigned char data;
        int i;
        for(i=0;i<sizeof(s);i++){
            if(i%8==0) printf("\n");
            data=*(((unsigned char*)&s)+i);
            printf("%02x ",data);
        }
}