# RT-Template: Path Tracer

Este arquivo usa o RT-Template disponibilizado pelo professor Christian A. Pagot, que pode ser encontrado [clicando aqui](https://github.com/capagot).

## Como usar o programa

```sh
$ ./swpathtracer Samples_Per_Pixel Depth Threads OutputFile
```

- Samples_Per_Pixel: Quantidade amostras por pixel

- Depth: Profundidade máxima dos raios

- Threads: Quantidade de threads usada para gerar a imagem (usei 4, devido minha máquina ser um i5)

- OutputFile: Nome de saída do arquivo, não é necessário inserir a extensão, será sempre um arquivo do tipo .ppm

## Atividade Proposta

- Box filtering: Diversas amostras de radiância serão obtidas para cada pixel. As amostras devem apresentar distribuição uniforme sobre a área do pixel (sugestão: utilizar as classes de geração de números randômicos para C++11, mais especificamente o Mersenne Twister). O resultado final da radiância incidente em um pixel será a média das amostras (box filter). O número de amostras por pixel deve ser um parâmetro da aplicação.

- Profundidade máxima dos raios: Resultados satisfatórios podem ser obtidos com raios de profundidade 5. Entretanto, a profundidade máxima dos raios deve ser um parâmetro da aplicação.

- Materiais: Os objetos da cena podem ser perfeitamente difusos e/ou emissores. Os materiais difusos devem ser representados por meio de uma BRDF (sugere-se a criação de uma classe específica para BRDFs), que será uma propriedade das primitivas. A emitância também será uma propriedade adicional das primitivas.

- Amostragem: a amostragem a ser utilizada na determinação dos raios incidentes nos pontos de intersecção dos raios deverá ser uniforme (como visto em aula).

## Resultados

### Começando o cálculo do Path Tracer

Nos primeiros commits dessa atividades, já deu pra notar uma grande diferença entre o ray tracing e o path tracing, antes mesmo de usar a emitância, como pode-se ver na comparação de images a seguir:


<p align="center">
	<br>
    <img src="./images/img1.png" width="375" hspace="20"/> <img src="https://github.com/nycholassousa/RenderingBaseadoEmFisica/raw/master/Atividade%203/images/image2.png" width="375"/>
	<h5 align="center">Figura 1 - A esquerda, início do path tracer, na direita, imagem utilizando ray tracer</h5>
	<br>
</p>

### Emitância

Após a seção anterior, foi criado a emitância, ou seja, definindo ou não se certa "parte" será quem emite luz ou não, e usando uma pequena fonte de luz, o resultado foi o seguinte:

<p align="center">
	<br>
	<img src="./images/img2.png"/>
	<h5 align="center">Figura 2 - Começando a usar emitância</h5>
	<br>
</p>

A qualidade da imagem não fica muito boa, pois os raios que não encontram o modelo, não são rebatidos de lugar algum, e os que encontram, não rebatem em nada, assim, ficando com essa qualidade.

Com isso, resolvi inserir um cenário, assim, podendo testar melhor como estava funcionando a emitância e também, ver se os raios secundários estavam certos, assim, gerando o seguinte resultado:

<p align="center">
	<br>
	<img src="./images/img3.png"/>
	<h5 align="center">Figura 3 - Testando emitância junto com raios secundários</h5>
	<br>
</p>

O resultado, na minha opinião, foi satisfatório, porém, eu desejei melhorar mais ainda a imagem, pra ver se não faltava mais algo, com isso, aumentei a quantidade de raios por pixel e aumentei a profundidade (eu queria ver se mudando muito a profundidade, alterava em algo), e o resultado ficou da seguinte maneira:

<p align="center">
	<br>
	<img src="./images/img4.png"/>
	<h5 align="center">Figura 4 - Teste de emitância e raios secundários com mais amostras</h5>
	<br>
</p>

Eu, particularmente, gostei do resultado, mas como ainda não tinha feito a parte de material e brdf, dá pra notar como a imagem fica artificial, principalmente o lado direito, a cor azul.

### Inserindo Materiais

Após terminar a parte dos materiais, obtive o seguinte resultado:

<p align="center">
	<br>
	<img src="./images/img5.png"/>
	<h5 align="center">Figura 5 - Utilizando materiais difusos</h5>
	<br>
</p>

A imagem acima foi utilizado 1000 raios por pixel, 4 threads e 5 de profundidade, onde demorou cerca de 2 minutos e 12 segundos.

Com isso, resolvi usar mais raios por pixel e mudar um pouco a profundidade, pra ver o quão diferente ficaria:

<p align="center">
	<br>
	<img src="./images/img6.png"/>
	<h5 align="center">Figura 6 - Aumentando a quantidade de raios por pixel</h5>
	<br>
</p>

Para gerar essa imagem, utilizei 5000 raios por pixel, 4 threads e 10 de profundidade, onde demorou cerca de 

Colocando as duas imagens lado a lado, podemos ver melhor a diferença entre cada uma:

<p align="center">
	<br>
    <img src="./images/img5.png" width="375" hspace="20"/> <img src="./images/img6.png" width="375"/>
	<h5 align="center">Figura 7 - Comparação entre as figuras 5 e 6</h5>
	<br>
</p>