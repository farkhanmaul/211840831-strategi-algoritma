// Praktikum 10: String Matching
// Penerapan contoh dengan algoritma Boyer-Moore
#include <windows.h>
#include <iostream>
#include <string>
#include "draws.h"
using namespace std;
// global Graph
Graph graph;
char markText[1024];
string ptext;
string pattern;
int startIdx;
// fungsi untuk menandai jalur hasil pencarian
void drawResult()
{
	glPushMatrix();
	sprintf(markText, "%s", ptext.c_str());
	Vec3 position(-350.0f, 0.0f, 0.0f);
	Vec3 color1(1.0f, 1.0f, 1.0f);
	Vec3 color2(1.0f, 0.0f, 1.0f);
	if (startIdx >= 0)
		drawText(position, color1, color2, markText, 2.0f, startIdx,
				 pattern.length());
	else
		drawText(position, color1, color1, markText, 2.0f, 0, pattern.length());
	glPopMatrix();
}
// taruh semua obyek yang akan digambar di fungsi display()
void displayGraph()
{
	// bersihkan dan reset layar dan buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	// posisikan kamera pandang
	gluLookAt(0.0f, 0.0f, 2.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
	// panggil fungsi untuk menggambar obyek
	drawResult();
	// tampilkan obyek ke layar
	glutSwapBuffers();
}

#define NO_OF_CHARS 256

// The preprocessing function for Boyer Moore's
// bad character heuristic
int badCharHeuristic(string str, int size, int badchar[NO_OF_CHARS])
{
	int i;
	// Initialize all occurrences as -1
	for (i = 0; i < NO_OF_CHARS; i++)
		badchar[i] = -1;

	// Fill the actual value of last occurrence
	// of a character
	for (i = 0; i < size; i++)
		badchar[(int)str[i]] = i;
}
/* pattern searching function yang menggunakan Bad
Character Heuristic dari Boyer Moore Algorithm */
int search(string text, string pattern)
{
	int m = pattern.length();
	int n = text.length();
	int badchar[NO_OF_CHARS];
	badCharHeuristic(pattern, m, badchar);

	int s = 0; // s is shift of the pattern with
			   // respect to text
	while (s <= (n - m))
	{
		int j = m - 1;
		while (j >= 0 && pattern[j] == text[s + j])
			j--;

		if (j < 0)
		{
			cout << "pola berada pada posisi = " << s << endl;
			startIdx = s;
			s += (s + m < n) ? m - badchar[text[s + m]] : 1;
		}
		else
			s += max(1, j - badchar[text[s + j]]);
	}
}

// kode tester
int main(int argc, char **argv)
{
	// teks yang akan dicocokkan
	ptext = "abacaabacabacababa";
	// pola yang akan dicocokkan
	pattern = "acabaca";
	cout << "cari: [" << pattern << "] di dalam teks: [" << ptext << "]\n";
	// penerapan algoritma Boyer Moore
	// startIdx =
	search(ptext, pattern);
	// cout<<startIdx<<" : ";
	//  inisialisasi jendela OpenGL
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	// set ukuran jendela tampilan dalam piksel
	glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	// posisi jendela dilayar komputer dalam piksel
	glutInitWindowPosition(100, 100);
	// judul jendela (isi dengan NAMA / NIM - JUDUL PRAKTIKUM)
	glutCreateWindow("Muhammad Farkhan Maulana / 2000018280 - POSTTEST 10 SA");
	// panggil fungsi init untuk inisialisasi awal
	initView();
	// event handler untuk display
	glutDisplayFunc(displayGraph);
	glutReshapeFunc(reshapeView);
	// looping
	glutMainLoop();
	return 0;
}

