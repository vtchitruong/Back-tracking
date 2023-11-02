def generate_binary(binary, length, current):
    # Nếu độ dài số nhị phân đã đủ theo yêu cầu,
    # thì nạp vào mảng solution
    if len(binary) == length:
        solution.append(binary.copy())
        return
    
    ## Lần lượt chọn chữ số 0 và 1
    for digit in [0, 1]:
        # Nạp chữ số 0 (hoặc 1) hoặc binary
        binary.append(digit)

        # Gọi hàm đệ quy để chọn chữ số ở vị trí tiếp theo
        generate_binary(binary, length, current + 1)

        # Quay lui: Xóa bỏ chữ số cuối cùng (để chuẩn bị nạp chữ số khác cho cùng vị trí đó)
        binary.pop()

def show_solution():
    for binary in solution:
        s = ''.join(map(str, binary))
        print(s)

if __name__ == '__main__':
    # List B lưu số nhị phân, mỗi phần tử là một chữ số
    B = []
    
    # Độ dài của số nhị phân B
    n = int(input('Nhập số chữ số: '))

    # Mảng solution chứa tất cả đáp án, là các số nhị phân hợp lệ
    solution = []

    generate_binary(B, n, 0)

    show_solution()