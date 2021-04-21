#undef VETOR_H
#undef TIPO_
#undef TIPADO_
#undef TIPADO2_


#include "complexo-double.h"

#define TIPO_ D_Complexo_pt
#define TIPADO_(THING) VCD_ ## THING
#define TIPO2_ double
#define TIPADO2_(THING) D_ ## THING

#include "vetor_nao_nativo.h"

