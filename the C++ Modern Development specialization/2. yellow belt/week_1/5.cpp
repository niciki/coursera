#include <iostream>
#include <map>
#include <tuple>
#include <sstream>

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


// Принимаем словарь по значению, чтобы иметь возможность
// обращаться к отсутствующим ключам с помощью [] и получать 0,
// не меняя при этом исходный словарь
void PrintTasksInfo(TasksInfo tasks_info) {
  cout << tasks_info[TaskStatus::NEW] << " new tasks" <<
      ", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
      ", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested" <<
      ", " << tasks_info[TaskStatus::DONE] << " tasks are done" << endl;
}
*/

void NoZero(TasksInfo& tasks) {
    for(auto it = tasks.begin(); it!=tasks.end();){
        if(it->second == 0){
            it = tasks.erase(it);
        } else {
            ++it;
        }
    }
}

class TeamTasks {
    public:
        // Получить статистику по статусам задач конкретного разработчика
        const TasksInfo& GetPersonTasksInfo(const string& person) const{
            return info.at(person);
        }
        
        // Добавить новую задачу (в статусе NEW) для конкретного разработчитка
        void AddNewTask(const string& person){
            if(!info[person].count(TaskStatus::NEW)){
                info[person][TaskStatus::NEW] = 1;
            } else {
                info[person][TaskStatus::NEW]++;
            }
        }
        
        // Обновить статусы по данному количеству задач конкретного разработчика,
        // подробности см. ниже
        tuple<TasksInfo, TasksInfo> PerformPersonTasks(const string& person, int task_count){
            TasksInfo done;
            /*done[TaskStatus::NEW] = 0;
            done[TaskStatus::IN_PROGRESS] = 0;
            done[TaskStatus::TESTING] = 0;
            done[TaskStatus::DONE] = 0;*/
            TasksInfo not_done;
            if(!info.count(person)){
                return {done, not_done};
            }
            /*not_done[TaskStatus::NEW] = 0;
            not_done[TaskStatus::IN_PROGRESS] = 0;
            not_done[TaskStatus::TESTING] = 0;*/
            int n = 0, in_progress = 0, testing = 0, d = 0;
            n = info[person][TaskStatus::NEW];
            in_progress = info[person][TaskStatus::IN_PROGRESS];
            testing = info[person][TaskStatus::TESTING];
            d = info[person][TaskStatus::DONE];
            if(task_count >= n && n){
                info[person][TaskStatus::NEW] -= n;
                //info[person].erase(TaskStatus::NEW);
                done[TaskStatus::IN_PROGRESS] = n;
                info[person][TaskStatus::IN_PROGRESS] += n;
                //not_done[TaskStatus::NEW] = 0;
                task_count -= n;
            } else if (task_count > 0 && n){
                info[person][TaskStatus::NEW] -= task_count;
                done[TaskStatus::IN_PROGRESS] = task_count;
                info[person][TaskStatus::IN_PROGRESS] += task_count;
                not_done[TaskStatus::NEW] = n - task_count;
                task_count = 0;
            } else if (task_count == 0 && n){
                not_done[TaskStatus::NEW] = n;
            }
            //PrintTasksInfo(info[person]);
            //cout << task_count << " " << in_progress << "\n";
            if(task_count >= in_progress && task_count > 0 && in_progress){
                info[person][TaskStatus::IN_PROGRESS] -= in_progress;
                //info[person].erase(TaskStatus::IN_PROGRESS);
                done[TaskStatus::TESTING] = in_progress;
                info[person][TaskStatus::TESTING] += in_progress;
                //not_done[TaskStatus::IN_PROGRESS] = 0;
                task_count -= in_progress;
            } else if (task_count > 0 && in_progress){
                info[person][TaskStatus::IN_PROGRESS] -= task_count;
                done[TaskStatus::TESTING] = task_count;
                info[person][TaskStatus::TESTING] += task_count;
                not_done[TaskStatus::IN_PROGRESS] = in_progress - task_count;
                task_count = 0;
            } else if (task_count == 0 && in_progress){
                not_done[TaskStatus::IN_PROGRESS] = in_progress;
            }
            if(task_count >= testing && task_count > 0 && testing){
                info[person][TaskStatus::TESTING] -= testing;
                //info[person].erase(TaskStatus::TESTING);
                done[TaskStatus::DONE] = testing;
                info[person][TaskStatus::DONE] += testing;
                //not_done[TaskStatus::TESTING] = 0;
            } else if (task_count > 0 && testing){
                info[person][TaskStatus::TESTING] -= task_count;
                done[TaskStatus::DONE] = task_count;
                info[person][TaskStatus::DONE] += task_count;
                not_done[TaskStatus::TESTING] = testing - task_count;
            } else if (task_count == 0 && testing){
                not_done[TaskStatus::TESTING] = testing;
            }
            NoZero(done);
            NoZero(not_done);
            NoZero(info[person]);
            return {done, not_done};
        }
private:
    map<string, TasksInfo> info;
};

