class TaskManager {
public:

    unordered_map<int , pair<int , int>> taskInfo;
    set<pair<pair<int , int> , int>> pq;

    TaskManager(vector<vector<int>>& tasks) {
       for(auto &t : tasks){
            int u = t[0], tid = t[1], p = t[2];
            taskInfo[tid] = {u, p};
            pq.insert({{p, tid}, u});
        }
    }
    
    void add(int userId, int taskId, int priority) {
        taskInfo[taskId] = {userId, priority};
        pq.insert({{priority, taskId}, userId});
    }
    
    void edit(int taskId, int newPriority) {
       auto [userId, oldPriority] = taskInfo[taskId];
        pq.erase({{oldPriority, taskId}, userId}); 
        taskInfo[taskId] = {userId, newPriority};
        pq.insert({{newPriority, taskId}, userId});
    }
    
    void rmv(int taskId) {
        auto [userId, priority] = taskInfo[taskId];
        pq.erase({{priority, taskId}, userId});
        taskInfo.erase(taskId);
    }
    
    int execTop() {
        if(pq.empty()) return -1;
        auto it = prev(pq.end());
        int priority = it->first.first;
        int taskId = it->first.second;
        int userId = it->second;
        
        pq.erase(it);
        taskInfo.erase(taskId);
        return userId;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */
