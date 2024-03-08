#include <iostream>
#include "Mylib.h"
#define MAX 100//Khởi tạo số lượng phần tử tối đa của mảng
using namespace std;

//===================== 4 Level cơ bản để tạo ra 1 trò chơi rắn săn mồi ================================
#if 0
int main()
{
    
    //Level 1: Cách di chuyển vật thể
#if 0
    int i = 1;//Biến màu, dùng để xác định giá trị màu
    int x = 10, y = 0;//Tọa độ x và y
    while (true)//vòng lặp để di duyển vật thể 
    {
    gotoXY(x, y);/*Hàm di chuyển con trỏ đến toa độ x y mà ta đã set tọa độ bất kỳ cho x và y của thư viện Mylib ta đã cài
    bên file Mylib.h*/
    cout << "Hoc lap trinh that de!";//Vật thể

    SetColor(i);/*Hàm để set màu cho vật thể của thư viên Mylib của ta đã cài ở thư viện Mylib. Tham số truyền vào là 1 mã
    màu với tham số truyền vào là i và i là đoạn màu nằm từ 1 đến 15*/
    i++;//Mõi lần i tăng là vật thể đc set 1 màu mới
    if (i > 15)//Vì mã màu của i chỉ có từ 1 đến 15 thôi nếu i vượt quá 15 thì
    {
        i = 1;//Cho i chạy lại mã màu từ 1
    }

    y++;//Tăng x hoặc y để di chuyển vật thể đến điểm x và y ta tăng
    
    Sleep(50);//Chỉnh tốc độ lặp của vòng lặp là 50 thôi. 50 là 50ms <=> 0.05s/lần lặp
    }
#endif // 0

    
    //Level 2: Di chuyển có biên(Tức di chuyển đến 1 điểm biên đó thì vật thể dừng lại ngay biên)
#if 0
int i = 1;//Biến màu, dùng để xác định giá trị màu

    /*Level 2*/int check = 0;/* - 0 là chạm vào biên trên. Khi vật thể chạm vào biên trên thì phải cho vật thể đi xuống bằng cách tăng tọa độ Oy lên
                               - 1 là chạm vào biên dưới. Khi vật thể chạm vào biên dưới thì phải cho vật thể đi lên bằng cách giảm tọa độ Oy xuống*/
    
    int x = 10, y = 0;//Tọa độ x và y
    /*Level 2*/int xcu = x, ycu = y;//Hai biến xcu và ycu để giữ tọa độ (x,y) cũ sau khi thực hiện xóa dữ liệu cũ bằng Backspace
    while (true)//vòng lặp để di duyển vật thể 
    {
        /*Xóa dữ liệu cũ
    - Cách 1: System("cls"); Làm nháy vật thể tĩnh liên tục rất là xấu
    - Cách 2: Backspace;
     Backspace nó sẽ hoạt động như sau mõi thực thi Backspace sẽ xóa 1 ký tự và đè lên ký tự vừa xóa là 1 khoản trắng và lùi con trỏ về vị trí
     kế ký tự vị xóa gọi là vị trí cũ và in ra dữ liệu vừa mất đi 1 ký tự. để có vị trí cũ ta phải có biến giữ tọa độ cũ là x và y
     ví dụ:  ta nhập hello thì khi Backspace thực hiện nó sẽ
     1-> hellcontrỏchuộtđcdịchtớiđây"đây là khoảng trắng đè lên ký tự bị xóa"
     2-> cuối cùng kết quả là: hell */

        ///*Cách xóa dữ liệu cũ bằng cách 1 dùng system("cls")
        //Level 2*/ system("cls");/*Mõi lần vật thể di chuyển thì phải xóa vị trí của vật thể cũ đi để hiện vị trí mới của vật thể di chuyển đến
        //                         vì mõi lần lặp ta set Ox và Oy tăng hoặc giảm để truyền vào hàm gotoXY(x, y) di chuyển vật thể đến 1 vị trí mà ta 
        //                         đã set Ox và Oy tăng hoặc giảm. system("cls") làm nháy các vật thể tĩnh cách 1 này sẽ làm vật di chuyển rất xấu*/

       /*Xóa dữ liệu cũ bằng cách 2 dùng thuật Backspace
       Level 2*/gotoXY(xcu, ycu);//Cần di chuyển vật đến vị trí cũ trước khi xóa vị trí cũ để xóa trước khi thực hiện đến vị trí mới
       cout << "                      ";/*Tạo 1 khoảng trắng tương ứng với độ dài của vật đề dùng khoảng trăng lấp vị trí cũ của vật vì vật ta tạo có 
       độ dài ngang là 22 ký tự nên phải tạo 1 khoảng trắng tương ứng là 22 ký tự là khoảng trắng.*/

        gotoXY(x, y);/*Hàm di chuyển con trỏ đến toa độ x y mà ta đã set tọa độ bất kỳ cho x và y của thư viện Mylib ta đã cài
        bên file Mylib.h*/
        cout << "Hoc lap trinh that de!";/*Vật thể. /Level 2/ vật thể ta tạo Có 22 ký tự tương đương với xóa bằng backspace ta phải tạo ra 1 khoảnh
        trắng có 22 ký tự là khoảng trắng để lắp vị trí cũ của vật đã di chuyển đến trước khi vật di chuyển đến 1 vị trí mới*/
        /*Level 2*/xcu = x;
                   ycu = y;/*Sau khi vật di chuyển đến 1 vị trí mới thì ta phải bắt tọa độ vị trí của vật vừa di chuyển đến để khi vòng lặp while thực 
                   thi nghĩa là vật di chuyể đến vị trí có tọa độ mới nên mõi lần vật di chuyển đến 1 vị trí mới thì ta bắt vị trí mà vật vừa di chuyển
                   đến bằng cách cho biến xcu = x và ycu = y để mõi lần di chuyển đến vị trí mới thì phải dùng backspace để xóa vị trí cũ bằng các đè
                   khoảng trắng có độ dài tương ứng với độ dài của vật*/

        SetColor(i);/*Hàm để set màu cho vật thể của thư viên Mylib của ta đã cài ở thư viện Mylib. Tham số truyền vào là 1 mã
        màu với tham số truyền vào là i và i là đoạn màu nằm từ 1 đến 15*/
        i++;//Mõi lần i tăng là vật thể đc set 1 màu mới
        if (i > 15)//Vì mã màu của i chỉ có từ 1 đến 15 thôi nếu i vượt quá 15 thì
        {
            i = 1;//Cho i chạy lại mã màu từ 1
        }

         //Kiểm tra hướng
       /*Level 2*/ if (check == 0)//Nếu chạm biên trên
        {
           y++;//Cho vật thể đi xuống bằng cách tăng tọa độ Oy lên 
        }
       else if(check == 1)//Nếu chạm biên dưới
       {
           y--;//Cho vật thể đi lên bằng cách giảm tọa độ Oy xuống 
       }

       //Kiểm tra biên
       /*Level 2*/if (y == 28)/*Ta set 1 cái biên y (y là chiều dọc tọa O là y = 0 và x = 0 y = 0 y tăng thì vật đi xuống còn y giảm về bằng 0 là vật
           về lại tọa độ y gốc ban đầu là nằm biên trên) có bề dọc là từ 0 - 28*/
       {
           check = 1;/*Nếu y đi đến tận biên dưới thì cho y đi lên lại vì ta đã set điều kiện( else if(check == 1)//Nếu chạm biên dưới
           {
               y--;//Cho vật thể đi lên bằng cách giảm tọa độ Oy xuống 
           })*/
       }
       else if (y == 0)//Nếu y chạm biên trên
       {
           check = 0;/*Nếu y đi đến tận biên trên thì cho y đi xuống lại vì ta đã set điều kiện if (check == 0)//Nếu chạm biên trên
           {
               y++;//Cho vật thể đi xuống bằng cách tăng tọa độ Oy lên 
           }*/
       }
     

        Sleep(10);/*Chỉnh tốc độ lặp của vòng lặp là 50 thôi. 50 là 50ms <=> 0.05s/lần lặp. Tương ứng với chỉnh tốc độ di chuyển của vật thể luôn
        càng tăng thì tốc độ di chuyển của vật càng chậm và ngược lại càng giảm là tốc độ di chuyển càng nhanh*/
    }
#endif // 0

    
    //Level 3: di chuyển vật thể có biên + phím(Nhấn w là đi lên, nhấn s là đi xuống) lên xuống thì phụ thuộc vào y
#if 0
int i = 1;//Biến màu, dùng để xác định giá trị màu

    /*Level 2*/int check = 0;/* - 0 là chạm vào biên trên. Khi vật thể chạm vào biên trên thì phải cho vật thể đi xuống bằng cách tăng tọa độ Oy lên
                               - 1 là chạm vào biên dưới. Khi vật thể chạm vào biên dưới thì phải cho vật thể đi lên bằng cách giảm tọa độ Oy xuống*/

    int x = 10, y = 0;//Tọa độ x và y
    /*Level 2*/int xcu = x, ycu = y;//Hai biến xcu và ycu để giữ tọa độ (x,y) cũ sau khi thực hiện xóa dữ liệu cũ bằng Backspace
    while (true)//vòng lặp để di duyển vật thể 
    {
        /*Xóa dữ liệu cũ
    - Cách 1: System("cls"); Làm nháy vật thể tĩnh liên tục rất là xấu
    - Cách 2: Backspace;
     Backspace nó sẽ hoạt động như sau mõi thực thi Backspace sẽ xóa 1 ký tự và đè lên ký tự vừa xóa là 1 khoản trắng và lùi con trỏ về vị trí
     kế ký tự vị xóa gọi là vị trí cũ và in ra dữ liệu vừa mất đi 1 ký tự. để có vị trí cũ ta phải có biến giữ tọa độ cũ là x và y
     ví dụ:  ta nhập hello thì khi Backspace thực hiện nó sẽ
     1-> hellcontrỏchuộtđcdịchtớiđây"đây là khoảng trắng đè lên ký tự bị xóa"
     2-> cuối cùng kết quả là: hell */

     ///*Cách xóa dữ liệu cũ bằng cách 1 dùng system("cls")
     //Level 2*/ system("cls");/*Mõi lần vật thể di chuyển thì phải xóa vị trí của vật thể cũ đi để hiện vị trí mới của vật thể di chuyển đến
     //                         vì mõi lần lặp ta set Ox và Oy tăng hoặc giảm để truyền vào hàm gotoXY(x, y) di chuyển vật thể đến 1 vị trí mà ta 
     //                         đã set Ox và Oy tăng hoặc giảm. system("cls") làm nháy các vật thể tĩnh cách 1 này sẽ làm vật di chuyển rất xấu*/

    /*Xóa dữ liệu cũ bằng cách 2 dùng thuật Backspace
    Level 2*/gotoXY(xcu, ycu);//Cần di chuyển vật đến vị trí cũ trước khi xóa vị trí cũ để xóa trước khi thực hiện đến vị trí mới
    cout << "                      ";/*Tạo 1 khoảng trắng tương ứng với độ dài của vật đề dùng khoảng trăng lấp vị trí cũ của vật vì vật ta tạo có
    độ dài ngang là 22 ký tự nên phải tạo 1 khoảng trắng tương ứng là 22 ký tự là khoảng trắng.*/

    gotoXY(x, y);/*Hàm di chuyển con trỏ đến toa độ x y mà ta đã set tọa độ bất kỳ cho x và y của thư viện Mylib ta đã cài
    bên file Mylib.h*/
    cout << "Hoc lap trinh that de!";/*Vật thể. /Level 2/ vật thể ta tạo Có 22 ký tự tương đương với xóa bằng backspace ta phải tạo ra 1 khoảnh
    trắng có 22 ký tự là khoảng trắng để lắp vị trí cũ của vật đã di chuyển đến trước khi vật di chuyển đến 1 vị trí mới*/
    /*Level 2*/xcu = x;
    ycu = y;/*Sau khi vật di chuyển đến 1 vị trí mới thì ta phải bắt tọa độ vị trí của vật vừa di chuyển đến để khi vòng lặp while thực
    thi nghĩa là vật di chuyể đến vị trí có tọa độ mới nên mõi lần vật di chuyển đến 1 vị trí mới thì ta bắt vị trí mà vật vừa di chuyển
    đến bằng cách cho biến xcu = x và ycu = y để mõi lần di chuyển đến vị trí mới thì phải dùng backspace để xóa vị trí cũ bằng các đè
    khoảng trắng có độ dài tương ứng với độ dài của vật*/

    SetColor(i);/*Hàm để set màu cho vật thể của thư viên Mylib của ta đã cài ở thư viện Mylib. Tham số truyền vào là 1 mã
    màu với tham số truyền vào là i và i là đoạn màu nằm từ 1 đến 15*/
    i++;//Mõi lần i tăng là vật thể đc set 1 màu mới
    if (i > 15)//Vì mã màu của i chỉ có từ 1 đến 15 thôi nếu i vượt quá 15 thì
    {
        i = 1;//Cho i chạy lại mã màu từ 1
    }


    /*Level 3*///Diều khiển
    /*Level 3*/if (_kbhit())/*Hàm kbhit() là hàm dùng để kiểm tra xem người dùng có nhập gì vào không nếu kbhit() là true thì người dùng đã nhập 1 phím nào đó
        nếu người dùng không nhập gì thì hàm sẽ trả về giá trị là false*/
    {
        char kitu = _getch();/*Vì dữ liệu của người dùng nhập là nằm ở bộ nhớ đệm thì hàm _getch này nó sẽ thực hiện load bộ nhớ đệm trước rồi mới 
        nhận kết quả là người dùng nhập phím gì để gán và biến kitu*/
        
        if (kitu =='w')//Nếu là phím W thì người dùng đang muốn cho vật thể đi lên  
        {
            check = 1;/*Ta đã set 1 cái điều kiện cho vật thể đi lên là: else if (check == 1)//Nếu chạm biên dưới
    {
        y--;//Cho vật thể đi lên bằng cách giảm tọa độ Oy xuống 
    }*/
        }
        else if(kitu == 's')//Nếu người dùng nhập s thì người dùng đang muốn điều khiển vật đi xuống 
        {
            check = 0;/*Ta đã set 1 cái điều kiện cho vật thể đi xuống là:  if (check == 0)//Nếu chạm biên trên
    {
        y++;//Cho vật thể đi xuống bằng cách tăng tọa độ Oy lên 
    }*/

        }

    }


    //Kiểm tra hướng
    /*Level 2*/ if (check == 0)//Nếu chạm biên trên
    {
        y++;//Cho vật thể đi xuống bằng cách tăng tọa độ Oy lên 
    }
    else if (check == 1)//Nếu chạm biên dưới
    {
        y--;//Cho vật thể đi lên bằng cách giảm tọa độ Oy xuống 
    }

    //Kiểm tra biên
    /*Level 2*/if (y == 28)/*Ta set 1 cái biên y (y là chiều dọc tọa O là y = 0 và x = 0 y = 0 y tăng thì vật đi xuống còn y giảm về bằng 0 là vật
        về lại tọa độ y gốc ban đầu là nằm biên trên) có bề dọc là từ 0 - 28*/
    {
        check = 1;/*Nếu y đi đến tận biên dưới thì cho y đi lên lại vì ta đã set điều kiện( else if(check == 1)//Nếu chạm biên dưới
        {
            y--;//Cho vật thể đi lên bằng cách giảm tọa độ Oy xuống
        })*/
    }
    else if (y == 0)//Nếu y chạm biên trên
    {
        check = 0;/*Nếu y đi đến tận biên trên thì cho y đi xuống lại vì ta đã set điều kiện if (check == 0)//Nếu chạm biên trên
        {
            y++;//Cho vật thể đi xuống bằng cách tăng tọa độ Oy lên
        }*/
    }


    Sleep(50);/*Chỉnh tốc độ lặp của vòng lặp là 50 thôi. 50 là 50ms <=> 0.05s/lần lặp. Tương ứng với chỉnh tốc độ di chuyển của vật thể luôn
    càng tăng thì tốc độ di chuyển của vật càng chậm và ngược lại càng giảm là tốc độ di chuyển càng nhanh*/
    }
#endif // 0


    /*Level 4: di chuyển vật thể 4 hướng và có biên + phím(Nhấn w là đi lên, nhấn s là đi xuống, nhấn a là qua trái và nhấn d là qua phải) lên xuống
    thì phụ thuộc vào y và thêm trái phải thì phụ thuộc vào x*/
#if 0
    int i = 1;//Biến màu, dùng để xác định giá trị màu
    /*Level 2*/int check = 0;/* #Tư duy khi vật duy chuyển thì phải có tọa độ (x;y) theo trục tọa độ Oxy
                               - 0 là chạm vào biên trên. Khi vật thể chạm vào biên trên thì phải cho vật thể đi xuống bằng cách tăng tọa độ Oy lên
                               - 1 là chạm vào biên dưới. Khi vật thể chạm vào biên dưới thì phải cho vật thể đi lên bằng cách giảm tọa độ Oy xuống
                               - 2 Là chạm vào biên phải. Khi vật chạm vào biên phải thì phải cho vật đi qua trái bằng cách giảm x xuống
                               - 3 Là chạm vào biên trái. Khi vật chạm vào biên trái thì phải cho vật đi qua phải bằng cách tăng x lên*/

    int x = 10, y = 0;//Tọa độ x và y
    /*Level 2*/int xcu = x, ycu = y;//Hai biến xcu và ycu để giữ tọa độ (x,y) cũ sau khi thực hiện xóa dữ liệu cũ bằng Backspace
    while (true)//vòng lặp để di duyển vật thể 
    {
        /*Xóa dữ liệu cũ
    - Cách 1: System("cls"); Làm nháy vật thể tĩnh liên tục rất là xấu
    - Cách 2: Backspace;
     Backspace nó sẽ hoạt động như sau mõi thực thi Backspace sẽ xóa 1 ký tự và đè lên ký tự vừa xóa là 1 khoản trắng và lùi con trỏ về vị trí
     kế ký tự vị xóa gọi là vị trí cũ và in ra dữ liệu vừa mất đi 1 ký tự. để có vị trí cũ ta phải có biến giữ tọa độ cũ là x và y
     ví dụ:  ta nhập hello thì khi Backspace thực hiện nó sẽ
     1-> hellcontrỏchuộtđcdịchtớiđây"đây là khoảng trắng đè lên ký tự bị xóa"
     2-> cuối cùng kết quả là: hell */

     ///*Cách xóa dữ liệu cũ bằng cách 1 dùng system("cls")
     //Level 2*/ system("cls");/*Mõi lần vật thể di chuyển thì phải xóa vị trí của vật thể cũ đi để hiện vị trí mới của vật thể di chuyển đến
     //                         vì mõi lần lặp ta set Ox và Oy tăng hoặc giảm để truyền vào hàm gotoXY(x, y) di chuyển vật thể đến 1 vị trí mà ta 
     //                         đã set Ox và Oy tăng hoặc giảm. system("cls") làm nháy các vật thể tĩnh cách 1 này sẽ làm vật di chuyển rất xấu*/

    /*Xóa dữ liệu cũ bằng cách 2 dùng thuật Backspace
    Level 2*/gotoXY(xcu, ycu);//Cần di chuyển vật đến vị trí cũ trước khi xóa vị trí cũ để xóa trước khi thực hiện đến vị trí mới
    cout << "                      ";/*Tạo 1 khoảng trắng tương ứng với độ dài của vật đề dùng khoảng trăng lấp vị trí cũ của vật vì vật ta tạo có
    độ dài ngang là 22 ký tự nên phải tạo 1 khoảng trắng tương ứng là 22 ký tự là khoảng trắng.*/

    gotoXY(x, y);/*Hàm di chuyển con trỏ đến toa độ x y mà ta đã set tọa độ bất kỳ cho x và y của thư viện Mylib ta đã cài
    bên file Mylib.h*/
    cout << "Hoc lap trinh that de!";/*Vật thể. /Level 2/ vật thể ta tạo Có 22 ký tự tương đương với xóa bằng backspace ta phải tạo ra 1 khoảnh
    trắng có 22 ký tự là khoảng trắng để lắp vị trí cũ của vật đã di chuyển đến trước khi vật di chuyển đến 1 vị trí mới*/
    /*Level 2*/xcu = x;
    ycu = y;/*Sau khi vật di chuyển đến 1 vị trí mới thì ta phải bắt tọa độ vị trí của vật vừa di chuyển đến để khi vòng lặp while thực
    thi nghĩa là vật di chuyể đến vị trí có tọa độ mới nên mõi lần vật di chuyển đến 1 vị trí mới thì ta bắt vị trí mà vật vừa di chuyển
    đến bằng cách cho biến xcu = x và ycu = y để mõi lần di chuyển đến vị trí mới thì phải dùng backspace để xóa vị trí cũ bằng các đè
    khoảng trắng có độ dài tương ứng với độ dài của vật*/

    SetColor(i);/*Hàm để set màu cho vật thể của thư viên Mylib của ta đã cài ở thư viện Mylib. Tham số truyền vào là 1 mã
    màu với tham số truyền vào là i và i là đoạn màu nằm từ 1 đến 15*/
    i++;//Mõi lần i tăng là vật thể đc set 1 màu mới
    if (i > 15)//Vì mã màu của i chỉ có từ 1 đến 15 thôi nếu i vượt quá 15 thì
    {
        i = 1;//Cho i chạy lại mã màu từ 1
    }


    /*Điều khiển có hai cách: 
    - 1 là điều khiển bằng phím đơn: W,S,D,A
    - 2 là điều khiển bằng phím kép(phím kép là phím có 2 mã ASCII: 1 là -32 và mã còn lại là mã của phím): là điều khiển bằng phím mũi tên*/
    /*Level 3*///Diều khiển
    /*Level 3*/if (_kbhit())/*Hàm kbhit() là hàm dùng để kiểm tra xem người dùng có nhập gì vào không nếu kbhit() là true thì người dùng đã nhập 1 phím nào đó
        nếu người dùng không nhập gì thì hàm sẽ trả về giá trị là false*/
    {
        /*Level 3*/char kitu = _getch();/*Vì dữ liệu của người dùng nhập là nằm ở bộ nhớ đệm thì hàm _getch này nó sẽ thực hiện load bộ nhớ đệm trước rồi mới
        nhận kết quả là người dùng nhập phím gì để gán và biến kitu*/

        //Điều khiển bằng phím kép(phím kép là phím có 2 mã ASCII: 1 là -32 và 2 là mã của phím): là điều khiển bằng phím mũi tên
        /*Level 4*/if (kitu == -32)/*Kiểm tra có phải là phím kép(là các phím mũi tên) k tức là kiểm tra xem người dùng nhập vào có phải là phím mũi tên
                                   k*/
        {
            kitu = _getch();//Nếu là phím kép(là các phím mũi tên) thì phải load bộ nhớ đệm để lấy mã ASCII của phím mũi tên mà người dùng đã nhập 
            if (kitu == 72)//Nếu mã ASCII là 72 thì người dùng đã nhập mũi tên đi lên
            {
                check = 1;/*Ta đã set 1 cái điều kiện cho vật thể đi lên là: else if (check == 1)//Nếu chạm biên dưới
                                                                                  {
                                                                                      y--;//Cho vật thể đi lên bằng cách giảm tọa độ Oy xuống
                                                                                   }*/
            }
            else if (kitu == 80)//Nếu mã ASCII là 80 thì người dùng đã nhập mũi tên đi xuống
            {
                check = 0;/*Ta đã set 1 cái điều kiện cho vật thể đi xuống là:    if (check == 0)//Nếu chạm biên trên
                                                                                  {
                                                                                      y++;//Cho vật thể đi xuống bằng cách tăng tọa độ Oy lên
                                                                                   }*/
            }
            else if (kitu == 75)//Nếu mã ASCII là 75 thì người dùng đã nhập mũi tên đi qua trái
            {
                check = 2;/*Nếu x đi đến tận biên phải thì cho x đi qua trái lại vì ta đã set điều kiện else if (check == 2)//Nếu chạm biên phải
                                                                                          {
                                                                                           x--;//Cho vật thể đi qua trái bằng cách giảm tọa độ Ox xuống
                                                                                           }*/

            }
            else if (kitu == 77)//Nếu mã ASCII là 75 thì người dùng đã nhập mũi tên đi qua phải
            {
                check = 3;/*Nếu x đi đến tận biên trái thì cho x đi qua phải lại vì ta đã set điều kiện else if (check == 3)//Nếu chạm biên trái
                                                                                          {
                                                                                           x++;//Cho vật thể đi qua phải bằng cách tăng tọa độ Ox lên
                                                                                           }*/

            }
        }

        //điều khiển bằng ký tự đơn(là các phím W,S,D,A)
#if 0
  /*Level 3*/if (kitu == 'w')//Nếu là phím W thì người dùng đang muốn cho vật thể đi lên  
        {
            check = 1;/*Ta đã set 1 cái điều kiện cho vật thể đi lên là: else if (check == 1)//Nếu chạm biên dưới
    {
        y--;//Cho vật thể đi lên bằng cách giảm tọa độ Oy xuống
    }*/
        }
        /*Level 3*/else if (kitu == 's')//Nếu người dùng nhập s thì người dùng đang muốn điều khiển vật đi xuống 
        {
            check = 0;/*Ta đã set 1 cái điều kiện cho vật thể đi xuống là:  if (check == 0)//Nếu chạm biên trên
    {
        y++;//Cho vật thể đi xuống bằng cách tăng tọa độ Oy lên
    }*/
        }
#endif // 0
    }

    //Kiểm tra hướng
    /*Level 2*/ if (check == 0)//Nếu chạm biên trên
    {
        y++;//Cho vật thể đi xuống bằng cách tăng tọa độ Oy lên 
    }
    /*Level 2*/else if (check == 1)//Nếu chạm biên dưới
    {
        y--;//Cho vật thể đi lên bằng cách giảm tọa độ Oy xuống 
    }
    /*Level 4*/else if (check == 2)//Nếu chạm biên phải
    {
        x--;//Cho vật thể đi qua trái bằng cách giảm tọa độ Ox xuống 
    }
    /*Level 4*/else if (check == 3)//Nếu chạm biên trái
    {
        x++;//Cho vật thể đi qua phải bằng cách tăng tọa độ Ox lên 
    }

    //Kiểm tra biên
    /*Level 2*/if (y == 28)/*Ta set 1 cái biên y (y là chiều dọc tọa O là y = 0 và x = 0 y = 0 y tăng thì vật đi xuống còn y giảm về bằng 0 là vật
        về lại tọa độ y gốc ban đầu là nằm biên trên) có biên bề dọc là từ 0 - 28*/
    {
        check = 1;/*Nếu y đi đến tận biên dưới thì cho y đi lên lại vì ta đã set điều kiện( else if(check == 1)//Nếu chạm biên dưới
        {
            y--;//Cho vật thể đi lên bằng cách giảm tọa độ Oy xuống
        })*/
    }
    /*Level 2*/else if (y == 0)//Nếu y chạm biên trên
    {
        check = 0;/*Nếu y đi đến tận biên trên thì cho y đi xuống lại vì ta đã set điều kiện if (check == 0)//Nếu chạm biên trên
        {
            y++;//Cho vật thể đi xuống bằng cách tăng tọa độ Oy lên
        }*/
    }
    /*Level 4*/else if (x == 0)//Nếu x chạm biên trái
    {
        check = 3;/*Nếu x đi đến tận biên trái thì cho x đi qua phải lại vì ta đã set điều kiện else if (check == 3)//Nếu chạm biên trái
    {
        x++;//Cho vật thể đi qua phải bằng cách tăng tọa độ Ox lên 
    }*/
    }
    /*Level 4*/ else if (x == 100)/*Ta set 1 cái biên x (x là chiều ngang tọa O là y = 0 và x = 0 y = 0, x tăng thì vật đi qua phải còn x giảm về bằng 0 là vật
        về lại tọa độ x gốc ban đầu là nằm biên trái) có biên bề ngang là từ 0 - 100*/
    {
        check = 2;/*Nếu x đi đến tận biên phải thì cho x đi qua trái lại vì ta đã set điều kiện else if (check == 2)//Nếu chạm biên phải
    {
        x--;//Cho vật thể đi qua trái bằng cách giảm tọa độ Ox xuống
    }*/
    }

    Sleep(50);/*Chỉnh tốc độ lặp của vòng lặp là 50 thôi. 50 là 50ms <=> 0.05s/lần lặp. Tương ứng với chỉnh tốc độ di chuyển của vật thể luôn
    càng tăng thì tốc độ di chuyển của vật càng chậm và ngược lại càng giảm là tốc độ di chuyển càng nhanh*/
    }
#endif
    system("Pause");
}
#endif


