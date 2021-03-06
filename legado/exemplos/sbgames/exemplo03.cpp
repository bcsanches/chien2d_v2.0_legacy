/*
Copyright 2008-2010, Paulo Vinicius Wolski Radtke (pvwradtke@gmail.com)

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

#include <c2d2/chien2d2.h>
#include <math.h>

#define RESX    800
#define RESY    600
#define NUM_BALOES  50

int main(int ac, char **av)
{
	unsigned int balao;
	int baloes[NUM_BALOES][2], conta;
	C2D2_Botao *teclas = C2D2_PegaTeclas();
	if(!C2D2_Inicia(RESX, RESY, C2D2_JANELA, C2D2_DESENHO_PADRAO, "Baloes"))
		return 1;
	C2D2_TrocaCorLimpezaTela(128, 128, 255);
	for(conta=0;conta<NUM_BALOES;conta++)
	{
		baloes[conta][0] = random()%RESX;
		baloes[conta][1] = random()%RESY;
	}
	balao = C2D2_CarregaSpriteSet("balao.png", 35,50);
	if(0 == balao)
	{
		C2D2_Encerra();
		return 1;
	}
	while(!teclas[C2D2_ESC].pressionado && !teclas[C2D2_ENCERRA].pressionado)
	{
		for(conta=0;conta<NUM_BALOES;conta++)
			if(--baloes[conta][1] < -35)
			{
				baloes[conta][0] = random()%RESX;
				baloes[conta][1] = RESY;        
			}
		C2D2_LimpaTela();
		for(conta=0;conta<NUM_BALOES;conta++)
			C2D2_DesenhaSprite(balao, 0, baloes[conta][0], baloes[conta][1]);
		C2D2_Sincroniza(C2D2_FPS_PADRAO);
	}
	C2D2_RemoveSpriteSet(balao);
	C2D2_Encerra();
	return 0;
}
