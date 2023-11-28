#pragma once


class task {

public:
	/** @param taktsLimit предел генерации тактов.
		@param nodesLimit предел генерации узлов. */
	task(int taktsLimit, int nodesLimit);

	/* Возращает true, если задача отработала такт и false, если задача завершила свою работу. */
	bool runTaсt();
	/* Возращает количество потребляемых задачей узлов. */
	int getNodes() const;
	/* Возращает количество потребляемых задачей тактов. */
	int getTaсts() const;
	/* Возращает номер задачи. */
	int getId() const;

private:
	int taсts, nodes;
	static int nextId; // Статическая переменная для хранения следующего id.
	int id; // Переменная для хранения id текущего объекта.
};