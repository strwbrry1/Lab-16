
#include "stdio.h"
#define NUM_ELEMENTS 20

void printElements();
void deleteElement(int index);
void insertElement(int index, int elem);
void arrInput();
void odds10();
int morethan10();
int findFirstEven();
int findLastEven();
int min();
int max();

int arr[NUM_ELEMENTS];
int n = 0;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    //int index = -1;
    int choice;
    int con;
    do {
        printf("Содержимое массива: ");
        printElements();
        printf("Выберите нужную вам операцию:\n");
        printf("1: Ввести с клавиатуры массив\n");
        printf("2: x10 для всех нечетных элементов\n");
        printf("3: Найти минимальный элемент\n");
        printf("4: Кол-во элементов > 10\n");
        printf("5: х2 для последнего чётного\n");
        printf("6: Сколько чётных левее минимального\n");
        printf("7: х10 для нечетных правее минимального\n");
        printf("8: Поменять местами минимум и максимум\n");
        printf("9: Все чётные элементы меняют знаки\n");
        printf("10: Всё меньше 4 теперь 4\n");
        printf("11: Элементы между максимальным и минимальным х10\n");
        printf("12: Элементы между первым и последним чётным х100\n");
        printf("/// НАЧАЛАСЬ 17 ЛАБА ///\n");
        printf("13: Удалить элемент по индексу\n");
        printf("14: Вставить элемент по индексу\n");
        printf("15: Удалить минимальный элемент\n");
        printf("16: Перед минимальным элементом вставить ноль\n");
        printf("17: Удалить все чётные элементы\n");
        printf("18: Добавить в начало минимальный элемент\n");
        printf("19: Всё меньше 4 теперь не существует\n");
        printf("20: Дублировать все чётные\n");
        printf("\n");
        printf("0: Выйти из программы\n");
        printf("Ввод >>> ");
        scanf_s("%d", &choice);
        switch (choice) {
        case 1:
            arrInput();
            break;
        case 2:
            odds10();
            break;
        case 3:
            printf(">> %d <<\n\n", arr[min()]);
            break;
        case 4:
            printf(">> %d элементов больше 10 <<\n\n", morethan10());
            break;
        case 5:
            int index = findLastEven();
            if (index >= 0) {
                arr[index] *= 2;
            }
            break;
        case 6:
            index = min();
            con = 0;
            for (int i = index - 1; i >= 0; i--) {
                if (arr[i] % 2 == 0) {
                    con++;
                }
            }
            printf(">> %d чётных левее минимального <<\n\n", con);
            break;
        case 7:
            index = min();
            for (int i = index + 1; i < n; i++) {
                if (arr[i] % 2 != 0) {
                    arr[i] *= 10;
                }
            }
            break;
        case 8:
            if (n > 1)
            {
                int maxIndex = max();
                int minIndex = min();
                int temp = arr[maxIndex];
                arr[maxIndex] = arr[minIndex];
                arr[minIndex] = temp;
                printf(">> Оп-па <<\n\n");
            }
            else {
                printf(">> Мало элементов в списке <<\n\n");
            }
            break;
        case 9:
            for (int i = 0; i < n; i++) {
                if (arr[i] % 2 == 0) {
                    arr[i] *= -1;
                }
            }
            break;
        case 10:
            for (int i = 0; i < n; i++) {
                if (arr[i] < 4) {
                    arr[i] = 4;
                }
            }
            break;
        case 11:
            int maxI = max();
            int minI = min();
            if (maxI > minI) {
                for (int i = minI + 1; i < maxI; i++) {
                    arr[i] *= 10;
                }
            }
            else {
                for (int i = maxI + 1; i < minI; i++) {
                    arr[i] *= 10;
                }
            }
        case 12:
            int fInd = findFirstEven();
            int lInd = findLastEven();
            for (int i = fInd + 1; i < lInd; i++) {
                arr[i] *= 100;
            }
        case 13:
            printf("\nИндекс удаляемого элемента -> ");
            scanf_s("%d", &index);
            deleteElement(index);
            break;
        case 14:
            printf("\nИндекс куда вставить -> ");
            scanf_s("%d", &index);
            int elem;
            printf("\nЧто вставить -> ");
            scanf_s("%d", &elem);
            insertElement(index, elem);
            break;
        case 15:
            printf(">> Удалён элемент с индексом %d <<\n\n", min());
            deleteElement(min());
            break;
        case 16:
            printf(">> Перед минимальным вставлен ноль <<\n\n");
            insertElement(min(), 0);
            break;
        case 17:
            for (int i = 0; i < n; i++) {
                if (arr[i] % 2 == 0) {
                    deleteElement(i);
                    i--;
                }
            }
            printf(">> Удалено <<\n\n");
            break;
        case 18:
            insertElement(0, arr[min()]);
            break;

        case 19:
            for (int i = 0; i < n; i++) {
                if (arr[i] < 4) {
                    deleteElement(i);
                    i--;
                }
            }
            break;
        case 20:
            for (int i = 0; i < n; i++) {
                if (arr[i] % 2 == 0) {
                    insertElement(i, arr[i]);
                    i++;
                }
            }
            break;
        }
        
    } while (choice != 0);
}

void printElements(){
    printf("< ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf(">\n");
}

void deleteElement(int index) {
    for (int i = index; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
}

void insertElement(int index, int elem) {
    for (int i = n; i > index; i--) {
        arr[i] = arr[i - 1];
    }
    n++;
    arr[index] = elem;
}

void arrInput() {
    printf("n = ");
    scanf_s("%d", &n);

    printf("Введите %d значений -> ", n);
    for (int i = 0; i < n; i++) {
        scanf_s("%d", &arr[i]);
    }
}

void odds10() {
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 != 0) {
            arr[i] *= 10;
        }
    }
}

int morethan10() {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > 10) {
            count++;
        }
    }
    return count;
}

int findFirstEven() {
    int res = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            res = i;
            return res;
        }
    }
    return -1;
}

int findLastEven() {
    int res = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            res = i;
        }
    }
    return res;
}

int min() {
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] < arr[res]) {
            res = i;
        }
    }
    return res;
}

int max() {
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > arr[res]) {
            res = i;
        }
    }
    return res;
}
