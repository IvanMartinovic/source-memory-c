#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <math.h>


int main() {

	char prvo = 'e', drugo = 'a';
	char red[200];
	int uk = 0, i = 0, br_prvo = 0, br_drugo = 0, br_prvodrugo = 0, niz[] = { 1000, 10000, 100000 }, k = 0, b = 1;
	FILE *knjiga;


	knjiga = fopen("knjiga.txt", "r");
	if (knjiga == NULL) {
		perror("Greska u otvaranju knjige");
		getchar();
		return(-1);
	}



	fseek(knjiga, 0, SEEK_SET);
	while (fgets(red, 200, knjiga)) {

		i = 0;
		while (red[i]) {
			if (red[i] == prvo) { br_prvo++; if (red[i + 1] == drugo) br_prvodrugo++; }
			if (red[i] == drugo)  br_drugo++;
			i++;

		}
		uk += i - 1;
		if (uk >= niz[k])
		{
			float p_drugo = (float)br_drugo / uk;
			float p_drugousl = (float)br_prvodrugo / br_prvo;
			printf("%d.\n", b++);
			printf("Ukupan broj stampajucih karaktera je %d \n", uk);
			printf("Ukupan broj pojavljivanja slova %c je %d \n", prvo, br_prvo);
			printf("Ukupan broj pojavljivanja slova %c je %d \n", drugo, br_drugo);
			printf("Ukupan broj pojavljivanja para %c%c je %d \n\n", prvo, drugo, br_prvodrugo);
			printf("Verovatnoca pojavljivanja slova %c je         P(%c)  = %f \n", drugo, drugo, p_drugo);
			printf("Verovatnoca pojavljivanja slova %c posle %c je P(%c|%c)= %f\n", drugo, prvo, drugo, prvo, p_drugousl);
			printf("P(%c|%c)-P(%c)=%f\n\n", drugo, prvo, drugo, p_drugousl - p_drugo);
			if (k == 2) break;
			k++;
		}
	} getchar(); return 0;
}
