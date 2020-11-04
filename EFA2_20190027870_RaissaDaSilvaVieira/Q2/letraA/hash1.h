#ifndef HASH
#define HASH

typedef struct pessoa Pessoa;
typedef struct hash Hash;

static int hash (long int cpf, Hash* tabela);
static void redimensiona (Hash* tabela);
Pessoa* create_pessoa(long int cpf, char* nome, int idade, char* sexo);
Hash* create_hash();
Pessoa* insert_hash(Hash* tabela, Pessoa* pessoa);
Pessoa* search_hash(Hash* tabela, long int cpf);
void printfnome(Pessoa* pessoa);
int remove_hash(Hash* tabela, long int cpf);

#endif
