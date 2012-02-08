/* codepage: UTF-8
 *
 *          Файл: urltotxt.cpp
 * Дата создания: 8 февраля 2012 год
 * 
 *      Описание: Программа для преобразования URL с элементами вида %XX
 *                в читаемый текст. Работает в окружении с кодирвокой UTF-8.
 *                Берет URL из стандартного потока и отдает результат туда же.
 * 
 *         Автор: Бравиков Дмитрий (bravikov@gmail.com)
 *
*/

#include <iostream>

using namespace std;

int main(int argc, char * argv[])
{
  string url;
  string txt;
  
  cin >> url;
  
  bool percent = false;
  bool error   = false;
  char part_c = 0;
  
  for (unsigned i = 0; i < url.size(); i++)
  {
    char c = url.at(i);
    
    if (percent)
    {   
      if (c >= '0' && c <= '9')      c -= '0';
      else if (c >= 'a' && c <= 'f') c += (0x0A - 'a');
      else if (c >= 'A' && c <= 'F') c += (0x0A - 'A');
      else { error = true; break; }
      
      if (part_c)
      {
        txt += (part_c + c);
        part_c = 0;
        percent = false;
      }
      else
        part_c = (c << 4);
      
      continue;
    }

    if ( c != '%')
      txt += c;
    else
      percent = true;
  }
  
  if (percent || error)
  {
    cout << "Ошибка: недействительный URL" << endl;
    return 1;
  }
  
  cout << txt << endl;
    
  return 0;
}

