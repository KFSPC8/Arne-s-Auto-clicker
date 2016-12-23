// Arne's Auto Clicker
#include <iostream>
#include <windows.h>
#include <stdlib.h>

using namespace std;

const float INTERVAL = 42;

void getMousePos (long&, long&);
void printMenu (HWND, char []);

int main ()
{
	SetConsoleTitle("Arne's Auto Clicker"); 
	
	static bool isClickerOn = false;	
	
	while (!GetAsyncKeyState(VK_F8))
	{
		HWND hwnd;
		char str[50] = "BlueStacks App Player";
		
		printMenu(hwnd, str);
		cout << ((isClickerOn == false) ? "Auto-clicker is: [OFF]" : "Auto-clicker is: [ON]") << endl;	
		
		static long xPos = 0, yPos= 0;
			
		if (GetAsyncKeyState(VK_F2))
		{	 	 	 
				isClickerOn = ((isClickerOn == true) ? false : true);
				
				while (isClickerOn == true)
				{
					if (GetAsyncKeyState(VK_F2))
					{
						isClickerOn = false;
						break;
					}
					else
					{	
						printMenu(hwnd, str);
						cout << ((isClickerOn == false) ? "Auto-clicker is: [OFF]" : "Auto-clicker is: [ON]") << endl;
						mouse_event(MOUSEEVENTF_LEFTDOWN, xPos, yPos, 0, 0);
						mouse_event(MOUSEEVENTF_LEFTUP, xPos, yPos, 0, 0);
						Sleep(INTERVAL);	
					} 	  
				}
		}	
			
		Sleep(600);
	}

}

void getMousePos (long &x, long &y)
{
	POINT p;
	GetCursorPos(&p);
	
	x = p.x;
	y = p.y;
	
	GetCursorPos(&p);
	if (p.x != x && p.y != y)
	{
		x = p.x;
		y = p.y;
		cout << x << ", " << y << endl;
	}	
}

void printMenu (HWND hwnd, char str[])
{
	system("cls");
		
	cout << "==================================" << endl
		 << "==\tArne's auto clicker\t==" << endl 
		 << "==================================" << endl;
		
	hwnd = FindWindow(NULL, str);
	
	cout << "\nTarget window is: '" << str << "'"<< endl;
	if (hwnd != NULL)
		cout << "Target status: [FOUND]" << endl;
	else
		cout << "Target status: [NOT FOUND]" << endl;
		
	cout << "--------------------------------------" << endl	  
		 << "\nPress F2 to start auto-clicking" << endl
		 << "Press F8 to exit\n" << endl 
		 << "--------------------------------------" << endl;
		 
	cout << "\nClicking interval is: " << INTERVAL/1000 << "s" << endl;  
}

