#pragma once
#include "Task.h"
#include <string>

using namespace std;


class cluster_interface {

public:
	cluster_interface();
	/** @param label сктрока для вывода.
		@param x координата x.
		@param y координата y. */
	void label(string label, int x, int y);
	/** @param newTask выполняемая задача.
		@param x координата x.
		@param y координата y. */
	void drawProcess(task newTask, int x, int y);
	/* Отрисовка поля. */
	void drawField();
};