//======================== Project chính của Game A Huting Snacke cơ bản ====================
//Vẽ tường tạo hình rắn và xử lí rắn di chuyển
    
/*Vẽ tường: 
 - Vẽ tường: Vì màn hình console với tọa độ góc là (0,0) tức x = 0 và y = 0 là nằm ở góc vuông trái trên nên từ tọa độ góc của màn hình console ta
   phải tạo 1 cái tường cách màn hình console ra như sau(Khoảng cách tạo tường cách so với màn hình console tùy ý ta): 
    + chiều dọc: 
      > trên y = 1, x = 10 x++ x =100 
      > dưới y = 26, x = 10 x++ x = 100 .
    + chiều ngang: 
      > trái x = 10, y = 1 y++ y =26.
      > phải x = 100, y = 1 y++ y =26
      => Tức là từ biên trên của màn hình console mà tới biên trên của tường ta là cách khoảng 1 ký tự và
              từ biên trái của màn hình console mà tới biên trái của tường ta là cách khoảng 10 ký tự và
              khoảng cách từ biên trái tới biên phải của tường ta là 10 đến 100 ký tự và
              khoảng cách từ biên trên tới biên dưới của tường ta là 1 đến 26 ký tự
    */

int soLuongKhucCuaSnake = 4;//Đây là biến lưu chiều dài của rắn dài bao nhiêu là rắn bao nhiêu khúc
void Ve_Tuong_Tren();
void Ve_Tuong_Duoi();
void Ve_Tuong_Trai();
void Ve_Tuong_Phai();
void Ve_Tuong();//Vẽ tường là hàm để gọi các hàm vẽ tường trên dưới trái phải vào hàm vẽ tường này để khi trong hàm main chỉ gọi 1 hàm vẽ tường cho gọn 

