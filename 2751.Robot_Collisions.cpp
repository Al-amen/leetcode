class Solution {
public:
    struct Robot {
        int index;
        int position;
        int health;
        char direction;

    };

    void handleCollisions(stack<Robot>& st, Robot & robot) {
        while(!st.empty() && st.top().direction == 'R' && st.top().health<robot.health){
            st.pop();
            robot.health--;
        }
        if(!st.empty() && st.top().direction == 'R') {
            if(st.top().health == robot.health) {
                st.pop();
            }
            else {
                st.top().health--;
            }
        }
        else {
            st.push(robot);
        }
    }
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {

        int n = positions.size();
        vector<Robot>robots;

        for(int i = 0; i <n; i++) {
            robots.push_back({i,positions[i], healths[i],directions[i]});

        }

        sort(robots.begin(), robots.end(),[](const auto &a, const auto &b){
             return a.position < b.position;
        });

        stack<Robot>st;

        for(Robot& robot: robots) {
            if(robot.direction == 'R') {
                st.push(robot);
            }
            else {
                handleCollisions(st,robot);
            }
        }
        robots.clear();

        while(!st.empty()) {
            robots.push_back(st.top());
            st.pop();
        }

        sort(robots.begin(),robots.end(), [](const auto &a , const auto &b){
            return a.index < b.index;
        });

        vector<int>ans;

        for(Robot robot : robots) {
            ans.push_back(robot.health);
        }

        return ans;
           
        




        
    }
};