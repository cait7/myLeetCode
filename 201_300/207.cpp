class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjanency(numCourses, vector<int>(0));
        vector<int> indegree(numCourses);

        for (int i=0; i<numCourses; i++) {
            indegree[i] = 0;
        }

        for (int i=0; i<prerequisites.size(); i++) {
            vector<int> pair = prerequisites[i];
            adjanency[ pair[0] ].push_back( pair[1] );
            indegree[ pair[1] ] += 1;
        }

        queue<int> q;
        for (int i=0; i<indegree.size(); i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            int ele = q.front();
            q.pop();
            numCourses -= 1;

            for (int i=0; i<adjanency[ele].size(); i++) {
                indegree[ adjanency[ele][i] ] -= 1;

                if (indegree[ adjanency[ele][i] ] == 0) {
                    q.push(adjanency[ele][i]);
                }
            }

        }

        return numCourses == 0;
    }
};
