/* Một đơn vị sản xuất gồm có các cán bộ là công nhân, kỹ sư, nhân viên. Mỗi cán bộ cần quản lý các dữ liệu: Họ tên, tuổi, giới tính(name, nữ, khác), địa chỉ.

Cấp công nhân sẽ có thêm các thuộc tính riêng: Bậc (1 đến 10).
Cấp kỹ sư có thuộc tính riêng: Nghành đào tạo.
Các nhân viên có thuộc tính riêng: công việc.
Yêu cầu 1: Xây dựng các lớp CongNhan, KySu, NhanVien kế thừa từ lớp CanBo.

Yêu cầu 2: Xây dựng lớp QLCB(quản lý cán bộ) cài đặt các phương thức thực hiện các chức năng sau:

Thêm mới cán bộ.
Tìm kiếm theo họ tên.
Hiện thị thông tin về danh sách các cán bộ.
Thoát khỏi chương trình.

*/

#include <iostream>
#include <vector>
using namespace std;

class Canbo {
public:

    string hoten;
    int tuoi;
    string gioitinh;
    string diachi;
};
class Congnhan: public Canbo {
public:
    int bac;
};
class Kysu: public Canbo {
public:
    string Nganh;
};
class Nhanvien: public Canbo {
public:
    string congviec;
};

class QLCB {
public:
    vector<Canbo> cb; 
    void Themcanbomoi(Canbo _canbo) { 
    cb.push_back(_canbo);
    }
    Canbo Timkiemtheohoten(string name){  
    for (int i = 0; i<cb.size(); i++){
        if(cb[i].hoten == name){
            return cb[i];
        }
    }
    throw out_of_range("Khong tim thay ten");
    }
    void Danhsachcanbo(){
    cout << "Danh sach can bo: \n";
    for( int i = 0; i< cb.size(); i++)
    {
        cout << cb[i].hoten <<endl;
    }
    }
};

int main(){

Canbo canbo1, canbo2, canbo3, c;
cout<< "Nhap thong tin cac can bo: \n";
cin >> canbo1.hoten >> canbo1.tuoi >>canbo1.gioitinh >>canbo1.diachi;
cin >> canbo2.hoten >> canbo2.tuoi >>canbo2.gioitinh >>canbo2.diachi;
cin >> canbo3.hoten >> canbo3.tuoi >>canbo3.gioitinh >>canbo3.diachi;
QLCB q;
q.Themcanbomoi(canbo1);
q.Themcanbomoi(canbo2);
q.Themcanbomoi(canbo3);
q.Danhsachcanbo();
c = q.Timkiemtheohoten(canbo1.hoten);
cout << "Thong tin cua can bo do: \n" << c.hoten <<endl << c.diachi <<endl << c.tuoi <<endl  << c.gioitinh <<endl;
return 0;
}