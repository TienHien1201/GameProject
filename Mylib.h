/*file.h là fie thường dùng để tạo 1 cái thư viện vs mục đích riêng của ta để qua bên file.cpp chỉ cần add thư viện file.h
này bằng cách (#include "file.h" ) là sài đc chức năng của thư viện mà ta đã tạo*/

#pragma once/*Có tác dụng tránh xung đột thư viện khi gọi chồng thư viện
vd ở bên file.cpp ta đã gọi thư viện #include<iostream>  rồi mà bên file.h vẫn gọi lại thì dẫn đến bị xung đột thư viện */
#include <stdio.h>
#include <conio.h>
#include<ctime> /* thư viện hỗ trợ về thời gian thực */
#include "windows.h" // thư viện này bá đạo lắm nhé - chứa nhiều đồ chơi nek - cứ tìm hiểu dần dần s

//======= lấy tọa độ x của con trỏ hiện tại =============
#define KEY_NONE	-1/*Đây là một preprocessor directive (định nghĩa trước biên dịch) trong C++. Nó định nghĩa hằng số KEY_NONE 
với giá trị là -1. Điều này giúp dễ nhận diện khi không có phím nào được nhấn.*/
int whereX()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;/*Tạo một biến csbi có kiểu dữ liệu là CONSOLE_SCREEN_BUFFER_INFO. Đây là một cấu trúc dữ liệu
	trong Windows để lưu thông tin về bộ đệm màn hình console.*/
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))/* Sử dụng hàm GetConsoleScreenBufferInfo để lấy thông tin
		về bộ đệm màn hình console. Đối số thứ nhất là handle của bộ đệm đầu ra (stdout), được lấy bằng hàm GetStdHandle với đối số
		STD_OUTPUT_HANDLE. Đối số thứ hai là địa chỉ của biến csbi, nơi dữ liệu được lưu trữ.*/
		return csbi.dwCursorPosition.X;/*Trả về tọa độ x của con trỏ hiện tại trên màn hình console từ biến csbi. Cấu trúc 
	    CONSOLE_SCREEN_BUFFER_INFO chứa thông tin về vị trí hiện tại của con trỏ và nó có một thành viên là dwCursorPosition là một cấu 
		trúc COORD chứa tọa độ của con trỏ X*/
	return -1;/*Trong trường hợp hàm GetConsoleScreenBufferInfo thất bại (ví dụ: nếu không thể lấy thông tin bộ đệm màn hình), hàm whereX() 
	    sẽ trả về -1, chỉ ra rằng không thể xác định tọa độ x của con trỏ.*/
}

//========= lấy tọa độ y của con trỏ hiện tại =======
int whereY()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;/*Tạo một biến csbi có kiểu dữ liệu là CONSOLE_SCREEN_BUFFER_INFO. Đây là một cấu trúc dữ liệu
	trong Windows để lưu thông tin về bộ đệm màn hình console.*/
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))/* Sử dụng hàm GetConsoleScreenBufferInfo để lấy thông tin
		về bộ đệm màn hình console. Đối số thứ nhất là handle của bộ đệm đầu ra (stdout), được lấy bằng hàm GetStdHandle với đối số
		STD_OUTPUT_HANDLE. Đối số thứ hai là địa chỉ của biến csbi, nơi dữ liệu được lưu trữ.*/
		return csbi.dwCursorPosition.Y;/*Trả về tọa độ x của con trỏ hiện tại trên màn hình console từ biến csbi. Cấu trúc 
	    CONSOLE_SCREEN_BUFFER_INFO chứa thông tin về vị trí hiện tại của con trỏ và nó có một thành viên là dwCursorPosition là một cấu 
		trúc COORD chứa tọa độ của con trỏ Y*/
	return -1;/*Trong trường hợp hàm GetConsoleScreenBufferInfo thất bại (ví dụ: nếu không thể lấy thông tin bộ đệm màn hình), hàm whereX() 
	    sẽ trả về -1, chỉ ra rằng không thể xác định tọa độ x của con trỏ.*/
}

//============== dịch con trỏ hiện tại đến điểm có tọa độ (x,y) ==========
void gotoXY(int x, int y)
{
	HANDLE hConsoleOutput;/*Tạo một biến có kiểu HANDLE để lưu trữ handle của bộ đệm đầu ra (stdout) của màn hình console.*/
	COORD Cursor_an_Pos = { x, y };/*Tạo một biến có kiểu dữ liệu COORD(coordinate - tọa độ) với tên là Cursor_an_Pos và gán giá trị x và y 
	được truyền vào từ tham số của hàm.*/
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);/*Lấy handle(Xử lý) của bộ đệm đầu ra (stdout) của màn hình console bằng cách sử dụng hàm 
	GetStdHandle với đối số là STD_OUTPUT_HANDLE.*/
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);/*Sử dụng hàm SetConsoleCursorPosition để di chuyển con trỏ đến tọa độ mới được chỉ
	định bởi biến Cursor_an_Pos trên màn hình console. Đối số thứ nhất là handle của bộ đệm đầu ra, và đối số thứ hai là tọa độ mới của con trỏ.*/
}