void Ve_Tuong_Tren() {
    int x = 10, y = 1;
    while (x <= 100)
    {
gotoXY(x, y);
    cout << "+";
      x++;
    }   
}
void Ve_Tuong_Duoi() {
    int x = 10, y = 26;
    while (x <= 100)
    {
        gotoXY(x, y);
        cout << "+";
        x++;
    }
}
void Ve_Tuong_Trai() {
    int x = 10, y = 1;
    while (y <= 26)
    {
        gotoXY(x, y);
        cout << "+";
        y++;
    }
}
void Ve_Tuong_Phai() {
    int x = 100, y = 1;
    while (y <= 26)
    {
        gotoXY(x, y);
        cout << "+";
        y++;
    }
}

void Ve_Tuong() {
    SetColor(11);

    Ve_Tuong_Tren();
    Ve_Tuong_Phai();
    Ve_Tuong_Duoi();
    Ve_Tuong_Trai();

    SetColor(7);
}

/*Tạo hình rắn:
- Đối với hình rắn thì 1 con răn sẽ gồm nhiều khúc nối lại thành 1 con rắn thì mõi khúc con rắn đều có tọa độ nơi mà khúc đó của con rắn hiển thị 
trên màn hình console Vì 1 con rắn đc hình thành bởi gồm nhiều khúc nối liền nhau và từng khúc của rắn từ cái đầu rắn có tọa độ là (x0;y0) cho đến 
dần đến đuôi có tọa độ là (xN + 1;yN + 1) mõi tọa độ x và y của từng khúc rắn được lưu vào hai mảng toadoX lưu tọa độ x và toadoY lưu tọa độ y của 
các khúc rắn và gộp x và y của 2 mảng có vị trí phần tử tương ứng lại và các phần tử này nằm liền nhau sẽ tạo thành 1 con rắn

+ ví dụ 1 con rắn có 3 khúc như sau: .o0
> khúc đầu con rắn là 0 có tọa độ của 0(x0,y0) thì x0 là phần tử đầu tiên của mảng toadoX và y0 là phần tử đầu tiên của mảng toadoY tức phần tử ở 
vị trí 0 của mảng toadoX gộp với phần tử ở vị trí 0 của mảng toadoY lại sẽ đc 1 khúc là đầu rắn  
> Khúc giữa con rắn là o có tọa độ của o(x1,y1) thì x1 là phần tử thứ 2 của mảng toadoX và y1 là phần tử thứ 2 của mảng toadoY tức phần tử ở 
vị trí 1 của mảng toadoX gộp với phần tử ở vị trí 1 của mảng toadoY lại sẽ đc 1 khúc là thân rắn 
> Khúc đuôi của con rắn là . có tọa độ của .(x2,y2) thì x2 là phần tử thứ 3 của mảng toadoX và y2 là phần tử thứ 3 của mảng toadoY tức phần tử ở 
vị trí 2 của mảng toadoX gộp với phần tử ở vị trí 2 của mảng toadoY lại sẽ đc 1 khúc là đuôi rắn

+ thì ta cần phải dùng hai mãng để 1 mãng là lưu tọa độ x của rắn và 1 mãng là lưu tọa độ y của rắn. Rắn có độ dài bao nhiêu thì ta chỉ cần duyệt các
phần tử tương đương với độ dài của rắn đã lưu ở hai mảng này thôi:
> 1 là mảng toadoX[] để lưu tọa độ x của rắn với những phần tử(rắn có độ dài bao nhiêu phần tử thì mảng sẽ lưu giá trị và chỉ số tương ứng với độ dài
của rắn) vì rắn ta 3 khúc tương đương với độ dài rắn là 3 nên trong mảng toadoX chỉ số x sẽ có 3 giá trị như sau: 
chỉ số:    0   1    2 
giá trị:  x0  x1   x2
> 2 là mảng toadoY[] để lưu tọa độ y của rắn với những phần tử(rắn có độ dài bao nhiêu phần tử thì mảng sẽ lưu giá trị và chỉ số tương ứng với độ dài
của rắn) vì rắn ta 3 khúc tương đương với độ dài rắn là 3 nên trong mảng toadoY chỉ số y sẽ có 3 như sau:
chỉ số:    0   1    2
giá trị:  y0  y1   y2*/

