#include <windows.h>
#include <fstream>
#include <iostream>

using namespace std;
void clear() {
    COORD topLeft  = { 0, 0 };
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen;
    DWORD written;

    GetConsoleScreenBufferInfo(console, &screen);
    FillConsoleOutputCharacterA(
        console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    );
    FillConsoleOutputAttribute(
        console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
        screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    );
    SetConsoleCursorPosition(console, topLeft);
}

class Keyclick{
	private:
	int key;
	char id;
	public:
	bool keydown = false;
	Keyclick(int key1, char id1){
		key=key1;
		id=id1;
	};
	void watch(){
		if(keydown==false){
			if(GetKeyState(key) & 0x8000 ){
				cout << id;
				cout << "  pressed.\r\n";
				keydown = true;
			}
		}
		if(keydown == true){
			if(!(GetKeyState(key) & 0x8000)) {
				cout << "released!!!!!!!!!!\r\n";
				keydown = false;
				clear();
			}
		}
	};
};

int main()
{
	bool primaryloop =true;
	Keyclick keysp(VK_SPACE,'S');
	Keyclick keyw(0x57,'w');
	Keyclick keya(0x41,'a');
	Keyclick keys(0x53,'s');
	Keyclick keyd(0x44,'d');
	Keyclick keyesc(VK_ESCAPE,'E');
	
    while(primaryloop){
		keysp.watch();
		keyw.watch();
		keya.watch();
		keys.watch();
		keyd.watch();
		keyesc.watch();
		
		if(keyesc.keydown){
			primaryloop=false;
		};		
    }
    return 0;
}