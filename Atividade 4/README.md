# RT-Template: Path Tracer

Este arquivo usa o RT-Template disponibilizado pelo professor Christian A. Pagot, que pode ser encontrado [clicando aqui](https://github.com/capagot).

## Atividade Proposta

- Box filtering: Diversas amostras de radiância serão obtidas para cada pixel. As amostras devem apresentar distribuição uniforme sobre a área do pixel (sugestão: utilizar as classes de geração de números randômicos para C++11, mais especificamente o Mersenne Twister). O resultado final da radiância incidente em um pixel será a média das amostras (box filter). O número de amostras por pixel deve ser um parâmetro da aplicação.

- Profundidade máxima dos raios: Resultados satisfatórios podem ser obtidos com raios de profundidade 5. Entretanto, a profundidade máxima dos raios deve ser um parâmetro da aplicação.

- Materiais: Os objetos da cena podem ser perfeitamente difusos e/ou emissores. Os materiais difusos devem ser representados por meio de uma BRDF (sugere-se a criação de uma classe específica para BRDFs), que será uma propriedade das primitivas. A emitância também será uma propriedade adicional das primitivas.

- Amostragem: a amostragem a ser utilizada na determinação dos raios incidentes nos pontos de intersecção dos raios deverá ser uniforme (como visto em aula).

## Resultados

Nos primeiros commits dessa atividades, já deu pra notar uma grande diferença entre o ray tracing e o path tracing, antes mesmo de usar a emitância, como pode-se ver na comparação de images a seguir:

![alt-text-1](images/commit1.png "Imagem com Path Tracing") ![alt-text-2](https://github.com/nycholassousa/RenderingBaseadoEmFisica/blob/master/Atividade%203/images/image2.png "Imagem com Ray Tracing")