void Ve_Ran(int toaDoX[], int toaDoY[]);
void Khoi_Tao_Ran(int toaDoX[], int toaDoY[]);
void Xu_Ly_Ran(int toaDoX[], int toaDoY[], int x, int y);
void Xoa_Du_Lieu_Cu(int toaDoX[], int toaDoY[]);
void Them_Toa_Do_Moi_Vao_Dau_Mang(int a[], int x);
void Xoa_Duoi_Ran_Khi_Da_Them_Toa_Do_Moi_Vao_Dau(int a[], int vt);
bool Check_Snake_Cham_Tuong(int x0, int y0);
bool Snake_Cham_Duoi(int toadoX[], int toadoY[]);
bool kt_ran_de_qua(int xqua, int yqua, int toadox[], int toadoy[]);
void tao_qua(int& xqua, int& yqua, int toadox[], int toadoy[]);
bool kt_ran_an_qua(int xqua, int yqua, int x0, int y0);

//Hàm vẽ rắn
void Ve_Ran(int toaDoX[], int toaDoY[]) {
    //Vòng lặp duyệt để vẽ số khúc của rắn tương đương với độ dài của rắn mà ta đã set cho biến lưu số khúc của rắn soLuongKhucCuaSnake
    for (short i = 0; i < soLuongKhucCuaSnake; i++){
        if(i == 0) {//Vì đầu mảng là chứa cái đầu của rắn mà đầu rắn là phần to hơn thân và đuôi nên nếu là đầu rắn thì ra vẽ cái đầu rắn là 0
           gotoXY(toaDoX[i], toaDoY[i]);
           cout << "0";
        }
        else//Nếu không phải đầu rắn thì ta vẽ phần thân rắn nhỏ hơn đầu rắn là o
        {
            gotoXY(toaDoX[i], toaDoY[i]);
            cout << "o";
        }
    }
}
/*Hàm khởi tạo rắn:
là set 1 tọa độ (x;y) để cho các khúc của rắn xuất hiện trên màn hình console nơi xuất hiện sẽ là nơi mà ta set tọa độ cho từng khúc
của rắn cái này ta có thể tùy ý set tọa độ(x; y) để để các khúc của rắn xuất hiện bất kỳ trên màn hình lưu ý là muốn hình thành 1 con rắn mà rắn thì
thường dài chiều ngang mà ngang là trục Ox thì các khúc này phải có chỉ số 0x liền kề nhau thì mới tạo thành 1 con rắn */
void Khoi_Tao_Ran(int toaDoX[], int toaDoY[]) {

    int x = 50, y = 13;//là set 1 tọa độ (x;y) để cho các khúc hình thành 1 con rắn xuất hiện trên màn hình console
    for (short i = 0; i < soLuongKhucCuaSnake; i++)
    {
        /*- Mõi lần lặp thì hai mảng toaDoX và toaDoY sẽ lưu 1 tọa độ để hình thành 1 phần của rắn và vì rắn là dài theo chiều dài ngang và phải liền
        nhau nên giá trị y của rắn là chiều cao k đổi chỉ có chiều dài ngang là giảm dần liền nhau tương đương với số khúc của rắn
        + ví dụ: ta set cho soLuongKhucCuaSnake là 4 tương đương chiều dài của rắn là 4 khúc
        >lần lặp đầu tiên ta set cho cái đầu con rắn sẽ xuất hiện ở tọa độ (x;y) là (50,13)  
        >lần lặp thứ 2 ta set cho cái thân kế đầu rắn sẽ xuất hiện ở tọa độ (x;y) là (49,13)
        >lần lặp thứ 3 ta set cho cái thân kế cái đuôi rắn sẽ xuất hiện ở tọa độ (x;y) là (48,13)
        >lần lặp thứ 4 ta set cho cái cái đuôi rắn sẽ xuất hiện ở tọa độ (x;y) là (47,13)*/
        toaDoX[i] = x;
        toaDoY[i] = y;
        x--;
    }
}

