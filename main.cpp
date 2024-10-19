#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <string>


template<class T>
std::vector<T> generate_random_vector(std::size_t num, T min = -10, T max = 10)
{
    std::random_device rd;
    std::mt19937 e2(rd());
    std::uniform_real_distribution<> dist(min, max);

    auto lambda = [&e2, &dist] () -> T { return dist(e2); };

    std::vector<T> result(num);
    std::generate_n(result.begin(), num, lambda);
    return result;
}


float sum(std::vector<float> v, int from, int to) {
    float s { 0 };
    for (int i = from; i <= to; i++) {
        s += v[i];
    }
    return s;
}


void task1() {
    std::cout << "Введите число a: ";
    int a;
    std::cin >> a;
    std::vector<float> v = generate_random_vector<float>(10, 1, 100);
    for (int i = 0; i < v.size(); i++) {
        v[i] = (v[i] * 2 - a) / v[0];
    }
}


void task2() {
    std::vector<float> v = generate_random_vector<float>(10, 1, 100);
    for (auto el: v) std::cout << el << std::endl;
    float all_sum = sum(v, 0, v.size() - 1);
    float avg = all_sum / v.size();
    std::cout << "Сумма всех элементов: " << all_sum << std::endl;

    float square_sum { 0 };
    for (float el : v) {
        square_sum += el * el;
    }
    std::cout << "Сумма квадратов всех элементов: " << square_sum << std::endl;
    std::cout << "Сумма первых шести элементов: " << sum(v, 0, 5) << std::endl;
    std::cout << "Введите значения k1 и k2: ";
    int k1, k2;
    std::cin >> k1 >> k2;
    std::cout << "Сумма элементов с " << k1 << " по " << k2 << ": " << sum(v, k1, k2) << std::endl;
    std::cout << "Среднее арифметическое всех элементов: " << avg << std::endl;
    std::cout << "Введите значения s1 и s2: ";
    int s1, s2;
    std::cin >> s1 >> s2;
    float sum_s1_s2 = sum(v, s1, s2);
    std::cout << "Среднее арифметическое элементов с " << s1 << " по " << s2 << ": " << sum_s1_s2 / (s2 - s1 + 1) << std::endl;
}


void task3() {
    std::vector<float> v = generate_random_vector<float>(20, 1, 100);
    float t[3] = {v[0], v[1], v[2]};
    v[0] = v[v.size() - 3];
    v[1] = v[v.size() - 2];
    v[2] = v[v.size() - 1];
    v[v.size() - 1] = t[2];
    v[v.size() - 2] = t[1];
    v[v.size() - 3] = t[0];
}


void task4() {
    std::vector<float> v = generate_random_vector<float>(20, 1, 100);
    
    std::vector<int> res1 {};
    bool isFirst = true;
    for (int i = 0; i < v.size(); i++) {
        if (isFirst && v[i] < 0) {
            isFirst = false;
            continue;
        }
        res1.push_back(v[i]);
    }

    isFirst = true;
    std::vector<int> res2 {};
    for (int i = res1.size() - 1; i >= 0; i--) {
        if (isFirst && res1[i] % 2 == 0) {
            isFirst = false;
            continue;
        }
        res2.push_back(v[i]);
    }
}


void task5() {
    std::string name;
    std::cout << "Введите имя: ";
    std::cin >> name;
    if (name.length() % 2 == 0) {
        std::cout << "Количество букв четно" << std::endl;
    } else {
        std::cout << "Количество букв нечетно" << std::endl;
    }
}



void task6() {
    std::string s1, s2;
    std::cout << "Введите две фамилии: ";
    std::cin >> s1 >> s2;
    if (s1.length() > s2.length())
        std::cout << "Первая фамилия длиннее" << std::endl;
    else if (s1.length() < s2.length())
        std::cout << "Вторая фамилия длиннее" << std::endl;
    else
        std::cout << "Фамилии равны по длине" << std::endl;
}


void task7() {
    std::string city1, city2, city3;

    std::cout << "Введите название первого города: ";
    std::cin >> city1;

    std::cout << "Введите название второго города: ";
    std::cin >> city2;

    std::cout << "Введите название третьего города: ";
    std::cin >> city3;

    std::string longest = city1;
    std::string shortest = city1;

    if (city2.length() > longest.length()) {
        longest = city2;
    } else if (city2.length() < shortest.length()) {
        shortest = city2;
    }

    if (city3.length() > longest.length()) {
        longest = city3;
    } else if (city3.length() < shortest.length()) {
        shortest = city3;
    }

    std::cout << "Самое длинное название: " << longest << std::endl;
    std::cout << "Самое короткое название: " << shortest << std::endl;
}


void task8() {
    std::string word, result;
    int m, n;
    std::cout << "Введите слово: ";
    std::cin >> word;
    std::cout << "Введите начальный и конечный индекс: ";
    std::cin >> m >> n;
    for (int i = m; i <= n; ++i) {
        result += word[i];
    }
    std::cout << "Часть слова: " << result << std::endl;
}


void task9() {
    std::string word;
    std::cout << "Введите слово: ";
    std::cin >> word;
    int length = word.length();
    std::vector<char> result;
    for (int i = 0; i < length; ++i) {
        result.push_back('*');
    }
    for (char c : word) {
        result.push_back(c);
    }
    for (int i = 0; i < length; ++i) {
        result.push_back('*');
    }
    for (char c : result) {
        std::cout << c;
    }
    std::cout << std::endl;
}


void task10() {
    std::string word;
    std::cout << "Введите слово: ";
    std::cin >> word;
    int count {};
    for (char letter : word) {
        if (letter == 'a') 
            ++count;
    }
    std::cout << "Процент использования буквы 'a' в строке: " << (count * 1.0f) / word.length() * 100 << "%" << std::endl;
}


void task11() {
    std::string seq = "Can you can a can as a canner can can a can?";
    std::string newWord, result_str;
    std::cout << "Введите newWord: ";
    std::cin >> newWord;
    for (int i = 0; i < seq.size(); ++i) {
        if (i + 2 < seq.length() && seq[i] == 'c' && seq[i + 1] == 'a' && seq[i + 2] == 'n') {
            for(char c : newWord) {
                result_str.push_back(c);
            }
            i += 2;
        }
        else {
            result_str.push_back(seq[i]);
        } 
    }
    std::cout << "Новое предложение: " << result_str << std::endl;
}



int main() {
    int task;
    std::cout << "Введите номер задачи: ";
    std::cin >> task;

    switch (task) {
        case 1:
            task1();
            break;
        case 2:
            task2();
            break;
        case 3:
            task3();
            break;
        case 4:
            task4();
            break;
        case 5:
            task5();
            break;
        case 6:
            task6();
            break;
        case 7:
            task7();
            break;
        case 8:
            task8();
            break;
        case 9:
            task9();
            break;
        case 10:
            task10();
            break;
        case 11:
            task11();
            break;
    }

    return 0;
}