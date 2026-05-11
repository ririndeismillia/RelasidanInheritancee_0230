#include <iostream>
using namespace std;

//CLASS USER
class User {
protected:
    static int globalId;
    int id;
    string nama;
    string email;

public:
    // constructor
    User(string nama, string email) {
        this->nama = nama;
        this->email = email;
        id = generateId();
    }

    // function generate id
    int generateId() {
        globalId++;
        return globalId;
    }
};

// inisialisasi static variable
int User::globalId = 0;

//CLASS MEMBER 
class Member : public User {
private:
    bool status;

public:
    // constructor
    Member(string nama, string email, bool status)
        : User(nama, email) {

        this->status = status;
    }

    // menampilkan profile member
    void showProfile() {
        cout << "===== PROFILE MEMBER =====" << endl;
        cout << "ID     : " << id << endl;
        cout << "Nama   : " << nama << endl;
        cout << "Email  : " << email << endl;

        if (status == true) {
            cout << "Status : Aktif" << endl;
        } else {
            cout << "Status : Nonaktif" << endl;
        }

        cout << endl;
    }

    // getter status
    bool getStatus() {
        return status;
    }

    // ubah status
    void setStatus(bool status) {
        this->status = status;
    }
};

//CLASS ADMIN 
class Admin : public User {
public:
    // constructor
    Admin(string nama, string email)
        : User(nama, email) {
    }

    // menampilkan semua member
    void showAllMember(Member m1, Member m2) {
        cout << "===== DATA MEMBER =====" << endl;
        m1.showProfile();
        m2.showProfile();
    }

    // mengubah status member
    void toggleActivationMember(Member &m) {
        if (m.getStatus() == true) {
            m.setStatus(false);
        } else {
            m.setStatus(true);
        }
    }
};

int main() {

    // membuat object member
    Member member1("Budi", "budi@gmail.com", true);
    Member member2("Siti", "siti@gmail.com", false);

    // membuat object admin
    Admin admin1("Admin", "admin@gmail.com");

    // tampil semua member
    admin1.showAllMember(member1, member2);

    // ubah status member2
    admin1.toggleActivationMember(member2);

    cout << "Setelah status diubah:" << endl;
    member2.showProfile();

    return 0;
}