#ifdef TIPO_ //Complexo_pt
#ifdef TIPADO_ // VCI_()
#ifdef TIPADO2_

struct TIPADO_(Vetor_st){
  	int n; // numero de elementos atual
    int N; // numero máximo de elementos
    int i;
    TIPO_ *elementos;
};

typedef struct TIPADO_(Vetor_st) TIPADO_(Vetor_t);

// O WHILE FICARIA AQUI
void TIPADO_(realocaEspaco)(TIPADO_(Vetor_pt) vetor){ //acho que isso pode ficar dentro da funcao de criar vetor
    if(vetor->n >= vetor->N){
        vetor->elementos = (TIPO_*) realloc(vetor->elementos, 2 * vetor->n * sizeof(TIPO_));
    }
    if(vetor->n <= (vetor->N / 4)){
        vetor->elementos = (TIPO_*) realloc(vetor->elementos, 0.5 * vetor->n * sizeof(TIPO_));
    };
}

TIPADO_(Vetor_pt) TIPADO_(criaVetor)(int n, TIPO_ *elementos){
  printf ("Marco 0\n");
  TIPADO_(Vetor_pt) vetor = (TIPADO_(Vetor_t)*) malloc(sizeof(TIPADO_(Vetor_t)));
  vetor->elementos = (TIPO_*) malloc(100 * sizeof(TIPO_));
  if(vetor->elementos == NULL || vetor == NULL){
    printf("Memória insuficiente!\n");
	  exit(1);
  }
  printf ("Marco 1");
    vetor->n = n;
    vetor->N = 100;
    vetor->i = 0;

   // TIPADO_(realocaEspaco)(vetor);
  printf ("Marco 2");
    for(int c = 0; c < vetor->n; c++){
      // ATENCAO
      printf ("Marco 3");
      TIPADO2_(atribuiNovoValorReal)(vetor->elementos[c], TIPADO2_(retornaReal)(elementos[c]));
      printf ("Marco 4");
      TIPADO2_(atribuiNovoValorImaginario)(vetor->elementos[c], TIPADO2_(retornaImaginario)(elementos[c]));
    }
    printf ("Marco 5");
    return vetor;
}
/*
void TIPADO_(destroiVetor)(TIPADO_(Vetor_pt) vetor){
    for(int i = 0; i < vetor->n; i++){
      // ATENCAO
        TIPADO2_(destroiComplexo)(vetor->elementos[i]);
        vetor->elementos[i] = NULL;
    }
    free(vetor);
    vetor = NULL;
}

TIPO2_ TIPADO_(retornaElementoReal)(TIPADO_(Vetor_pt) vetor, int indice){
    TIPO2_ elemComplexo = TIPADO2_(retornaReal)(vetor->elementos[indice]);
    return elemComplexo;
}

TIPO2_ TIPADO_(retornaElementoImag)(TIPADO_(Vetor_pt) vetor, int indice){
    TIPO2_ elemComplexo = TIPADO2_(retornaImaginario)(vetor->elementos[indice]);
    return elemComplexo;
}

void TIPADO_(atribuiVetor)(TIPADO_(Vetor_pt) vetor1, TIPADO_(Vetor_pt) vetor2){
  vetor1->n = vetor2->n;
  vetor1->N = vetor2->N;
  vetor1->i = vetor2->i;

  for(int c = 0; c < vetor1->n; c++){

    TIPADO2_(atribuiNovoValorReal)(vetor1->elementos[c], TIPADO2_(retornaReal)(vetor2->elementos[c]));
    TIPADO2_(atribuiNovoValorImaginario)(vetor1->elementos[c], TIPADO2_(retornaImaginario)(vetor2->elementos[c]));
    }
}

TIPADO_(Vetor_pt) TIPADO_(criaCopiaVetor)(TIPADO_(Vetor_pt) vetor){
    TIPADO_(Vetor_pt) vetorNovo = TIPADO_(criaVetor)(vetor->n, vetor->elementos);
    return vetorNovo;
}

int TIPADO_(retornaNumeroAtualElementos)(TIPADO_(Vetor_pt) vetor){
    return vetor->n;
}

int TIPADO_(retornaNumeroMaxElementos)(TIPADO_(Vetor_pt) vetor){
  return vetor->N;
}

int TIPADO_(retornaIndice)(TIPADO_(Vetor_pt) vetor){
  return vetor->i;
}
// verificar 
TIPO_ TIPADO_(retornaPrimeiroElemento)(TIPADO_(Vetor_pt) vetor){
    return *(vetor->elementos);
    vetor->i = 0;
}

TIPO_ TIPADO_(retornaProximoElemento)(TIPADO_(Vetor_pt) vetor, int indice){
    vetor->i = indice + 1;
    return vetor->elementos[indice+1];
}

TIPO_ TIPADO_(retornaElementoAnterior)(TIPADO_(Vetor_pt) vetor, int indice){
  vetor->i = indice - 1;
  return vetor->elementos[indice-1];
}

TIPO_ TIPADO_(retornaUltimoElemento)(TIPADO_(Vetor_pt) vetor){
    vetor->i = vetor->n-1;
    return vetor->elementos[vetor->n-1];
}

TIPO_ TIPADO_(retornaElementoDePosicaoI)(TIPADO_(Vetor_pt) vetor, int indice){
    vetor->i = indice;
    return vetor->elementos[indice];
}

void TIPADO_(atribuirValorNaIesimaPosicao)(TIPADO_(Vetor_pt) vetor, int indice, TIPO_ valor){
      
    TIPADO2_(atribuiNovoValorReal)(vetor->elementos[indice], TIPADO2_(retornaReal)(valor));
    TIPADO2_(atribuiNovoValorImaginario)(vetor->elementos[indice], TIPADO2_(retornaImaginario)(valor));
}

void TIPADO_(adicionaElemento)(TIPADO_(Vetor_pt) vetor, TIPO_ valor){
    
    TIPADO2_(atribuiNovoValorReal)(vetor->elementos[vetor->n], TIPADO2_(retornaReal)(valor));
    TIPADO2_(atribuiNovoValorImaginario)(vetor->elementos[vetor->n], TIPADO2_(retornaImaginario)(valor));
    
    vetor->n += 1;
}

void TIPADO_(eliminaElementoDePosicaoI)(TIPADO_(Vetor_pt) vetor, int indice){ //Revisar o significado dessa funcao
    for(int c = indice; c < vetor->n; c++){
        vetor->elementos[c] = vetor->elementos[c+1];
    }
    vetor->n = vetor->n-1;
    //estou na duvida se faco esse realloc 
    //vetor->elementos = (TIPO_*) realloc(vetor->elementos, vetor->n * sizeof(TIPO_));
}

void TIPADO_(eliminaTodosElementos)(TIPADO_(Vetor_pt) vetor){
    TIPO_ n = TIPADO2_(criaComplexo)(0, 0);
    for (int i = 0; i < vetor->n; i++){
      TIPADO_(atribuirValorNaIesimaPosicao)(vetor, i, n);
    }
} */