/*Di chuyển rắn: 
- Bước 1: Thêm tọa độ mới vào đầu mảng
- Bước 2: Xóa tọa độ cuối mảng 
- Bước 3: Vẽ rắn để vẽ tọa độ mới cho rắn khi ta di chuyển rắn đến tọa độ mới theo ý ta
* thì tư duy di chuyển rắn như sau: 
-> Bước 1: Thêm tọa độ mới vào đầu mảng. Tức khi ta di chuyển rắn đến 1 vị trí mới thì đầu tiên là đầu răn di chuyển trước mà đầu rắn có tọa độ là
(x0,y0) thì lúc đầu rắn di chuyển đến 1 vị trí mới thì đầu rắn sẽ đc tạo bởi 1 tọa độ mới là (x,y), sau đó 
-> Bước 2: Xóa tọa độ cuối mảng. Thì khi đầu rắn di chuyển đến vị trí với thì vị trí này là ta thêm vào đầu mảng tức đầu rắn lúc này có tọa độ mới vừa
thêm vào là (x;y) lúc này ta dồn cái thân kế cái đầu rắn tức là cái thân kế đầu rắn có tọa độ là (x1;y1) lên tọa độ của đầu rắn thì cái thân kế
đầu rắn dồn lên nên cái thân kế đầu rắn lúc này nằm ở vị trí tọa độ cũ của đầu rắn trước khi đầu rắn di chuyển đến vị trí mới là cái thân kế đầu
rắn lúc này sau khi dồn lên sẽ có tọa độ là (x0;y0) và tương tự cái kế cái vừa đc dồn lên tọa độ của đầu cũ có tọa độ ban đầu là (x2,y2) thì lúc này 
cái kế cái vừa đc dồn lên chổ tọa độ của cái đầu cũ sẽ có tọa độ là từ (x2;y2) thành (x1,y1)..... Cứ như vậy dồn lên do tới khi dư cái tọa độ phần tử là đuôi rắn ra thì ta xóa cái tọa độ phần tử
đuôi rắn dư cuối mảng đi
+ vd: 
> con rắn ta có độ dài là 4 khúc ban đầu chưa di chuyển nó nằm với tọa độ của từ khúc như sau: 
         
         (x3;y3)(x2,y2)(x1,y1)(x0,y0)
                               ooo0 (đây là con rắn của ta đã vẽ)

> sau khi di chuyển bất kì vd là di chuyển xuống dưới thì nó sẽ nằm với tọa độ như sau:
            
             (x2,y2)(x1,y1)(x0,y0)
                               ooo
                                  0(x,y)

-> Bước 3 Sẽ Vẽ rắn để vẽ tọa độ mới cho rắn khi ta di chuyển rắn đến tọa độ mới theo ý ta*/
void Xu_Ly_Ran(int toaDoX[], int toaDoY[], int x, int y, int& xqua, int& yqua) {/*biến x và y là hai biến khi mõi lần di chuyển rắn tới vị trí bất kì thì tọa độ x và y
    sẽ thêm vào đầu mảng tức x và y là dùng để tạo 1 cái đầu rắn mới ở vị trí mới mà ta muốn di chuyển rắn*/

    //Bước 1: thêm tọa độ mới vào đầu mảng
    Them_Toa_Do_Moi_Vao_Dau_Mang(toaDoX, x);
    Them_Toa_Do_Moi_Vao_Dau_Mang(toaDoY, y);
    if (kt_ran_an_qua(toaDoX[0], toaDoY[0], xqua, yqua) == false)/*Ta đã tạo ra 1 hàm kt_ran_an_qua để kiểm tra xem rắn có ăn quả hay không nếu hàm
        kt_ran_an_qua trả về true là rắn đã ăn quả mà khi rắn ăn quả thì dk (kt_ran_an_qua(toaDoX[0], toaDoY[0], xqua, yqua) == false) sai khi đk này
        sai thì rắn sẽ đc thêm phần tử  còn false là rắn k ăn quả. Mà rắn k ăn quả thì con rắn đó vẫn di chuyển với kích thước bình thường
        mà rắn di chuyển có 3 bước bước thứ 3 là bước xóa nên khi rắn k ăn quả ta vẫn giữ kích thước của rắn bình thường bằng cách thưc hiện xóa cái 
        đuôi rắn dư sau khi dồn các khúc từ đuôi tới khúc đầu cũ của rắn trước khi di chuyển rắn tới vị trí mới đi sau khi đầu rắn ở vị trí mới*/
    {
 //Bước 2: Xóa tọa độ cuối mảng
    Xoa_Duoi_Ran_Khi_Da_Them_Toa_Do_Moi_Vao_Dau(toaDoX,soLuongKhucCuaSnake - 1);
    Xoa_Duoi_Ran_Khi_Da_Them_Toa_Do_Moi_Vao_Dau(toaDoY, soLuongKhucCuaSnake - 1);
    }
    else
    {
 //Tạo quả sau khi rắn ăn quả r thì ta phải tạo 1 quả mới
    tao_qua(xqua, yqua, toaDoX, toaDoY);
    }

   

    //Bước 3: Vẽ rắn
    Ve_Ran(toaDoX, toaDoY);

   

}

void Xoa_Du_Lieu_Cu(int toadoX[], int toadoY[]) {

    /*Vòng lặp duyệt từ đầu mảng tới cuối mảng tức duyệt từ đầu con rắn tới đuôi rắn, Và hàm gotoXY là hàm đi tới 1 vị trí x và y bất kỳ mà ta truyền
    và cho hàm gotoXY này mà lúc này con rắn của ta hình thành bởi nhiều khúc mõi khúc là 1 tọa độ x và y mà mõi tọa độ x và y này đc lưu ở hai mảng
    toadoX và toadoY mà mõi phần tử x ở mảng toadoX sẽ gộp với phần tử y ở mảng toadoY có vị trí tương ứng và liền kề nhau vì con rắn đc hình thành
    bởi nhiều khúc liền nhau nên khi vòng lặp này duyệt đến khúc nào của rắn thì khúc đó sẽ đc xóa bằng thuật backspace(đã tìm hiểu và thực hành ở 
    4 bước cơ bản của game rắn săn mồi dòng 6) tức là duyệt tới khúc nào của rắn bằng hàm gotoXY(toadoX[i],toadoY[i]) thì sẽ xóa khúc đó của rắn bằng
    cách lấy khoảng trắng lấp khúc vừa đc duyệt luôn*/
    for (short i = 0; i < soLuongKhucCuaSnake; i++)
    {
        gotoXY(toadoX[i],toadoY[i]);
        cout << " ";
    }
}

