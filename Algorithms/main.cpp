//
// use this to front-end calc.asm.
//
#include <stdio.h>

//vars and funcs defined elsewhere (in asm)
extern "C" {
    void calc(void);

    int getSum(void);
    int getAvg(void);
    int getMin(void);
    int getMax(void);
    int getCnt(void);
};

int main(int argc, char* argv[]) {    //where the magic begins!
    printf("hello \n");
    calc();

    printf("sum = %d \n", getSum());
    printf("avg = %d \n", getAvg());
    printf("min = %d \n", getMin());
    printf("max = %d \n", getMax());
    printf("cnt = %d \n", getCnt());

    printf("goodbye \n");
    return 0;
}