#include <c2d2/chien2d2.h>

int main(int ac, char **av)
{
	unsigned int balao;
	if(!C2D2_Inicia(800, 600, C2D2_JANELA, 
		C2D2_DESENHO_PADRAO, "Baloes"))
		return 1;
	C2D2_TrocaCorLimpezaTela(128, 128, 255);
	balao = C2D2_CarregaSpriteSet("balao.png",
		35,50);
	if(0 == balao)
	{
		C2D2_Encerra();
		return 1;
	}
	C2D2_LimpaTela();
	C2D2_DesenhaSprite(balao, 0, 100,100);
	C2D2_Sincroniza(C2D2_FPS_PADRAO);
	C2D2_Pausa(5000);
	C2D2_RemoveSpriteSet(balao);
	C2D2_Encerra();
	return 0;
}
