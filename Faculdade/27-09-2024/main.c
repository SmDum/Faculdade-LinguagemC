/*
    ===== Estruturas =====
    
    ----------------
    | String       |
    | Int          |  ---> Struct
    | Float        |
    |              |
    ----------------

    Ex.0: 

    struct facil {
    int num;
    char c;
    };

==========================

    Ex.1: 
    
    struct facil{
    int num;
    char c;
    };

    struct facil x;

==========================

    typedef tipo_existente novonome;

    Ex. 2: 

    typedef float real;


==========================

    Ex.3:

    typedef struct facil{
    int num;
    char c;
    }facil;

    facil x;

==========================

    Ex.4:

    struct facil {
    int num;
    char c;
    };

    struct facil x;

    x.num = 10;
    x.c = 'Z';

    ==========================

    Ex.5:

    struct facil {
    int num;
    char c;};

    struct facil x1,x2;

    ==========================

    Ex.6:

    struct data{
    int x[2];
    char y[10];
    };

    struct data record;

    record.x[0] = 100;
    puts(record.y);

    ==========================
    
    Atribuições de Estrutura:

    livro2 = livro1;

    O valor de uma variávl estruturada pode ser atribuído a outra variável estrutura do mesmo tipo.

    ***Só pode fazer isso com ESTRUTURAS***

    ==========================

    Ex.7:

    struct livro{
    char titulo[30];
    int regnum;
    };

    struct livro livro1, livro2=("Ana",2);

    livro1=livro2;

    livro1.numreg=livro2.numreg;

    ==========================

    Estrutura Alinhadas:

    struct livro{
        char titulo[30];
        int regnum;
    };

    struct grupo{
        struct livro dicionario;
        struct livro literatura;
    };

    --------------

    struct grupo{
        struct livro{
        char titulo[30];
        int regnum;
        }dicionario, literatura;
    }

    ==========================

    Matriz de Estruturas:

    Ex.8:

    struct entrada{
        char nome[10];
        char email[12];
        char fone[8];
    };

    struct entrada lista[1000];
*/