/*Hàm thêm phần tử vào đầu mảng tức là tạo 1 cái đầu rắn mới ở vị tró mới mà ta muốn di chuyển rắn và thực hiện dồn các phần tử cuối mảng tức là các
khúc từ đuôi tới thân kế đầu của rắn lên đầu mảng tức là lên đầu rắn sau đó thực hiện xóa phần tử cuối mảng là phần tử đuôi rắn bị dư sau khi dồn các
khúc của rắn lên khi rắn di chuyển đến 1 vị trí mới bất kì*/
void Them_Toa_Do_Moi_Vao_Dau_Mang(int a[], int x) {

    /*Vòng lặp duyệt từ cuối mảng đến đầu mảng tức dồn các phần tử từ cuối mảng lên đầu mảng tức là dồn các từ khúc đuôi đến khúc kế đầu lên đầu mảng
    sau khi thêm phần tử đầu mảng thì phần tử sau khi thêm ở đầu mảng là phần tử mới tương đương với đầu rắn mới tọa tọa độ vị trí mới mà ta điều khiển
    rắn tới vị trí mới này*/
    for (short i = soLuongKhucCuaSnake; i > 0 ; i--)
    {
        a[i] = a[i - 1];/*biến soLuongKhucCuaRan là lưu độ dài của rắn tương đương với từng khúc của con rắn thì mõi lần vòng lặp duyệt từ cuối mảng 
        lên đầu mảng cứ mõi lần lặp thì phần tử thứ i sẽ bằng phần tử thứ i - 1 tức dồn từ phần tử cuối mảng lên cho đến phần tử đầu mảng 
        + vd: rắn ta có 4 khúc vì ta khai báo biến soLuongKhucCuaRan = 4 khi vào vòng lặp thực hiện dồn từ tử cuối mảng lần lượt cho đến phần tử đầu 
        mảng như sau: 
        -> lặp đầu tiên i = soLuongKhucCuaRan mà soLuongKhucCuaRan = 4 => i = 4
           nên a[i] là a[4] = a[i -1] tức a[4] = a[ 4 -1] <=> a[4] = a[3] nghĩa là phần tử cuối mảng lúc này đã là phần tử kế cuối
        -> lặp thứ 2 sau lần lặp đầu thì i-- là i - đi 1 tức 4 - 1 thì i = 3 
           nên a[i] là a[3] = a[i - 1] tức a[3] = a[ 3 - 1] <=> a[3] = a[2] nghĩa là phần tử kế cuối mảng lúc này đã là phần tử kế của phần tử kế cuối
        -> lặp thứ 3 sau lần lặp thứ 2 thì i-- là i - đi 1 tức 3 - 1 thì i = 2
           nên a[i] là a[2] = a[i - 1] tức a[3] = a[ 2 - 1] <=> a[2] = a[1] nghĩa là phần tử kế của phần tử kế cuối mảng lúc này đã là phần tử kế của
           phần tử kế phần tử kế cuối mảng
        -> lặp thứ 4 sau lần lặp thứ 3 thì i-- là i - đi 1 tức 2 - 1 thì i = 1
           nên a[i] là a[1] = a[i - 1] tức a[1] = a[ 1 - 1] <=> a[1] = a[0] nghĩa là phần tử kế của phần tử kế đầu mảng lúc này đã là phần đầu mảng
        -> Lặp thứ 5 sau lần lặp thứ 4 thì i-- là i - đi 1 thì i = 0
        nên không thõa đk i > 0 vòng lặp dừng lại
        => kết quả của vòng lặp mảng ta lúc này: a[3],a[2],a[1],a[0]
        */
    }
    a[0] = x;//Cập nhật lại vị trí mà ta mới thêm là vị trí đầu mảng tức vị trí mà ta vừa thêm đc cập nhật lại là đầu của rắn
    soLuongKhucCuaSnake++;
}

/*Khi đầu rắn di chuyển đến vị trí có tọa độ mới thì ta sẽ thêm cái đầu rắn gọi là thêm phần tử vào đầu mảng chứa rắn xong và dồn hết các phần tử từ
đuôi rắn cho tới thân kế đầu rắn xong thì phần đuôi rắn sẽ bị dư ra vì ta đã thêm 1 cái đầu rắn mới ở hàm Them_Toa_Do_Moi_Vao_Dau_Mang nên ta cần phải
xóa cái phần tử ở cuối mảng chứa rắn là cái đuôi dư này*/
void Xoa_Duoi_Ran_Khi_Da_Them_Toa_Do_Moi_Vao_Dau(int a[], int vt) {

    /*Vòng lặp để duyệt từ vt mà vt này ta cho nó bằng soLuongKhucCuaSnake - 1 tức là duyệt từ cuối mảng */
    for (short i = vt; i  <  soLuongKhucCuaSnake; i++)
    {
        a[i] = a[i + 1];
    }
    soLuongKhucCuaSnake--;
}

//GAME OVER
/*Rắn chạm tường Game Over:
#Ta đã set 1 bức tường cho trò chơi ở hàm vẽ tường từ dòng code 407 - 464 như sau: 
( Vẽ tường: Vì màn hình console với tọa độ góc là (0,0) tức x = 0 và y = 0 là nằm ở góc vuông trái trên nên từ tọa độ góc của màn hình console ta
phải tạo 1 cái tường cách màn hình console ra như sau(Khoảng cách tạo tường cách so với màn hình console tùy ý ta):
    + chiều dọc:
    > trên y = 1, x = 10 x++ x =100
    > dưới y = 26, x = 10 x++ x = 100 .
    + chiều ngang:
    > trái x = 10, y = 1 y++ y =26.
    > phải x = 100, y = 1 y++ y =26
    => Tức là từ biên trên của màn hình console mà tới biên trên của tường ta là cách khoảng 1 ký tự và
              từ biên trái của màn hình console mà tới biên trái của tường ta là cách khoảng 10 ký tự và
              khoảng cách từ biên trái tới biên phải của tường ta là 10 đến 100 ký tự và
              khoảng cách từ biên trên tới biên dưới của tường ta là 1 đến 26 ký tự )

 - khi chạm tường trên: 
 thì tường trên của ta có tọa độ Oy mà ta đã set luôn luôn bằng 1 còn tọa độ Ox của tường trên ta cũng đã set luôn >= 10 và <= 100 Nên ở tường trên ta 
 chỉ cần set cho con rắn cái đầu rắn(mà cái đầu rắn có tọa độ (x0 ; y0)) là x0 >=10 và <= 100 và y0 có = 1 không nếu đầu rắn tức tọa độ của đầu rắn 
 (x0 ; y0) thỏa điều kiện  x0 >=10 và <= 100 và y0 có = 1 thì con rắn chạm tường trên và nghĩa là game over
 - khi chạm tường dưới: 
 thì tường dưới của ta có tọa độ Oy mà ta đã set luôn luôn bằng 26 còn tọa độ Ox của tường dưới ta cũng đã set luôn >= 10 và <= 100 Nên ở tường dưới ta
 chỉ cần set cho con rắn cái đầu rắn(mà cái đầu rắn có tọa độ (x0 ; y0) ) là x0 >=10 và <= 100 và y0 có = 26 không nếu đầu rắn tức tọa độ của đầu rắn 
 (x0 ; y0) thỏa điều kiện  x0 >=10 và <= 100 và y0 có = 26 thì con rắn chạm tường trên và nghĩa là game over
 - khi chạm tường trái:
 thì tường trái của ta có tọa độ Ox mà ta đã set luôn luôn bằng 10 còn tọa độ Oy của tường trái ta cũng đã set luôn >= 1 và <= 26 Nên ở tường trái ta 
 chỉ cần set cho con rắn cái đầu rắn(mà cái đầu rắn có tọa độ (x0 ; y0) ) là y0 >=1 và <= 26 và x0 có = 10 không nếu đầu rắn tức tọa độ của đầu rắn
 (x0 ; y0) thỏa điều kiện (x0 ; y0) ) là y0 >= 1 và <= 26 và x0 có = 10 thì con rắn chạm tường trái và nghĩa là game over
 - khi chạm tường phải:
 thì tường phải của ta có tọa độ Ox mà ta đã set luôn luôn bằng 100 còn tọa độ Oy của tường phải ta cũng đã set luôn >= 1 và <= 26 Nên ở tường phải ta
 chỉ cần set cho con rắn cái đầu rắn(mà cái đầu rắn có tọa độ (x0 ; y0) ) là y0 >= 1 và <= 26 và x0 có = 100 không nếu đầu rắn tức tọa độ của đầu rắn
 (x0 ; y0) thỏa điều kiện (x0 ; y0) ) là y0 >= 1 và <= 26 và x0 có = 10 thì con rắn chạm tường phải và nghĩa là game over
 */
bool Check_Snake_Cham_Tuong(int x0, int y0) {//Truyền tọa độ đầu rắn vào hàm để kiểm tra xem đầu rắn nó có chạm vào tường hay không

    //ran cham tuong tren
    if (y0 == 1 && (x0 >= 10 && x0 <= 100))
    {
        return true;//gameover
    }
    //ran cham tuong duoi
    else if (y0 == 26 && (x0 >= 10 && x0 <= 100))
    {
        return true;//gameover
    }
    //ran cham tuong phai
    else if (x0 == 100 && (y0 >= 1 && y0 <= 26))
    {
        return true;//gameover
    }
    //ran cham tuong trai
    else if (x0 == 10 && (y0 >= 1 && y0 <= 26))
    {
        return true;//gameover
    }
    
    
 return false;
    
   
    
}

/*Rắn chạm đuôi GameOver:
- Vì 1 con rắn đc hình thành bởi gồm nhiều khúc nối liền nhau và từng khúc của rắn từ cái đầu rắn có tọa độ là (x0;y0) cho đến dần đến đuôi có tọa độ
là (xN + 1;yN + 1) mõi tọa độ x và y của từng khúc rắn được lưu vào hai mảng toadoX lưu tọa độ x và toadoY lưu tọa độ y của các khúc rắn và gộp x và y
của 2 mảng có vị trí phần tử tương ứng lại và các phần tử này nằm liền nhau sẽ tạo thành 1 con rắn. Khi tọa độ đầu rắn mà trùng với tọa độ khúc nào của
rắn thì rắn đã cắn đuôi dẫn đến GameOver
+VD: đầu rắn với tọa độ (x0;y0) là (50,13) còn thân rắn vs tọa độ (x1,y1) là (49;13) và đuôi rắn có tọa độ là (x2,y2) là (48,13) là theo thứ tự tọa độ
đầu thân đuôi con rắn sẽ như thế này:  .o0
thì khi đầu có đang ở vị trí có tọa độ là (50,13) mà ta lại điều kiển rắn đến vị trí (48;13) hoặc (49;13) tức đầu rắn có tọa độ (50,13) sau khi di chuyển
đến vị trí (49;13) thì tọa độ đầu rắn trùng với tọa độ của thân rắn => rắn đã cắn thân dẫn đến GameOver Hoặc khi đầu có đang ở vị trí có tọa độ là (50,13)
mà ta lại điều kiển rắn đến vị trí (48;13) tức đầu rắn có tọa độ (50,13) sau khi di chuyển đến vị trí (48;13) thì tọa độ đầu rắn trùng với tọa độ của 
đuôi rắn => rắn đã cắn đuôi dẫn đến GameOver */
bool Snake_Cham_Duoi(int toadoX[], int toadoY[]) {

    //Dùng vòng lặp duyệt từ khúc thân kế đầu của rắn cho tới đuôi rắn 
    for (short i = 1; i < soLuongKhucCuaSnake; i++)
    {
        if ((toadoX[0] == toadoX[i]) && (toadoY[0] == toadoY[i])) {/*Nếu tọa độ (x0,y0) của đầu rắn mà trùng tọa độ của khúc nào trong khoảng từ khúc thân kế
            đầu của rắn cho tới đuôi rắn thì rắn đã tự cắn nó*/
            return true;//GammeOver    
    }
    }
    return false;

}

