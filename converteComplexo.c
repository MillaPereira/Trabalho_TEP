#include <stdio.h>
#include <stdlib.h> 
#include <math.h> 

#include "complexo-double.h"
#include "complexoLongInt.h"
//#include "complexo_racional.h"
//#include "racionais.h"
#include "converteComplexo.h"

//VERIFICAR SE PODE ISSO 
I_Complexo_pt converteDoubleParaLongInt(D_Complexo_pt dComplexo){
    long int real = D_retornaReal(dComplexo);
    long int imag = D_retornaImaginario(dComplexo);
    I_Complexo_pt iComplexo = I_criaComplexo(real, imag);
    return iComplexo;
}


D_Complexo_pt converteLongIntParaDouble(I_Complexo_pt iComplexo){
    double real = I_retornaReal(iComplexo);
    double imag = I_retornaImaginario(iComplexo);
    D_Complexo_pt dComplexo = D_criaComplexo(real, imag);
    return dComplexo;
}

/*R_Complexo_pt converteDoubleParaRacional(D_Complexo_pt dComplexo){
    Racional_pt real = converteRealEmRacional(dComplexo->real);
    Racional_pt imag = converteRealEmRacional(dComplexo->imag);
    R_Complexo_pt rComplexo = R_criaComplexo(real, imag);
    return rComplexo;
}

D_Complexo_pt converteRacionalParaDouble(R_Complexo_pt rComplexo){
    double real = converteRacionalEmReal(rComplexo->real);
    double imag = converteRacionalEmReal(rComplexo->imag);
    D_Complexo_pt dComplexo = D_criaComplexo(real, imag);
    return dComplexo;
}

I_Complexo_pt converteRacionalParaLongInt(R_Complexo_pt rComplexo){
    long int real = converteRacionalEmReal(rComplexo->real);
    long int imag = converteRacionalEmReal(rComplexo->imag);
    I_Complexo_pt iComplexo = I_criaComplexo(real, imag);
    return iComplexo;
}

R_Complexo_pt converteLongIntPataRacional(I_Complexo_pt iComplexo){
    double r = iComplexo->real;
    double i = iCompelxo->imag;
    Racional_pt real = converteRealEmRacional(r);
    Racional_pt imag = converteRealEmRacional(i);
    R_Complexo_pt rComplexo = R_criaComplexo(real, imag);
}*/