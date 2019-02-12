# odometro_hall_pic16f876
odometro com LCD 8x2
Projeto destina-se a equipamento de medida de distâncias.
O hardware possui um LCD 8x2, para exibir a medida de uma roda, o numero de voltas de ímã, em sensor hall.
O processador utilizado 16f876, vamos utilizar um timer dedicado a um pino RA4 (timer0), fazendo a leitura de transição de nivel (L_TO_H) baixo para alto. O numero de pulsos nesse pino é então multiplicado pela circunferencia da roda.  Com isso podemos medir grandezas de centenas de metros, com precisão entre 10 a 20 cm. dependendo do material da roda utilizada