/*Hàm Kiểm tra rắn: 
để khi 1 trong 2 trường hợp là rắn chạm đuôi và rắn chạm tường thì GameOver chứ nếu ta cho biến chạy game là GameOver mà bằng hàm rắn chạm đuôi và bằng
hàm rắn chạm tường gọi trong hàm main thì như vậy hàm nào mà bị true trước mà hàm dưới đang false thì game sẽ on chứ không over nên hàm này sẽ giải quyết
vấn đề chỉ cần rắn mà bị 1 trong 2 trường hợp của GameOver thì chương trình sẽ dừng lại*/
bool Check_GameOver(int toadoX[], int toadoY[]) {
    if (Check_Snake_Cham_Tuong(toadoX[0],toadoY[0]) == true || Snake_Cham_Duoi(toadoX,toadoY) == true)
    {
        return true;
    }
    return false;
}

/*Hàm Kiểm tra rắn đè quả: 
- Khi quả xuất hiện có tọa độ trùng với tọa độ của một trong các khúc của rắn xuất hiện thì khi đó rắn sẽ đè lên quả làm mất quả*/
bool kt_ran_de_qua(int xqua, int yqua, int toadox[], int toadoy[])
{
    //Dùng vòng lặp duyệt từng khúc của rắn từ đầu rắn cho tới đuôi rắn xem có khúc nào của rắn đè lên quả hay không
    for (int i = 0; i < soLuongKhucCuaSnake; i++)
    {
        if ((xqua == toadox[i]) && (yqua == toadoy[i]))//Nếu Khi quả xuất hiện có tọa độ trùng với tọa độ của một trong các khúc của rắn xuất hiện
        {
            return true;//Thì trả về hàm là true <=> Rắn đè lên quả
        }
    }
    //Ngược lại Khi quả xuất hiện có tọa độ khác với tọa độ của một trong các khúc của rắn xuất hiện
    return false;//Thì trả về hàm là false <=> Rắn k đè lên quả
}

/*Tạo quả: 
- Để quả xuất hiện ngẫu nhiên trong tường mà tường ta set với tọa độ là 0x là từ 10 đến 100 và oy là từ 1 đến 26 sau khi rắn ăn xong thì ta cần dùng 
 2 hàm: 
+ 1 là hàm: scrand(time(NULL));
+ 2 là hàm: rand() với công thức rand()%(b - a + 1) + a; //Đây là công thức random 1 số trong khoảng từ a đến b mà tường ta set với tọa độ là 0x là từ
10 đến 100 và oy là từ 1 đến 26 nên:  
quả sẽ xuất hiện các vị trí ngẫu nhiên trong tường với tọa độ của qua trong khoảng:
                                                               11 <= xQua <= 99 nên công thức sẽ là xQua = rand()%(99 - 11 + 1) + 11
                                                                2 <= yQua <= 25 nên công thức sẽ là yQua = rand()%(25 - 2 + 1) + 2  */
void tao_qua(int& xqua, int& yqua, int toadox[], int toadoy[])
{
    //Dùng vòng lặp do while để tạo quả trước sau đó 
    do
    {
        /*Vì tường ta set với tọa độ là 0x là từ 10 đến 100 nên quả chỉ đc xuất hiện bên trong theo chiều ngang của tường là: <= xqua <= 99*/
        xqua = rand() % (99 - 11 + 1) + 11;
        /*Vì tường ta set với tọa độ Oy là từ 1 đến 26 nên quả chỉ đc xuất hiện bên trong theo chiều dọc của tường là: 2 <= yqua <= 25*/
        yqua = rand() % (25 - 2 + 1) + 2;
    } while (kt_ran_de_qua(xqua, yqua, toadox, toadoy) == true);/*mới dùng hàm kt_ran_de_qua để kiểm tra tọa độ của quả xuất hiện có trùng với tọa độ
    của 1 trong các khúc của rắn xuất hiện không vì ta đã tạo 1 hàm kt_ran_de_qua ở dòng 777 trả về true là tọa độ của quả xuất hiện trùng với tọa độ
    của 1 trong các khúc của rắn xuất hiện nếu quả ta tạo có tọa độ trùng với tọa độ của 1 trong các khúc của rắn thì tạo 1 quả mới bằng cách quay lên
    lại do và thực hiện khối lệnh trong do vì vòng lặp do while là thực hiện lệnh trong do trước rồi mới vào đk while nếu ddk while đúng thì quay lên
    thực hiện lệnh trong do còn đk while sai vòng lặp dừng lại     */
    
    
    int i = rand() % (15 - 1 + 1) + 1;/*Random màu của quả trong khoảng màu từ [a,b] mà màu chỉ có từ 1 - 15 nên sẽ random từ [1,15] bằng công thức 
    random rand()%(b-a+ 1) + a <=>  rand() % (15 - 1 + 1) + 1*/
    SetColor(i);//Hàm SetColor làm hàm trong thư viện mylib mà thư viện mylib ta đã tạo ở file mylib.h
    gotoXY(xqua, yqua);//Dùng hàm gotoXY để hiển thị quả trong tọa độ x y đã random trong tọa độ bất kì trong tường
    cout << "$";//đây là quả
    SetColor(7);//Ban đầu ta cho quả xuất hiện là màu trắng
}

/*Xử lý rắn ăn quả: 
-Bằng cách nếu tọa độ của đầu rắn là (x0,y0) màu trùng với tọa độ (x;y) của quả thì ta cho thêm 1 phần tử mới vào đầu mảng và cập nhật lại phần từ vừa 
thêm vào đầu mảng là đầu của rắn tức là bước 1 của hàm xử lý rắn của phần rắn di chuyển đã code ở dòng 548*/
bool kt_ran_an_qua(int xqua, int yqua, int x0, int y0)
{
    if ((x0 == xqua) && (y0 == yqua))
    {
        return true;//ran an qua
    }
    return false;
}

