#include <iostream>
#include <thread>
#include <cstdio>
#include <pthread.h>
#include <vector>
#include <string>
#include <signal.h>
#include <unistd.h>
#include <semaphore.h>
#include <algorithm>
#include <list>



void printLines() {
    for (int i = 1; i <= 10; ++i) {
        printf("Line %d from thread\n", i);
    }
}

void* printLines2(void*) {
    for (int i = 1; i <= 10; ++i) {
        printf("Line %d from thread\n", i);
    }
    return nullptr;
}

void* printLine3(void*) {
    for (int i = 1; i <= 10; ++i) {
        printf("Line %d from thread\n", i);
    }
    return nullptr;
}

void printLines4(const std::vector<std::string>& lines) {
    for (const std::string& line : lines) {
        std::cout << line << std::endl;
    }
}

void* threadFunction(void* arg) {
    int localVariable = 42;
    printf("Thread address: %p, Local variable address: %p\n", (void*)pthread_self(), (void*)&localVariable);
    return NULL;
}

static pthread_t childThread;


void sigintHandler(int signal) {
    std::cout << "Child thread received signal SIGINT with thread ID: " << pthread_self() << std::endl;
}
void* childThreadFunction(void* arg) {
    signal(SIGINT, sigintHandler);
    while (1) {
        sleep(1);
    }
    return NULL;
}

void* childThreadFunction2(void* arg) {
    sleep(2);
    std::cout << "Child thread is running..." << std::endl;
    while (1) {
        sleep(1);
    }
    return NULL;
}


static pthread_t childThread3;
void cleanupHandler(void* arg) {
    std::cout << "Child thread is cleaning up..." << std::endl;
}

void* childThreadFunction3(void* arg) {
    sleep(2);
    std::cout << "Child thread is running..." << std::endl;
    pthread_cleanup_push(cleanupHandler, NULL);
        while (1) {
            sleep(1);
        }
    pthread_cleanup_pop(1);

    return NULL;
}

pthread_mutex_t mutex;
void printLines10() {
    for (int i = 1; i <= 10; ++i) {
        pthread_mutex_lock(&mutex);
        printf("Line %d from thread\n", i);
        pthread_mutex_unlock(&mutex);
    }
}

pthread_mutex_t printMutex;
pthread_cond_t condition;
bool childReady = false;
void printLines12() {
    for (int i = 1; i <= 10; ++i) {
        pthread_mutex_lock(&printMutex);
        while (!childReady) {
            pthread_cond_wait(&condition, &printMutex);
        }
        printf("Line %d from thread\n", i);
        childReady = false;
        pthread_cond_signal(&condition);
        pthread_mutex_unlock(&printMutex);
    }
}

sem_t readySemaphore;
sem_t printSemaphore;

void printLines13() {
    for (int i = 1; i <= 10; ++i) {
        sem_wait(&readySemaphore);
        printf("Line %d from thread\n", i);
        sem_post(&printSemaphore);
    }
}
std::list<std::string> stringList;
std::mutex mtx;
void parentThread15() {
    while (true) {
        std::string input;
        std::cout << "Введите строку (или нажмите Enter чтобы вывести отсортированную строку): ";
        std::getline(std::cin, input);

        if (input.empty()) {
            std::lock_guard<std::mutex> lock(mtx);
            std::cout << "Отсортированный список: " << std::endl;
            for (const std::string& str : stringList) {
                std::cout << str << std::endl;
            }
        } else {
            std::lock_guard<std::mutex> lock(mtx);
            while (input.length() > 80) {
                stringList.push_back(input.substr(0, 80));
                input = input.substr(80);
            }
            stringList.push_back(input);
        }
    }
}
void bubbleSort() {
    while (true) {
        {
            std::this_thread::sleep_for(std::chrono::seconds(5));
            std::lock_guard<std::mutex> lock(mtx);
            stringList.sort();
        }
    }
}


void n1() {
    setvbuf(stdout, NULL, _IONBF, 0);
    std::thread myThread(printLines);
    for (int i = 1; i <= 10; ++i) {
        printf("Нити %d из main\n", i);
    }
    myThread.join();
}
void n2() {
    setvbuf(stdout, NULL, _IONBF, 0);
    pthread_t myThread;
    if (pthread_create(&myThread, NULL, printLines2, NULL) != 0) {
        std::cerr << "Не удалось создать поток" << std::endl;
        return;
    }
    if (pthread_join(myThread, nullptr) != 0) {
        std::cerr << "Не удалось создать поток" << std::endl;
        return;
    }

    for (int i = 1; i <= 10; ++i) {
        printf("Нить %d из main\n", i);
    }
}

void n3() {
    setvbuf(stdout, NULL, _IONBF, 0);
    pthread_t myThread;
    if (pthread_create(&myThread, NULL, printLine3, NULL) != 0) {
        std::cerr << "Не удалось создать поток" << std::endl;
        return;
    }

    if (pthread_join(myThread, nullptr) != 0) {
        std::cerr << "Не удалось создать поток" << std::endl;
        return;
    }

    for (int i = 1; i <= 10; ++i) {
        printf("Нить %d из main\n", i);
    }
}

