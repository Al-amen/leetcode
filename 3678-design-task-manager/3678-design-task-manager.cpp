class TaskManager {
    using int2=pair<int , int>; 
    int2 mp[100001];// taskID->(prioity, userId)
    priority_queue<int2> pq; //(priority, taskID)
public:
    TaskManager(vector<vector<int>>& tasks) {
        fill(mp, mp+100001, make_pair(-1, -1));
        for(auto& t: tasks){
            int  u=t[0], i=t[1], p=t[2];
            mp[i]={p, u};
            pq.emplace(p, i);
        }
    }
    
    void add(int userId, int taskId, int priority) {
        mp[taskId]={priority, userId};
        pq.emplace(priority, taskId);
    }
    
    void edit(int taskId, int newPriority) {
        mp[taskId].first=newPriority;
        pq.emplace(newPriority, taskId);
    }
    
    void rmv(int taskId) {
        mp[taskId].first=-1;
    }
    
    int execTop() {
        while (!pq.empty()) {
            auto [p, i] = pq.top();
            if (mp[i].first == p) {
                pq.pop();
                int u=mp[i].second;
                mp[i]={-1, -1}; // Remove task after execution
                return u;
            }
            pq.pop(); // Remove
        }
        return -1; // No valid tasks to execute
        
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