/*
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

/*
AddNewTasks Alice 5
PerformPersonTasks Alice 5
PerformPersonTasks Alice 5
PerformPersonTasks Alice 1
AddNewTasks Alice 5
PerformPersonTasks Alice 2
GetPersonTasksInfo Alice
PerformPersonTasks Alice 4
GetPersonTasksInfo Alice


int main() {
    TasksInfo updated_tasks, untouched_tasks;
    TeamTasks tasks;
    tasks.AddNewTask("Alice");
    tasks.AddNewTask("Alice");
    tasks.AddNewTask("Alice");
    tasks.AddNewTask("Alice");
    tasks.AddNewTask("Alice");
    tie(updated_tasks, untouched_tasks) =
        tasks.PerformPersonTasks("Alice", 5);
    cout << "Updated Alice's tasks: ";
    PrintTasksInfo(updated_tasks);
    cout << "Untouched Alice's tasks: ";
    PrintTasksInfo(untouched_tasks);


    tie(updated_tasks, untouched_tasks) =
        tasks.PerformPersonTasks("Alice", 5);
    cout << "Updated Alice's tasks: ";
    PrintTasksInfo(updated_tasks);
    cout << "Untouched Alice's tasks: ";
    PrintTasksInfo(untouched_tasks);


    tie(updated_tasks, untouched_tasks) =
        tasks.PerformPersonTasks("Alice", 1);
    cout << "Updated Alice's tasks: ";
    PrintTasksInfo(updated_tasks);
    cout << "Untouched Alice's tasks: ";
    PrintTasksInfo(untouched_tasks);

    tasks.AddNewTask("Alice");
    tasks.AddNewTask("Alice");
    tasks.AddNewTask("Alice");
    tasks.AddNewTask("Alice");
    tasks.AddNewTask("Alice");

    tie(updated_tasks, untouched_tasks) =
        tasks.PerformPersonTasks("Alice", 2);
    cout << "Updated Alice's tasks: ";
    PrintTasksInfo(updated_tasks);
    cout << "Untouched Alice's tasks: ";
    PrintTasksInfo(untouched_tasks);

    PrintTasksInfo(tasks.GetPersonTasksInfo("Alice"));

    tie(updated_tasks, untouched_tasks) =
        tasks.PerformPersonTasks("Alice", 4);
    cout << "Updated Alice's tasks: ";
    PrintTasksInfo(updated_tasks);
    cout << "Untouched Alice's tasks: ";
    PrintTasksInfo(untouched_tasks);

    tie(updated_tasks, untouched_tasks) =
        tasks.PerformPersonTasks("A", 2);
    cout << "Updated A's tasks: ";
    PrintTasksInfo(updated_tasks);
    cout << "Untouched A's tasks: ";
    PrintTasksInfo(untouched_tasks);
}

int main() {
    TasksInfo updated_tasks, untouched_tasks;
    TeamTasks tasks;
    tasks.AddNewTask("Alice");
    tasks.AddNewTask("Alice");
    tasks.AddNewTask("Alice");
    tasks.AddNewTask("Alice");
    tasks.AddNewTask("Alice");
    tie(updated_tasks, untouched_tasks) =
        tasks.PerformPersonTasks("Alice", 50);
    cout << "Updated Alice's tasks: ";
    PrintTasksInfo(updated_tasks);
    cout << "Untouched Alice's tasks: ";
    PrintTasksInfo(untouched_tasks);
}
*/