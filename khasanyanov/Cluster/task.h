#ifndef __TASK_H__
#define __TASK_H__

#include"queue.h"
#include <ctime>

const size_t MaxTactsOfTask = 6;

using namespace std;

class Task {							
	size_t number, 						// номер задачи
	tacts, 								// кол-во тактов для выполнения
	nodes;								// кол-во занимаемых узлов
	bool closed;						// состояние задачи
public:									
	Task();								// конструктор по умолчанию
	Task(size_t Nodes);					// конструктор-инициализатор
	void work();						// отработка задачи за один такт
	bool is_closed() const noexcept;	// выполнена ли задача
	                                    // геттеры
	size_t get_nodes() const noexcept;	
	size_t get_tacts() const noexcept;	
	size_t get_number() const noexcept; 
};

#endif