int main() {
    int toaDoX[MAX], toaDoY[MAX];/*toaDoX và toaDoY là hai mảng chứa tọa độ từng khúc của rắn 1 khúc của rắn sẽ có tọa độ là (x,y) thì hai mảng
    toaDoX và toaDoY gộp 2 giá trị x và y tương ứng vị trí phần tử trong mảng lại sẽ ra tọa độ (x;y) để hình thành 1 hình rắn gồm nhiều khúc rắn
    dài bao nhiêu thì số phần tử trong hai mảng toadoX và toadoY sẽ tương ứng với độ dài cũng như là số khúc của rắn*/
   
    bool GameOver = false;/*Khởi tạo 1 biến có tên là GameOver kiểu bool vs giá trị là false tức khi vừa vào game thì game chưa kết thúc tức 
    GameOver mà còn false là game đang còn chạy ngược lại nếu biến GameOver là true thì trò chơi kết thúc*/

    //----Vẽ tường------
    Ve_Tuong();

    //------Khởi tạo và vẽ rắn------
    Khoi_Tao_Ran(toaDoX, toaDoY);//Khởi tạo rắn xong thì rồi ta sẽ
    Ve_Ran(toaDoX, toaDoY);/*Vẽ con rắn lần đầu tiên. Lý do phải có hàm vẽ rắn ở đây là vì khi vừa vào ta chỉ khởi tạo rắn thôi thì khi tăng x lên 
    tức là di duyển rắn thì ta sẽ bị sót con rắn ở vị trí đầu và khi khởi tạo 1 con rắn thì ta sẽ vẽ 1 con rắn ở giữa màn hình rồi mới xử lý rắn ở hàm 
    xử lý ta đã gọi ở dòng 666*/ 

    //-----Gọi hàm kiểm tra rắn có đè quả và hàm tạo quả----------
     srand(time(NULL));//Mõi lần game bắt đầu là ta random 1 quả có tộ độ vị trí khác
    int xqua = 0, yqua = 0;
    //tạo quả
    tao_qua(xqua, yqua, toaDoX, toaDoY);


    int x = 50, y = 13;//Tọa độ x và y

    /*Level 4: di chuyển vật thể 4 hướng và có biên + phím(Nhấn w là đi lên, nhấn s là đi xuống, nhấn a là qua trái và nhấn d là qua phải) lên xuống
   thì phụ thuộc vào y và thêm trái phải thì phụ thuộc vào x*/

    int i = 1;//Biến màu, dùng để xác định giá trị màu
    /*Level 2*/int check = 3;/* #Tư duy khi vật duy chuyển thì phải có tọa độ (x;y) theo trục tọa độ Oxy
                               - 0 là chạm vào biên trên. Khi vật thể chạm vào biên trên thì phải cho vật thể đi xuống bằng cách tăng tọa độ Oy lên
                               - 1 là chạm vào biên dưới. Khi vật thể chạm vào biên dưới thì phải cho vật thể đi lên bằng cách giảm tọa độ Oy xuống
                               - 2 Là chạm vào biên phải. Khi vật chạm vào biên phải thì phải cho vật đi qua trái bằng cách giảm x xuống
                               - 3 Là chạm vào biên trái. Khi vật chạm vào biên trái thì phải cho vật đi qua phải bằng cách tăng x lên*/

    
    while (GameOver == false)//vòng lặp để di duyển vật thể 
    {
  
    SetColor(i);/*Hàm để set màu cho vật thể của thư viên Mylib của ta đã cài ở thư viện Mylib. Tham số truyền vào là 1 mã
    màu với tham số truyền vào là i và i là đoạn màu nằm từ 1 đến 15*/
    i++;//Mõi lần i tăng là vật thể đc set 1 màu mới
    if (i > 15)//Vì mã màu của i chỉ có từ 1 đến 15 thôi nếu i vượt quá 15 thì
    {
        i = 1;//Cho i chạy lại mã màu từ 1
    }


    /*Điều khiển có hai cách:
    - 1 là điều khiển bằng phím đơn: W,S,D,A
    - 2 là điều khiển bằng phím kép(phím kép là phím có 2 mã ASCII: 1 là -32 và mã còn lại là mã của phím): là điều khiển bằng phím mũi tên*/
    /*Level 3*///Diều khiển
    /*Level 3*/if (_kbhit())/*Hàm kbhit() là hàm dùng để kiểm tra xem người dùng có nhập gì vào không nếu kbhit() là true thì người dùng đã nhập 1 phím nào đó
        nếu người dùng không nhập gì thì hàm sẽ trả về giá trị là false*/
    {
        /*Level 3*/char kitu = _getch();/*Vì dữ liệu của người dùng nhập là nằm ở bộ nhớ đệm thì hàm _getch này nó sẽ thực hiện load bộ nhớ đệm trước rồi mới
        nhận kết quả là người dùng nhập phím gì để gán và biến kitu*/

        //Điều khiển bằng phím kép(phím kép là phím có 2 mã ASCII: 1 là -32 và 2 là mã của phím): là điều khiển bằng phím mũi tên
        /*Level 4*/if (kitu == -32)/*Kiểm tra có phải là phím kép(là các phím mũi tên) k tức là kiểm tra xem người dùng nhập vào có phải là phím mũi tên
                                   k*/
        {
            kitu = _getch();//Nếu là phím kép(là các phím mũi tên) thì phải load bộ nhớ đệm để lấy mã ASCII của phím mũi tên mà người dùng đã nhập 
            if (kitu == 72 && check != 0)/*Nếu mã ASCII là 72 thì người dùng đã nhập mũi tên đi lên và phải ràng buộc thêm điều kiện check != 0 để 
                khi rắn đang di chuyển lên thì không thể bấm di duyển xuống vì di chuyển xuống là ta cho check = 0 thì ở đây khi nhấn phím đi lên 
                là check = 1 và thêm đk check != 0 là khi đang điều khiển rắn đi lên thì không thể điều khiển rắn đi xuống ngay lúc rắn đang đi lên 
                đc vì bản chất con rắn là cuộn chứ k tự ăn đuôi chủa chính nó*/
            {
                check = 1;/*Ta đã set 1 cái điều kiện cho vật thể đi lên là: else if (check == 1)//Di chuyển lên
                                                                                  {
                                                                                      y--;//Cho vật thể đi lên bằng cách giảm tọa độ Oy xuống
                                                                                   }*/
            }
            else if (kitu == 80 && check != 1)/*Nếu mã ASCII là 80 thì người dùng đã nhập mũi tên đi xuống và phải ràng buộc thêm điều kiện check != 1 
                để khi rắn đang di chuyển xuống thì không thể bấm di duyển lên vì di chuyển lên là ta cho check = 1 thì ở đây khi nhấn phím đi xuống
                là check = 0 và thêm đk check != 1 là khi đang điều khiển rắn đi xuống thì không thể điều khiển rắn đi lên ngay lúc rắn đang đi xuống
                đc vì bản chất con rắn là cuộn chứ k tự ăn đuôi chủa chính nó*/
            {
                check = 0;/*Ta đã set 1 cái điều kiện cho vật thể đi xuống là:    if (check == 0)//Di chuyển xuống
                                                                                  {
                                                                                      y++;//Cho vật thể đi xuống bằng cách tăng tọa độ Oy lên
                                                                                   }*/
            }
            else if (kitu == 75 && check != 3)/*Nếu mã ASCII là 75 thì người dùng đã nhập mũi tên đi qua trái và phải ràng buộc thêm điều kiện 
                check != 3 để khi rắn đang di chuyển qua trái thì không thể bấm di duyển qua phải vì di chuyển qua trái là ta cho check = 2 thì ở đây
                khi nhấn phím mũi tên trái là check = 2 và thêm đk check != 3 là khi đang điều khiển rắn đi qua trái thì không thể điều khiển rắn đi
                qua phải ngay lúc rắn đang đi qua trái đc vì bản chất con rắn là cuộn chứ k tự ăn đuôi chủa chính nó*/
            {
                check = 2;/*Nếu x đi đến tận biên phải thì cho x đi qua trái lại vì ta đã set điều kiện else if (check == 2)//Di chuyển qua trái
                                                                                          {
                                                                                           x--;//Cho vật thể đi qua trái bằng cách giảm tọa độ Ox xuống
                                                                                           }*/

            }
            else if (kitu == 77 && check != 2)/*Nếu mã ASCII là 75 thì người dùng đã nhập mũi tên đi qua phải và phải ràng buộc thêm điều kiện 
                check != 2 để khi rắn đang di chuyển qua phải thì không thể bấm di duyển qua trái vì di chuyển qua phải là ta cho check = 3 thì ở đây
                khi nhấn phím mũi tên phải là check = 3 và thêm đk check != 2 là khi đang điều khiển rắn đi qua phải thì không thể điều khiển rắn đi
                qua trái ngay lúc rắn đang đi qua phải đc vì bản chất con rắn là cuộn chứ k tự ăn đuôi chủa chính nó*/
            {
                check = 3;/*Nếu x đi đến tận biên trái thì cho x đi qua phải lại vì ta đã set điều kiện else if (check == 3)//Di chuyển qua phải
                                                                                          {
                                                                                           x++;//Cho vật thể đi qua phải bằng cách tăng tọa độ Ox lên
                                                                                           }*/

            }
        }
    }

    //Kiểm tra hướng
    /*Level 2*/ if (check == 0)//Di chuyển xuống
    {
        y++;//Cho vật thể đi xuống bằng cách tăng tọa độ Oy lên 
    }
    /*Level 2*/else if (check == 1)//Di chuyển lên
    {
        y--;//Cho vật thể đi lên bằng cách giảm tọa độ Oy xuống 
    }
    /*Level 4*/else if (check == 2)//Di chuyển qua trái
    {
        x--;//Cho vật thể đi qua trái bằng cách giảm tọa độ Ox xuống 
    }
    /*Level 4*/else if (check == 3)//Di chuyển qua phải
    {
        x++;//Cho vật thể đi qua phải bằng cách tăng tọa độ Ox lên 
    }
        //Rắn di chuyển
        Xoa_Du_Lieu_Cu(toaDoX, toaDoY);
        Xu_Ly_Ran(toaDoX, toaDoY, x, y,xqua, yqua);

        //Kiểm tra rắn 
       GameOver = Check_GameOver(toaDoX, toaDoY);
        
        Sleep(100);
    }
    cout << "\n\n\n\n\t\t\t\t\t\tGAME OVER !";
    _getch();
 
}

//======================== Project chính của Game A Huting Snacke Nâng Cao ====================
/*Có time thì phát triển làm thêm phần nâng cao, Phần nâng cao ta sẽ phải thêm: 
- Khi vào game thì tạo q cái menu 
- Rắn đi xuyên tường
- ăn quả màu gì rắn sẽ đổi thành màu của quả
- Ăn quả có phần thưởng cho rắn như: 
+ ăn quả tăng tốc thì giảm Sleep(); xuống để rắn chạy nhanh hơn
+ ăn quả giảm tốc thì tăng Sleep(); lên để rắn chạy chậm lại
+ ăn quả bất tử thì rắn chạm tường và cắn đuôi không bị GameOver
- Tạo một cái MENU lựa chọn cho người chơi chọn: 
+--------------------------------------------------------------+
|+ Hướng dẫn:                                                  |
|           > điều khiển bằng: W S D A                         |
|           > điều khiển bằng: mũi tên lên xuống trái phải     |
|+ Luật chơi:                                                  | 
|           > di chuyển rắn ăn các phần thưởng                 |
|           > rắn tự cắn đuôi thì GameOver                     |
|           > Cổ điển: Rắn không thể chạm tường                |
|           > Tùy chọn: Rắn có thể đi xuyên tường              |
+--------------------------------------------------------------+
          Game Rắn Săn mồi
    oo0   Bắt đầu - (Cổ điển)
          Bắt đầu - (Tùy chọn)

*/           