//============= đặt màu cho chữ =========
void SetColor(WORD color)
{
	HANDLE hConsoleOutput;/*Tạo một biến có kiểu HANDLE để lưu trữ handle của bộ đệm đầu ra (stdout) của màn hình console.*/
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);/* Lấy handle của bộ đệm đầu ra (stdout) của màn hình console bằng cách sử dụng hàm GetStdHandle 
	với đối số là STD_OUTPUT_HANDLE.*/

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;/*Tạo một biến có kiểu dữ liệu CONSOLE_SCREEN_BUFFER_INFO để lưu trữ thông tin về bộ đệm màn hình 
	console.*/
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);/*Lấy thông tin về bộ đệm màn hình console và lưu trữ vào biến screen_buffer_info.
	Thông tin này bao gồm các thuộc tính như kích thước màn hình, màu nền, màu văn bản, v.v.*/

	WORD wAttributes = screen_buffer_info.wAttributes;/* Lấy thuộc tính wAttributes từ biến screen_buffer_info. Đây là một thuộc tính trong
	CONSOLE_SCREEN_BUFFER_INFO chứa thông tin về màu sắc của văn bản trên màn hình console.*/
	color &= 0x000f;/*Thực hiện phép toán AND(&) bit với giá trị 0x000f để đảm bảo rằng chỉ có 4 bit cuối của color được sử dụng để biểu diễn màu.*/
	wAttributes &= 0xfff0;/*Thực hiện phép toán AND(&) bit với giá trị 0xfff0 để xóa 4 bit cuối của wAttributes, giữ lại các bit còn lại không liên 
	quan đến màu.*/
	wAttributes |= color;/*Gán giá trị màu mới cho 4 bit cuối của wAttributes bằng cách sử dụng phép OR( | ) bit.*/

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);/*Sử dụng hàm SetConsoleTextAttribute để thiết lập thuộc tính màu sắc cho văn bản trên màn 
	hình console. Đối số thứ nhất là handle của bộ đệm đầu ra, và đối số thứ hai là giá trị thuộc tính màu sắc mới (wAttributes).*/
}

//============== làm ẩn trỏ chuột ===========
void ShowCur(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);/*Tạo một biến handle có kiểu HANDLE để lưu trữ handle của bộ đệm đầu ra (stdout) của màn hình 
	console. Hàm GetStdHandle(STD_OUTPUT_HANDLE) được sử dụng để lấy handle của bộ đệm đầu ra.*/
	CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };/* Tạo một biến cursor có kiểu CONSOLE_CURSOR_INFO, là một cấu trúc dữ liệu để lưu trữ thông
	tin về con trỏ trên màn hình console. Trong trường hợp này, chúng ta cung cấp một giá trị cho hai thành viên của cấu trúc: Size (kích thước của 
	con trỏ, được đặt thành 1, có nghĩa là con trỏ sẽ có kích thước là 1 điểm ảnh.) và Visibility (tính hiển thị của con trỏ, được đặt bằng giá trị 
	của tham số CursorVisibility). Điều này có nghĩa là nếu CursorVisibility là true, tức là con trỏ sẽ được hiển thị trên màn hình console. Ngược lại, 
	nếu CursorVisibility là false, con trỏ sẽ bị ẩn đi trên màn hình console..*/
	SetConsoleCursorInfo(handle, &cursor);/*Sử dụng hàm SetConsoleCursorInfo để thiết lập thông tin về con trỏ trên màn hình console. Đối số thứ nhất 
	là handle của bộ đệm đầu ra, và đối số thứ hai là địa chỉ của biến cursor chứa thông tin về con trỏ. Điều này cho phép chúng ta thiết lập kích 
	thước và tính hiển thị của con trỏ dựa trên giá trị của CursorVisibility.*/
}

//======= trả về mã phím người dùng bấm =========
int inputKey()
{
	if (_kbhit())/*kiểm tra xem có phím nào được nhấn không. Nếu có ít nhất một phím đã được nhấn chương trình sẽ thực hiện các dòng lệnh bên trong.*/
	{
		int key = _getch();// sẽ trả về mã của phím đã nhấn. Mã này được lưu vào biến key.

		if (key == 224)/*kiểm tra xem mã của phím đã nhấn có phải là 224 không. Trong một số trường hợp, khi một số phím như các phím mũi tên, 
			hàm _getch() sẽ trả về 224 */
		{
			key = _getch();/*Nếu mã của phím là 224, chương trình lại gọi một lần nữa hàm _getch() để nhận mã phím tiếp theo, vì mã đặc biệt này 
			cần được kết hợp với mã phím tiếp theo để tạo thành một mã phím hoàn chỉnh.*/
			return key + 1000;/*Nếu mã phím là 224 và sau đó là một mã phím đặc biệt, hàm trả về tổng của hai mã này cộng thêm 1000. Điều này được 
			thực hiện để phân biệt mã của các phím đặc biệt với các phím thông thường.*/
		}

		return key;/*Nếu mã phím không phải là 224 (tức là mã phím đặc biệt), hàm sẽ trực tiếp trả về mã của phím đó.*/
	}
	else//Nếu không có phím nào được nhấn
	{
		return KEY_NONE;/*Trong trường hợp không có phím nào được nhấn, hàm sẽ trả về giá trị KEY_NONE(một hằng số được định nghĩa trước với giá 
		trị -1 hoặc một giá trị đặc biệt khác) để biểu diễn trạng thái không có phím nào được nhấn.*/
	}

	return KEY_NONE;/*Trong trường hợp không có phím nào được nhấn, hàm sẽ trả về giá trị KEY_NONE(một hằng số được định nghĩa trước với giá 
		trị -1 hoặc một giá trị đặc biệt khác) để biểu diễn trạng thái không có phím nào được nhấn.*/
}