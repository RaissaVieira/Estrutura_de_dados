LINHA* l = (LINHA*) malloc(sizeof(LINHA));

    if(l != NULL && mat != NULL){
        LINHA* x = mat->n_linhas;

        while(mat->a_linhas->prox == NULL)
        {
            mat->n_linhas = mat->a_linhas->prox;
        }//ÚLTIMO ELEMENTO

        if(lin <= mat->n_linhas & col<=mat->n_colunas)
        {
            //PRIMEIRO CADASTRO
            if( mat->a_linhas->lin == -1)
            {
                mat->a_linhas->lin = lin;
                mat->a_linhas->col = col;
                mat->a_linhas->prox = NULL;
            }
            else
            {
                x = l;
                mat->n_linhas= x;
                l->lin = lin;
                l->col = col;
                l->v = v;
                l->prox = NULL;
                return 1;
            }
        }
        else
        {
            printf("Tamanho de linha e coluna inválidos\n");
            return 0;
        }
    }else{
        printf("mat ou linha nula");
    }