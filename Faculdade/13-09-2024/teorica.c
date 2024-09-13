/*
    Alocação de Memória na Função
    =============================

    *Chamada por Referência - Devemos passar o endereço do ponteiro declarado na main, portanto, a função receberá como parâmetro o ponteiro para ponteiro.

    *Chamada por Valor - Só conseguimos trabalhar dessa forma, se a função retornar o endereço alocado para o ponteiro declarado na main, permitindo assim, o acesso à memória alocada. Caso contrário o ponteiro na main continuará NULL e ao saírmos da função perdemos a referência da memória alocada. Lembre-se que as variáveis (inclusive ponteiro) declaradas dentro da função, deixam de existir assim que a função termina.

    -------------------------------------------------------------------------------------------
    
*/