void n5() {
    pthread_t thread1, thread2;

    if (pthread_create(&thread1, NULL, threadFunction, NULL) != 0) {
        std::cerr << "Не удалось создать поток 1" << std::endl;
        return;
    }

    if (pthread_create(&thread2, NULL, threadFunction, NULL) != 0) {
        std::cerr << "Не удалось создать поток 2" << std::endl;
        return;
    }

    if (pthread_join(thread1, NULL) != 0) {
        std::cerr << "Не удалось создать поток 1" << std::endl;
        return;
    }

    if (pthread_join(thread2, NULL) != 0) {
        std::cerr << "Не удалось создать поток 2" << std::endl;
        return;
    }
}

void n6() {
    pthread_t thread;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    struct sched_param param;
    param.sched_priority = 10;
    pthread_attr_setschedpolicy(&attr, SCHED_FIFO);
    pthread_attr_setschedparam(&attr, &param);

    size_t stackSize = 1024 * 1024;
    void* stack = malloc(stackSize);
    pthread_attr_setstack(&attr, stack, stackSize);
    if (pthread_create(&thread, &attr, threadFunction, NULL) != 0) {
        std::cerr << "Не удалось создать поток" << std::endl;
        return;
    }
    if (pthread_join(thread, NULL) != 0) {
        std::cerr << "Не удалось создать поток" << std::endl;
        return;
    }
    pthread_attr_destroy(&attr);
    free(stack);
}

void n7() {
    if (pthread_create(&childThread, NULL, childThreadFunction, NULL) != 0) {
        std::cerr << "Не удалось создать поток" << std::endl;
        return;
    }
    signal(SIGINT, sigintHandler);
    pthread_kill(childThread, SIGINT);
    if (pthread_join(childThread, NULL) != 0) {
        std::cerr << "Не удалось подключиться к потоку" << std::endl;
        return;
    }
}

void n8() {

    if (pthread_create(&childThread, NULL, childThreadFunction, NULL) != 0) {
        std::cerr << "Не удалось создать child потока" << std::endl;
        return;
    }
    sleep(2);
    pthread_cancel(childThread);

    if (pthread_join(childThread, NULL) != 0) {
        std::cerr << "Не удалось подключить child потока" << std::endl;
        return;
    }
}

void n9() {
    if (pthread_create(&childThread3, NULL, childThreadFunction3, NULL) != 0) {
        std::cerr << "Не удалось создать child потока" << std::endl;
        return;
    }
    if (pthread_join(childThread3, NULL) != 0) {
        std::cerr << "Не удалось подключить child потока" << std::endl;
        return;
    }
}

void n10() {
    setvbuf(stdout, NULL, _IONBF, 0);
    pthread_mutex_init(&mutex, NULL);

    std::thread myThread(printLines);
    for (int i = 1; i <= 10; ++i) {
        pthread_mutex_lock(&mutex);
        printf("Нить %d из main\n", i);
        pthread_mutex_unlock(&mutex);
    }

    myThread.join();

    pthread_mutex_destroy(&mutex);
}

void n12() {

    pthread_mutex_init(&mutex, NULL);
    pthread_mutex_init(&printMutex, NULL);
    pthread_cond_init(&condition, NULL);
    std::thread myThread(printLines12);

    for (int i = 1; i <= 10; ++i) {

        pthread_mutex_lock(&mutex);
        childReady = true;
        pthread_cond_signal(&condition);
        while (childReady) {
            pthread_cond_wait(&condition, &mutex);
        }
        pthread_mutex_unlock(&mutex);
    }

    myThread.join();

    pthread_mutex_destroy(&mutex);
    pthread_mutex_destroy(&printMutex);
    pthread_cond_destroy(&condition);
}

void n13() {

    sem_init(&readySemaphore, 0, 0);
    sem_init(&printSemaphore, 0, 0);

    std::thread myThread(printLines13);

    for (int i = 1; i <= 10; ++i) {
        sem_post(&readySemaphore);
        sem_wait(&printSemaphore);
    }

    myThread.join();


    sem_destroy(&readySemaphore);
    sem_destroy(&printSemaphore);
}

void n15() {
    std::thread parent(parentThread15);
    std::thread child(bubbleSort);

    parent.join();
    child.join();
}


int main() {
    //n1();
    //n2();
    //n3();
    //n4();
    //n5();
    //n6();
    //n7();
    //n8();
    //n9();
    //n10();
    //Задача 10, которая требует синхронизации вывода родительской и дочерней нитей,
    //не может быть решена только с использованием двух мьютексов без использования других
    //средств синхронизации. Это связано с тем, что использование только двух мьютексов не
    //обеспечивает необходимой гарантии чередования вывода строк между нитями.
    //n12();
    //n13();
//    Cемафоры-счетчики не могут быть применены для решения задачи n10,
//    так как они не обеспечивают нужную синхронизацию вывода родительской и дочерней нитей.
//    Семафоры-счетчики позволяют управлять доступом к ресурсам в конкурентной среде, но они
//    не предоставляют средств для координации последовательности выполнения действий между нитями.
    //n15();
    return 0;
}
