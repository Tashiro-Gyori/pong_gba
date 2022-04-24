//
// pong.c
//

#include "toolbox.h"
#include "input.h"


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
	int diff = 0;

	REG_DISPCNT= DCNT_MODE3 | DCNT_BG2;

	while(1) {
		vid_vsync(); // prefer VBlankIntrWait(); ?
		key_poll();

		// pour débugger
		//m3_puts(0,0, "Hello world", 0); // prob : ds tonc-text mais pas fonction pas déf dans le bin?!

		if(diff != 0) {
			//m3_fill(0);
			// colorier en noir la partie sup ou inf
			if(diff == 1){
				m3_rect(P1_X, 0, P1_X + P_WIDTH, P1_Y, CLR_BLACK);
			}
			else{
				// todo : enlever 260 et -1 pour effacer le pixel
				m3_rect(P1_X, P1_Y + P_HEIGHT + 1, P1_X + P_WIDTH, 260, CLR_BLACK);
			}		
		}
		
		m3_rect(P1_X, P1_Y + diff * (-1), P1_X + P_WIDTH, P1_Y + P_HEIGHT, CLR_BLUE);

		m3_rect(P2_X, P2_Y, P2_X + P_WIDTH, P2_Y + P_HEIGHT, CLR_RED);
		m3_rect(BALL_X, BALL_Y, BALL_X + BALL_SIZE, BALL_Y + BALL_SIZE, CLR_WHITE);

		if(key_tri_vert() == 1 && P1_Y + P_HEIGHT <= 160) {
			P1_Y ++;
			diff = 1;
		}
		else if(key_tri_vert() == -1 && P1_Y >= 0) {
			P1_Y --;
			diff = -1;
		}
		
	}

	return 0;
}
