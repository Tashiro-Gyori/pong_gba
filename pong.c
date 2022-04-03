//
// pong.c
//

#include "toolbox.h"
#include "input.h"

#include "pad_blue.h"

#define P2_X 206
#define P2_Y 65
#define P_WIDTH 12
#define P_HEIGHT 30

#define BALL_X 50
#define BALL_Y 76
#define BALL_SIZE 8

int main()
{
	// à vérif: obj afficher bitmap
	//memcpy(vid_mem, gba_picBitmap, gba_picBitmapLen);
	//memcpy(pal_bg_mem, gba_picPal, gba_picPalLen);

	int P1_X = 24;
	int P1_Y = 65;

	REG_DISPCNT= DCNT_MODE3 | DCNT_BG2;

	// n'a l'air de rien afficher ???
	while(1) {
		m3_rect(P1_X, P1_Y, P1_X + P_WIDTH, P1_Y + P_HEIGHT, CLR_BLUE);
		m3_rect(P2_X, P2_Y, P2_X + P_WIDTH, P2_Y + P_HEIGHT, CLR_RED);
		m3_rect(BALL_X, BALL_Y, BALL_X + BALL_SIZE, BALL_Y + BALL_SIZE, CLR_WHITE);

		if(key_tri_vert() == 1) {
			P1_X++;
		}
		else if(key_tri_vert() == -1) {
			P1_X--;
		}
	}

	/*while(1)
		{
				vid_vsync();

				if(key_hit(KEY_A)){
					m3_rect( P1_X + 24, P1_Y, P1_X + P_WIDTH + 24, P1_Y + P_HEIGHT, CLR_BLUE);
				}

		}*/

	return 0;
}
