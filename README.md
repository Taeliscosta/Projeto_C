Esse código foi criado como parte de um projeto na disciplina de Laboratório de Programação. Ele implementa um sistema de reserva de assentos para um cinema, onde os clientes podem realizar reservas de assentos para um filme específico e também têm a opção de liberar um assento caso desistam da reserva.

O sistema utiliza uma matriz tridimensional chamada assentos para representar as cadeiras disponíveis em cada sala para cada filme. Cada dimensão da matriz corresponde a um aspecto: número de filas (NUM_FILA), número de cadeiras por fila (NUM_CADEIRAS), e número de filmes (NUM_FILMES). Inicialmente, todas as cadeiras são marcadas como disponíveis, ou seja, o valor correspondente na matriz é definido como zero.

O código inclui várias funções e procedimentos para operar no sistema de reserva de assentos:

A função inicializar_assentos() é responsável por inicializar todas as cadeiras como disponíveis. Ela percorre a matriz assentos e atribui o valor zero a cada elemento, indicando que o assento está livre.

A função print_assentos(int filme) imprime o mapa de assentos disponíveis para um filme específico. Ela percorre a matriz assentos correspondente ao filme fornecido como argumento e exibe um mapa indicando os assentos disponíveis (números) e os assentos reservados (caractere 'X').

A função avalia_assento(int fila, int assento, int filme) verifica se um determinado assento está disponível para um filme específico. Ela verifica se os índices fornecidos estão dentro dos limites válidos e consulta o valor correspondente na matriz assentos. Se o valor for zero, o assento está disponível, caso contrário, está reservado.

A função reservar_assento(int fila, int assento, int filme) reserva um assento específico para um filme. Ela chama a função avalia_assento() para verificar se o assento está disponível e, se estiver, marca o assento como reservado na matriz assentos, atribuindo o valor um. A função retorna 1 se a reserva for bem-sucedida ou 0 caso contrário.

A função liberar_assento(int fila, int assento, int filme) permite liberar um assento reservado anteriormente. Ela verifica se o assento estava reservado, consultando o valor correspondente na matriz assentos. Se estava reservado, marca o assento como disponível, atribuindo o valor zero. A função retorna 1 se a liberação for bem-sucedida ou 0 caso contrário.

Cabe ressaltar que os assentos reservados para um filme não interferem nos assentos disponíveis para outros filmes, pois cada filme tem sua própria seção na matriz assentos. Isso garante que as reservas e liberações sejam tratadas de forma independente para cada filme.
