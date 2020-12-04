#include<iostream>
#include<queue>
#include <string>

#define SIZE 4

struct pcb{
    std::string process_name;
    int arrival_time;
    int cpu_burst_time;
};


 struct compareBurstTime { 
    int operator()(const pcb& a,  const pcb& b) 
    { 
        return a.cpu_burst_time > b.cpu_burst_time; 
    } 
} ; 

void insertProcess_SJF(pcb *arr){
    // Used to sort the processes 
    // according to arrival time 
    int index = 0; 
    for (int i = 0; i < SIZE - 1; i++) { 
        index = i; 
        for (int j = i + 1; j < SIZE; j++) { 
            if (arr[j].arrival_time 
                < arr[index].arrival_time) { 
                index = j; 
            } 
        } 
        std::swap(arr[i], arr[index]); 
    } 

    int current_time = arr[0].arrival_time; 
    std::priority_queue <pcb, std::vector<pcb>,compareBurstTime> wait;
    int temp = arr[0].arrival_time; 
  
    // The first process is 
    // pushed in the wait queue. 
    wait.push(arr[0]); 
    arr[0].arrival_time = -1; 
  
    std::cout << "Process id"
         << "\t"; 
    std::cout << "Arrival time"
         << "\t"; 
    std::cout << "Burst time"
         << "\t"; 
  
    std::cout << std::endl;

    while (!wait.empty()){
        std::cout << "\t"; 
        std::cout << wait.top().process_name << "\t\t\t"; 
        std::cout << wait.top().arrival_time << "\t\t\t"; 
        std::cout << wait.top().cpu_burst_time << "\t\t"; 
        std::cout << std::endl; 
        current_time += wait.top().cpu_burst_time; 
        wait.pop();
        for (int i=0;i<SIZE;i++){
            if(arr[i].arrival_time<=current_time && arr[i].arrival_time!=-1){
                wait.push(arr[i]);
                arr[i].arrival_time=-1;
            }
        }
    } 

}
int main(){
    pcb arr[SIZE];
    arr[0] = { "p1", 4, 3 }; 
    arr[1] = { "p2", 0, 8 }; 
    arr[2] = { "p3", 5, 4 }; 
    arr[3] = { "p4", 5, 2 }; 
    std::cout << "Process scheduling "; 
    std::cout << "according to SJF is: \n"<< std::endl; 
    insertProcess_SJF(arr);
    return 0;
}