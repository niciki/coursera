#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;
/*
// Перечислимый тип для статуса задачи
enum class TaskStatus {
  NEW,          // новая
  IN_PROGRESS,  // в разработке
  TESTING,      // на тестировании
  DONE          // завершена
};

// Объявляем тип-синоним для map<TaskStatus, int>,
// позволяющего хранить количество задач каждого статуса
using TasksInfo = map<TaskStatus, int>;
*/
class TeamTasks {
public:
    // Получить статистику по статусам задач конкретного разработчика
    const TasksInfo& GetPersonTasksInfo(const string& person) const {
        return data.at(person);
    }

    // Добавить новую задачу (в статусе NEW) для конкретного разработчитка
    void AddNewTask(const string& person) {
        ++data[person][TaskStatus::NEW];
    }

    // Обновить статусы по данному количеству задач конкретного разработчика,
    // подробности см. ниже
    tuple<TasksInfo, TasksInfo> delete_zeros(tuple<TasksInfo, TasksInfo> answ) {
        tuple<TasksInfo, TasksInfo> res;
        for (auto& i: get<0>(answ)) {
            if (i.second != 0) {
                get<0>(res)[i.first] = i.second;
            }
        }
        for (auto& i: get<1>(answ)) {
            if (i.second != 0) {
                get<1>(res)[i.first] = i.second;
            }
        }
        return res;
    }

    void NoZero(TasksInfo& tasks) {
        for(auto it = tasks.begin(); it!=tasks.end();){
            if(it->second == 0){
                it = tasks.erase(it);
            } else {
                ++it;
            }
        }
    }

    tuple<TasksInfo, TasksInfo> PerformPersonTasks(
        const string& person, int task_count) {
            if (!data.count(person)) {
                return {};
            }
            tuple<TasksInfo, TasksInfo> answ;
            get<1>(answ) = data[person];
            get<1>(answ).erase(TaskStatus::DONE);
            if (task_count > get<1>(answ)[TaskStatus::NEW]) {
                task_count -= get<1>(answ)[TaskStatus::NEW];
                get<0>(answ)[TaskStatus::IN_PROGRESS] += get<1>(answ)[TaskStatus::NEW];
                data[person][TaskStatus::IN_PROGRESS] += get<1>(answ)[TaskStatus::NEW];
                get<1>(answ).erase(TaskStatus::NEW);
                data[person].erase(TaskStatus::NEW);
            } else {
                get<0>(answ)[TaskStatus::IN_PROGRESS] = task_count;
                data[person][TaskStatus::IN_PROGRESS] += task_count;
                data[person][TaskStatus::NEW] -= task_count;
                get<1>(answ)[TaskStatus::NEW] -= task_count;
                return delete_zeros(answ);
            }
            if (task_count > get<1>(answ)[TaskStatus::IN_PROGRESS]) {
                task_count -= get<1>(answ)[TaskStatus::IN_PROGRESS];
                get<0>(answ)[TaskStatus::TESTING] += get<1>(answ)[TaskStatus::IN_PROGRESS];
                data[person][TaskStatus::TESTING] += get<1>(answ)[TaskStatus::IN_PROGRESS];
                get<1>(answ).erase(TaskStatus::IN_PROGRESS);
                data[person].erase(TaskStatus::IN_PROGRESS);
            } else {
                get<0>(answ)[TaskStatus::TESTING] = task_count;
                data[person][TaskStatus::TESTING] += task_count;
                data[person][TaskStatus::IN_PROGRESS] -= task_count;
                get<1>(answ)[TaskStatus::IN_PROGRESS] -= task_count;
                return delete_zeros(answ);
            }

            if (task_count > get<1>(answ)[TaskStatus::TESTING]) {
                task_count -= get<1>(answ)[TaskStatus::TESTING];
                get<0>(answ)[TaskStatus::DONE] += get<1>(answ)[TaskStatus::TESTING];
                data[person][TaskStatus::DONE] += get<1>(answ)[TaskStatus::TESTING];
                get<1>(answ).erase(TaskStatus::TESTING);
                data[person].erase(TaskStatus::TESTING);
            } else {
                get<0>(answ)[TaskStatus::DONE] = task_count;
                data[person][TaskStatus::DONE] += task_count;
                data[person][TaskStatus::TESTING] -= task_count;
                get<1>(answ)[TaskStatus::TESTING] -= task_count;
                return delete_zeros(answ);
            }
            return delete_zeros(answ);
        }
private:
    map<string, TasksInfo> data;
};

/*
// Принимаем словарь по значению, чтобы иметь возможность
// обращаться к отсутствующим ключам с помощью [] и получать 0,
// не меняя при этом исходный словарь
void PrintTasksInfo(TasksInfo tasks_info) {
    cout << tasks_info[TaskStatus::NEW] << " new tasks" <<
        ", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
        ", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested" <<
        ", " << tasks_info[TaskStatus::DONE] << " tasks are done" << endl;
}

int main() {
    TeamTasks tasks;
    tasks.AddNewTask("Ilia");
    for (int i = 0; i < 3; ++i) {
        tasks.AddNewTask("Ivan");
    }
    cout << "Ilia's tasks: ";
    PrintTasksInfo(tasks.GetPersonTasksInfo("Ilia"));
    cout << "Ivan's tasks: ";
    PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));

    TasksInfo updated_tasks, untouched_tasks;

    tie(updated_tasks, untouched_tasks) =
        tasks.PerformPersonTasks("Ivan", 2);
    cout << "Updated Ivan's tasks: ";
    PrintTasksInfo(updated_tasks);
    cout << "Untouched Ivan's tasks: ";
    PrintTasksInfo(untouched_tasks);

    tie(updated_tasks, untouched_tasks) =
        tasks.PerformPersonTasks("Ivan", 2);
    cout << "Updated Ivan's tasks: ";
    PrintTasksInfo(updated_tasks);
    cout << "Untouched Ivan's tasks: ";
    PrintTasksInfo(untouched_tasks);

    return 0;
}
*/