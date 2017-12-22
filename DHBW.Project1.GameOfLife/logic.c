#include <stdio.h>
#include <stdbool.h>

int main(void) {

	bool isrunning = true;
	while (isrunning)
	{
		int a; //variable welche Nachbarfelder zählt
		bool sp[100][100];	 //Array für Spielbrett
		for (int i = 0; i <= 99; i++) {			//initialisieren der Felder per Zufall
			for (int j = 0; j <= 99; j++) {
				int r = rand() % 10;
				if (r > 4) {
					sp[i][j] = true;
				}
				else {
					sp[i][j] = false;
				}
			}
		}

		//Logik die definiert, ob Zellen leben oder sterben
		for (int i = 0; i <= 99; i++) {
			for (int j = 0; j <= 99; j++) {

				//Fall Feld links oben
				if (j == 0 && i == 0) {
					a = sp[i + 1][j] + sp[i][j + 1] + sp[i + 1][j + 1];
				}

				//Fall Feld rechts oben
				if (j == 0 && i == 99) {
					a = sp[i - 1][j] + sp[i][j + 1] + sp[i - 1][j + 1];
				}

				//Fall Feld links unten
				if (j == 99 && i == 0) {
					a = sp[i + 1][j] + sp[i][j - 1] + sp[i + 1][j - 1];
				}

				//Fall Feld rechts unten
				if (j == 99 && i == 99) {
					a = sp[i - 1][j] + sp[i][j - 1] + sp[i - 1][j - 1];
				}

				//Fall für Spalte 0 (außer den Eckfeldern)
				if (j != 99 && j != 0 && i == 0) {
					a = sp[i + 1][j] + sp[i][j - 1] + sp[i][j + 1] + sp[i + 1][j + 1] + sp[i + 1][j - 1];
				}
				//Fall für Spalte 100 (außer den Eckfeldern)
				if (j != 99 && j != 0 && i == 99) {
					a = sp[i - 1][j] + sp[i][j - 1] + sp[i][j + 1] + sp[i - 1][j + 1] + sp[i - 1][j - 1];
				}

				//Fall für Zeile 0 (außer den Eckfeldern)
				if (j == 0 && i != 0 && i != 99) {
					a = sp[i - 1][j] + sp[i + 1][j] + sp[i][j + 1] + sp[i + 1][j + 1] + sp[i - 1][j + 1];
				}

				//Fall für Zeile 100 (außer den Eckfeldern)
				if (j == 99 && i != 0 && i != 99) {
					a = sp[i - 1][j] + sp[i + 1][j] + sp[i][j - 1] + sp[i + 1][j - 1] + sp[i - 1][j - 1];
				}

				//Fall für alle Felder, die nicht am Rand sind
				if ((i < 99) && (j < 99) && (i > 0) && (j > 0)) {
					a = sp[i - 1][j] + sp[i - 1][j - 1] + sp[i + 1][j] + sp[i][j - 1] + sp[i][j + 1] + sp[i + 1][j + 1] + sp[i + 1][j - 1] + sp[i - 1][j + 1];
				}

				//definiert ob lebende Zelle sterben soll
				if (sp[i][j] == true) {
					if (a != 2 || a != 3) {
						sp[i][j] == false;
					}
				}
				//definiert ob tote Zelle leben soll
				else {
					if (a == 3) {
						sp[i][j] == true;
					}
				}

			}
		}
	}
	return 0;
}