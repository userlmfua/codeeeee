#include <iostream>
#include <cmath>
using namespace std;
struct CELL 
{ 
    unsigned short character  : 8;
    unsigned short foreground : 3;
    unsigned short intensity  : 1;
    unsigned short background : 3;
    unsigned short blink      : 1;
} screen[25][80];

int main() {
    setlocale(LC_ALL,"rus");
    CELL mandarin;
    cout << "Путь мандарина = "     << &mandarin           << endl;
    mandarin.character   = 'g';
    mandarin.intensity   = 0;
    mandarin.blink       = 1;
    mandarin.foreground  = 3;
    
    cout << "mandarin.character = "  << mandarin.character  << endl;
    cout << "mandarin.intensity = "  << mandarin.intensity  << endl;
    cout << "mandarin.blink = "      << mandarin.blink      << endl;
    cout << "mandarin.foreground = " << mandarin.foreground << endl;

    unsigned char* bytePtr=reinterpret_cast<unsigned char*>(&mandarin);
    *bytePtr |= (1<<(3));

    cout << "После изменения " << endl;
    cout << "mandarin.character = "  << mandarin.character  << endl;
    cout << "mandarin.intensity = "  << mandarin.intensity  << endl;
    cout << "mandarin.blink = "      << mandarin.blink      << endl;
    cout << "mandarin.foreground = " << mandarin.foreground << endl;

    cout << "Получение байтов в памяти " << endl;
    unsigned char* bytes = reinterpret_cast<unsigned char*>(&mandarin);
    cout << std::hex << static_cast<int>(bytes[0]) << endl;
    cout << std::hex << static_cast<int>(bytes[1]) << endl;

    cout<< "После еще одного изменения "<<endl;
    cout << "mandarin.character = "  << mandarin.character  << endl;
    cout << "mandarin.intensity = "  << mandarin.intensity  << endl;
    cout << "mandarin.blink = "      << mandarin.blink      << endl;
    cout << "mandarin.foreground = " << mandarin.foreground << endl;

    return 0;
} 