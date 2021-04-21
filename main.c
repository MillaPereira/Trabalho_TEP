#include <stdio.h>
#include <stdlib.h>

#include "racionais.h"

#include "complexoLongInt.h"
#include "complexo-double.h"
#include "converteComplexo.h"

#include "vetorLongInt.h"
#include "vetorDouble.h"
#include "vetor_complexo_double.h"
#include "vetor_complexo_int.h"

int main(void) {
  I_Complexo_pt n1, n2, n3, n4, n5;
  I_Complexo_pt m1, m2, m3, m4, m5;
  n1 = I_criaComplexo(1, 2);
  n2 = I_criaComplexo(3, 4);
  n3 = I_criaComplexo(5, 6);
  n4 = I_criaComplexo(7, 8);
  n5 = I_criaComplexo(9, 10);
  m1 = I_criaComplexo(11, 12);
  m2 = I_criaComplexo(13, 14);
  m3 = I_criaComplexo(1, 2);
  m4 = I_criaComplexo(4, 2);
  m5 = I_criaComplexo(16, 2);
  I_Complexo_pt elementos1[] = {n1, n2, n3, n4, n5};
  I_Complexo_pt elementos2[] = {m1, m2, m3, m4, m5};
  I_Complexo_pt *pv1 = elementos1;
  I_Complexo_pt *pv2 = elementos2;


  VCI_Vetor_pt vetor1 = VCI_criaVetor(5, pv1);

  /*VCI_Vetor_pt vetor2 = VCI_criaVetor(5, pv2);*/

  printf ("Hello\n");

  return 0;
}