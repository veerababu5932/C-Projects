#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
void hai(const char *text)
{
	int i;
	for(i=0; text[i]!='\0';i++)
	{
		keybd_event(VkKeyScanA(text[i]),0,0,0);
		keybd_event(VkKeyScanA(text[i]),0,KEYEVENTF_KEYUP,0);
	}
	Sleep(1000);
}
void mouseClick(int x, int y)
{
    SetCursorPos(x,y);
    Sleep(1000);  // Longer delay to ensure cursor moves
    mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
    Sleep(1000);
    mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
}
int main()
{
	system("start chrome https:\\ www.youtube.com");
	Sleep(3000);
	keybd_event(VkKeyScanA('/'),0,0,0);
	keybd_event(VkKeyScanA('/'),0,KEYEVENTF_KEYUP,0);
	Sleep(1000);
	const char *song="i hate you forever";
	hai(song);
	Sleep(100);
	keybd_event(VK_RETURN ,0,0,0);
	keybd_event(VK_RETURN,0, KEYEVENTF_KEYUP,0);
	Sleep(1000);
	mouseClick(400,400);
	
	}
 
