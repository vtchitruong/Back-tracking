#include <iostream>
#include <vector>

using namespace std;

// Mảng solution chứa tất cả đáp án, là các số nhị phân hợp lệ
vector<vector<int>> solution;

void generateBinary(vector<int> binary, int length, int current)
{
    // Nếu độ dài số nhị phân đã đủ theo yêu cầu,
    // thì nạp vào mảng solution
    if (binary.size() == length)
    {
        solution.push_back(binary);
        return;
    }

    // Lần lượt chọn chữ số 0 và 1
    for (int digit = 0; digit < 2; ++digit)
    {
        // Nạp chữ số 0 (hoặc 1) hoặc binary
        binary.push_back(digit);

        // Gọi hàm đệ quy để chọn chữ số ở vị trí tiếp theo
        generateBinary(binary, length, current + 1);

        // Quay lui: Xóa bỏ chữ số cuối cùng (để chuẩn bị nạp chữ số khác cho cùng vị trí đó)
        binary.pop_back();    
    }
}

void showSolution(int length)
{
    for (int i = 0; i < solution.size(); ++i)
    {
        for (int j = 0; j < length; ++j)
        {
            cout << solution[i][j];
        }
        cout << endl;
    }
}

int main()
{
    // List B lưu số nhị phân, mỗi phần tử là một chữ số
    vector<int> B;
    
    // Độ dài của số nhị phân B
    int n;
    cout << "Nhập số chữ số: ";
    cin >> n;

    generateBinary(B, n, 0);

    showSolution(n);

    return 0;
}