/*
void eliminaTodosElementos(Vetor_pt vetor){
  for (int i = 0; i < vetor->n; i++){
    atribuirValorNaIesimaPosicao(vetor, i, 0);
  }
}*/

// a funcao retorna magnitude de um numero complexoo retorna double verificar o retorno dessa 
/*double TIPADO_(valorDeMaiorModulo)(TIPADO_(Vetor_pt) vetor){
    double maior = TIPADO2_(retornaMagnitude)(vetor->elementos[0]);
    vetor->i = 0;
    for(int c = 0; c < vetor->n; c++){
        if(TIPADO2_(retornaMagnitude)(vetor->elementos[c]) > maior){
            maior = TIPADO2_(retornaMagnitude)(vetor->elementos[c]);
            vetor->i = c;
        }
    }
    return maior;
}

double TIPADO_(valorDeMenorModulo)(TIPADO_(Vetor_pt) vetor){
  double menor = TIPADO2_(retornaMagnitude)(vetor->elementos[0]);
  vetor->i = 0;
  for (int c = 0; c < vetor->n; c++){
    if (TIPADO2_(retornaMagnitude)(vetor->elementos[c]) < menor){
      menor = TIPADO2_(retornaMagnitude)(vetor->elementos[c]);
      vetor->i = c;
    }
  }
  return menor;
}

int TIPADO_(quantElementosDeValorV)(TIPADO_(Vetor_pt) vetor, TIPO_ valor){
    int quant = 0;
    for(int c = 0; c < vetor->n; c++){
        // verificar como utilizar o eps aqui
        if(TIPADO2_(comparaModuloNumeros)(vetor->elementos[c], valor) == 0){
            quant++;
        }
    }
    return quant;
}

//verificar se isso deu certo 
int *TIPADO_(retornaVetorComPosicoesQueTemV)(TIPADO_(Vetor_pt) vetor, TIPO_ valor){
    int n = 0;
    for(int i = 0; i < vetor->n; i++){
      if (TIPADO2_(comparaModuloNumeros)(vetor->elementos[i], valor) == 0){
        n++;
      }
    }
    int elementos[n];
    n = 0;
    for(int i = 0; i < vetor->n; i++){
      if (TIPADO2_(comparaModuloNumeros)(vetor->elementos[i], valor) == 0){
        elementos[n] = i;
        n++;
      }
    }
    return elementos[n];
}*/
// QUE?
/*int TIPADO_(criterioOrdenacao) (const void * a, const void * b){ // Compara os de conteúdos "a" e "b" e retorna para a função qsort se "a" é maior, menor ou igual que "b"
  if (*(TIPO_*)a == *(TIPO_*)b){
    return 0; // Iguais
  }
  else if (*(TIPO_*)a < *(TIPO_*)b){
    return -1; //  A "a" vem antes da "b"
  }
  else{
    return 1; //  A "a" vem depois da "b"
  }
}*/

