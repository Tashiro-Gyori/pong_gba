//
// pong.c
//

#include "toolbox.h"
#include "input.h"

#include "pad_blue.h"

#define P1_X 24
#define P1_Y 65
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

	REG_DISPCNT= DCNT_MODE3 | DCNT_BG2;

	// Rectangles:
 	/*m3_rect( P1_X, P1_Y, P1_X + P_WIDTH, P1_Y + P_HEIGHT, CLR_BLUE); // put in variables the rect (so we can move them ;-;) ?
	m3_rect( P2_X, P2_Y, P2_X + P_WIDTH, P2_Y + P_HEIGHT, CLR_RED);
	m3_rect( BALL_X, BALL_Y, BALL_X + BALL_SIZE, BALL_Y + BALL_SIZE, CLR_WHITE);*/

	/*while(1)
		{
				vid_vsync();

				if(key_hit(KEY_A)){
					m3_rect( P1_X + 24, P1_Y, P1_X + P_WIDTH + 24, P1_Y + P_HEIGHT, CLR_BLUE);
				}

		}*/

	while(1);

	return 0;
}
