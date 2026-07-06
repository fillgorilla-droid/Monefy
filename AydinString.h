//
// Created by User on 5/17/2026.
//

#ifndef UNTITLED3_AYDINSTRING_H
#define UNTITLED3_AYDINSTRING_H

#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include <fstream>

using namespace std;

class MyString {
private:
    char* str;
    size_t size;
public:

    MyString() {
        this->str = nullptr;
    }

    MyString(const char* str)
    {
        this->str = new char[strlen(str) + 1];
        strcpy(this->str, str);

    }

    MyString(const MyString& src) {
        this->str = new char[strlen(src.str) + 1];
        strcpy(this->str, src.str);
    }

    MyString(MyString&& src) noexcept {
        this->str = src.str;
        src.str = nullptr;
    }

    void setStr(const char* str) {
        delete[] this->str;
        this->str = new char[strlen(str) + 1];
        strcpy(this->str, str);
    }

    const char* getStr() const {
        return this->str;
    }

    MyString& operator=(const MyString& src) {
        if (this == &src) return *this;

        setStr(src.getStr());
        return *this;
    }

    MyString& operator=(MyString&& src) noexcept {
        this->str = src.str;
        src.str = nullptr;
        return *this;
    }

    MyString operator+(const MyString& src) const {
        MyString new_str;
        new_str.str = new char[strlen(this->str) + strlen(src.str) + 1];

        strcpy(new_str.str, this->str);
        MyString result = strconcat(new_str.str, src.str);

        return result;
    }

    MyString& operator+=(const MyString& src) {
        char* temp = strconcat(this->str, src.str);

        delete[] this->str;
        this->str = temp;

        return *this;
    }

    bool operator==(const MyString& src) const {
        return strcmp(this->str, src.str) == 0;
    }

    bool operator!=(const MyString& src) const {
        return strcmp(this->str, src.str) != 0;
    }

    bool operator<(const MyString& src) const { // это просто так
        return strcmp(this->str, src.str) < 0;
    }

    bool operator>(const MyString& src) const {
        return strcmp(this->str, src.str) > 0;
    }

    bool operator<=(const MyString& src) const {
        return strcmp(this->str, src.str) <= 0;
    }

    bool operator>=(const MyString& src) const {
        return strcmp(this->str, src.str) >= 0;
    }

    char operator[](int index) const {
        if (index > strlen(this->str) || index < 0) throw invalid_argument("invalid index");
        return this->str[index];
    }

    char operator()(int index,int) const {
        if (index > strlen(this->str) || index < 0) throw invalid_argument("invalid index");
        return this->str[index];
    }

    operator int(){
        int n = 1;
        int when = 0;
        if (this->str[0] == 45) {
            n = -1;
            when++;
        };
        int number = 0;
        for (int i = when;i < strlen(this->str);i++) {
            if (this->str[i] >= 48 && this->str[i] <= 57) {
                number = number * 10 + this->str[i] - 48;
            }
            else {
                throw invalid_argument("ValueError");
            }
        }
        number *= n;

        return number;
    }

    operator bool() {
        int flag = 0;
        int flag2 = 0;
        for (int i = 0; i < strlen(this->str); i++) {
            if (this->str[i] == 32) {
                flag2++;
            }
            else {
                flag++;
            }
        }
        flag2 = flag;
        if (flag > 0 && flag2 > 0) {
            return true;
        }
        else {
            return false;
        }
    }

    operator float() {
        for (int i = 0;i < strlen(this->str);i++) {
            if (this->str[i] == 46) {
                continue;
            }
            if (this->str[i] >= 48 && this->str[i] <= 57) {
                this->str[i] -= 48;
            }
            else {
                return 0;
            }
        }

        float number = 0;
        for (int k = 0; k < strlen(this->str); k++) {
            if (this->str[k] == 46) {
                continue;
            }
        }

        return number;
    }

    MyString operator*(int count) const {
        MyString result;

        if (count < 0) {
            throw invalid_argument("invalid count");
        }

        result.str = new char[strlen(this->str) * count + 1];
        result.str[0] = '\0';

        for (int i = 0; i < count; i++) {
            strcat(result.str, this->str);
        }

        return result;
    }

    MyString operator/(int count) const {
        MyString result;

        if (count > strlen(this->str)) {
            count = strlen(this->str);
        }

        result.str = new char[count + 1];

        int i = 0;
        while (i < count) {
            result.str[i] = this->str[i];
            i++;
        }

        result.str[i] = '\0';

        return result;
    }

