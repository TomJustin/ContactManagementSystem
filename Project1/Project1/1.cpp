// #include<iostream>

// int main() {
// 	struct student {
// 		char name[10];
// 		int c1, c2, c3;
// 		int Total;
// 	}Student[3];
// 	for (int i = 0; i < 3; i++) {
// 		std::cin >> Student[i].name >> Student[i].c1 >> Student[i].c2 >> Student[i].c3;
// 		Student[i].Total = Student[i].c1 + Student[i].c2 + Student[i].c3;
// 	}
// 	int Max = 0;
// 	for (int i = 0; i < 3; i++) {
// 		if (Student[Max].Total < Student[i].Total)
// 			Max = i;
// 	}
// 	std::cout << Student[Max].name;
// }
#include <iostream>
#include <string>

int main() {
    int N;
    std::cin >> N;
    
    std::string bestName;
    int bestC1, bestC2, bestC3;
    int maxTotal = -1;  // 初始化为较小值
    
    for (int i = 0; i < N; i++) {
        std::string name;
        int c1, c2, c3;
        std::cin >> name >> c1 >> c2 >> c3;
        
        int total = c1 + c2 + c3;
        
        // 只有当总分严格大于当前最大值时才更新
        // 这样就自然保持了输入顺序最小的特点
        if (total > maxTotal) {
            maxTotal = total;
            bestName = name;
            bestC1 = c1;
            bestC2 = c2;
            bestC3 = c3;
        }
    }
    
    std::cout << bestName << " " << bestC1 << " " << bestC2 << " " << bestC3 << std::endl;
    
    return 0;
}