/*void TIPADO_(ordenarVetor)(TIPADO_(Vetor_pt) vetor){
    double vetorModulo;
    qsort(vetor->elementos, vetor->n, sizeof(TIPO_), TIPADO_(criterioOrdenacao));
} */

/*TIPADO_(Vetor_pt) TIPADO_(intercalaVetor)(TIPADO_(Vetor_pt) vetor1, TIPADO_(Vetor_pt) vetor2){

}

TIPADO_(Vetor_pt) TIPADO_(somaVetores)(TIPADO_(Vetor_pt) vetor1, TIPADO_(Vetor_pt) vetor2){
  TIPADO_(Vetor_pt) vetor = TIPADO_(criaCopiaVetor)(vetor1);

  TIPO2_ real;
  TIPO2_ imaginario;

  for(int c = 0; c < vetor1->n; c++){
    real = TIPADO2_(retornaReal)(vetor1->elementos[c]) + TIPADO2_(retornaReal)(vetor2->elementos[c]);
    imaginario = TIPADO2_(retornaImaginario)(vetor1->elementos[c]) + TIPADO2_(retornaImaginario)(vetor2->elementos[c]);

    TIPADO2_(atribuiNovoValorReal)(vetor->elementos[c], real);
    TIPADO2_(atribuiNovoValorImaginario)(vetor->elementos[c], imaginario);
  }
  return vetor;
}

TIPO_ TIPADO_(produtoInternoVetores) (TIPADO_(Vetor_pt) vetor1, TIPADO_(Vetor_pt) vetor2){
  TIPO_ produtoInterno = TIPADO2_(criaComplexo)(0,0);

  if(vetor1->n != vetor2->n){
    printf("Nao eh possivel realizar o produto interno, a quantidade de elementos de cada vetor é diferente\n");
    exit(1);
  }

  for (int i = 0; i < vetor1->n; i++){
    TIPADO2_(acumulaSomando)(produtoInterno, (TIPADO2_(multiplicaComplexo)(vetor1->elementos[i],vetor2->elementos[i])));
  }
  return produtoInterno;
}

TIPADO_(Vetor_pt) TIPADO_(subtraiVetores)(TIPADO_(Vetor_pt) vetor1, TIPADO_(Vetor_pt) vetor2){
    TIPADO_(Vetor_pt) vetor = TIPADO_(criaCopiaVetor)(vetor1);

  TIPO2_ real;
  TIPO2_ imaginario;

  for(int c = 0; c < vetor1->n; c++){
    real = TIPADO2_(retornaReal)(vetor1->elementos[c]) - TIPADO2_(retornaReal)(vetor2->elementos[c]);
    imaginario = TIPADO2_(retornaImaginario)(vetor1->elementos[c]) - TIPADO2_(retornaImaginario)(vetor2->elementos[c]);

    TIPADO2_(atribuiNovoValorReal)(vetor->elementos[c], real);
    TIPADO2_(atribuiNovoValorImaginario)(vetor->elementos[c], imaginario);
  }
  return vetor;
}

void TIPADO_(multiplicaVetorPorEscalar)(TIPADO_(Vetor_pt) vetor, double escalar){
  for(int c = 0; c < vetor->n; c++){
    TIPADO2_(atribuiNovoValorReal)(vetor->elementos[c], TIPADO2_(retornaReal)(vetor->elementos[c])*escalar);
    TIPADO2_(atribuiNovoValorImaginario)(vetor->elementos[c], TIPADO2_(retornaImaginario)(vetor->elementos[c])*escalar);
  }
} 

void TIPADO_(acumulaVetor) (TIPADO_(Vetor_pt) vetor1, TIPADO_(Vetor_pt) vetor2){
  TIPO2_ real;
  TIPO2_ imaginario;

  for(int c = 0; c < vetor1->n; c++){
    real = TIPADO2_(retornaReal)(vetor1->elementos[c]) + TIPADO2_(retornaReal)(vetor2->elementos[c]);
    imaginario = TIPADO2_(retornaImaginario)(vetor1->elementos[c]) + TIPADO2_(retornaImaginario)(vetor2->elementos[c]);

    TIPADO2_(atribuiNovoValorReal)(vetor1->elementos[c], real);
    TIPADO2_(atribuiNovoValorImaginario)(vetor1->elementos[c], imaginario);
  }
}

double TIPADO_(mediaAritimetica) (TIPADO_(Vetor_pt) vetor){
  double media = 0;
  for (int i = 0; i < vetor->n; i++){
    media += TIPADO2_(retornaMagnitude)(vetor->elementos[i]);
  }
  return media/vetor->n;
}

double TIPADO_(varianciaVetor) (TIPADO_(Vetor_pt) vetor){
  double media = TIPADO_(mediaAritimetica)(vetor);
  double variancia = 0;
  
  for (int i = 0; i < vetor->n; i++){
    variancia += pow((TIPADO2_(retornaMagnitude)(vetor->elementos[i]) - media), 2);
  }
  variancia = variancia/vetor->n;
  return variancia;
}

double TIPADO_(desvioPadrao) (TIPADO_(Vetor_pt) vetor){
  double DP;
  DP = sqrt(TIPADO_(varianciaVetor(vetor)));
}*/

/*double TIPADO_(medianaVetor) (TIPADO_(Vetor_pt) vetor){
  TIPADO_(ordenarVetor)(vetor);
  double mediana = 0;
  if (vetor->n%2 == 0){
    mediana = (vetor->elementos[(vetor->n/2)-1] + vetor->elementos[vetor->n/2])/2;
  }
  else{
    mediana = vetor->elementos[(vetor->n-1)/2];
  }
  return mediana;
}*/


#endif 
#endif
#endif