    friend ostream& operator<<(ostream& os, const MyString& src);
    friend istream& operator>>(istream& is, MyString& src);

    ~MyString()
    {
        delete[] str;
    }

    // ====================== МЕТОДЫ ==========================

    void upper() {
        for (int i = 0; i < strlen(this->str); i++) {
            if (this->str[i] >= 97 && this->str[i] <= 122) {
                this->str[i] -= 32;
            }
        }
    }

    void lower()  {
        for (int i = 0; i < strlen(this->str); i++) {
            if (this->str[i] >= 65 && this->str[i] <= 90) {
                this->str[i] += 32;
            }
        }
    }

    int lenght() const {

        short len = 0;
        for (int i = 0; i < strlen(this->str); i++) {
            len++;
        }

        return len;
    }

    int find(const char* substr) const {
        for (int i = 0; i < strlen(this->str); i++) {
            if (this->str[i] == substr[i]) {
                return i;
            }
        }
        return -1;
    }

    void append(const char* substr) {
        MyString new_str;
        new_str.str = new char[strlen(this->str) + strlen(substr) + 1];
        short i = 0;

        while (i < strlen(this->str)) {
            new_str.str[i] = this->str[i];
            i++;
        }

        short j = 0;
        while (j < strlen(substr)) {
            new_str.str[i] = substr[j];
            i++;
            j++;
        }
        new_str.str[i] = '\0';

        delete[] this->str;
        this->str = new_str.str;

        new_str.str = nullptr;
    }

    const char* substring(int start, int lenght) const {
        short j = 0;
        while (start < lenght) {
            str[j] = this->str[start];
            start++;
            j++;
        }
        str[j] = '\0';
        return str;
    }

    void swapcase()
    {
        for (int i = 0; i < strlen(this->str); i++)
        {
            if (this->str[i] >= 97 && this->str[i] <= 122) {
                this->str[i] -= 32;
            }
            else
            {
                this->str[i] += 32;
            }
        }
    }

    bool isEmpty() const
    {
        if (strlen(this->str) == 0)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    char* strconcat(const char* str_1, const char* str_2) const
    {
        int str_1_length = strlen(str_1);
        int str_2_length = strlen(str_2);
        int temp_size = str_1_length + str_2_length;
        char* temp_arr = new char[temp_size + 1];

        for (size_t i = 0; i < str_1_length; i++)
        {
            temp_arr[i] = str_1[i];
        }

        for (size_t i = str_1_length, index = 0; i < temp_size; i++, index++)
        {
            temp_arr[i] = str_2[index];
        }

        temp_arr[temp_size] = '\0';

        return temp_arr;
    }

    void capitalize() const
    {
        this->str[0] -= 32;
    }

    MyString strip() const
    {
        MyString result;

        result.str = new char[strlen(this->str) + 1];

        int j = 0;

        for (int i = 0; this->str[i] != '\0'; i++) {

            if (this->str[i] != ' ') {
                result.str[j] = this->str[i];
                j++;
            }

        }

        result.str[j] = '\0';

        return result;
    }

    bool isDigit() const
    {
        for (int i = 0; i < strlen(this->str); i++) {
            if (this->str[i] >= 48 && this->str[i] <= 57) {
                return true;
            }
        }
        return false;
    }

    bool isAlpha() const {
        for (int i = 0; i < strlen(this->str); i++) {
            if (this->str[i] >= 65 && this->str[i] <= 122) {
                return true;
            }
        }
        return false;
    }

    void Write(ofstream& file) const
    {
        size_t len = lenght();

        file.write((char*)&len, sizeof(len));
        file.write(str, len);
    }

    void Read(ifstream& file)
    {
        size_t len = 0;

        file.read((char*)&len, sizeof(len));

        delete[] str;

        str = new char[len + 1];

        file.read(str, len);

        str[len] = '\0';
    }
};

inline ostream& operator<<(ostream& mycout, const MyString& str) {
    mycout << str.str;
    return mycout;
}

inline istream& operator>>(istream& mycin, MyString& str) {
    char temp[256];
    mycin >> temp;

    str.str = new char[strlen(temp) + 1];
    strcpy(str.str, temp);

    return mycin;
}

#endif //UNTITLED3_AYDINSTRING_H
