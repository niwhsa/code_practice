#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
    public:
    int numBusesToDestination(vector<vector<int>>& routes, int src, int target) {

        unordered_map<int, unordered_set<int>> graph;  //stop_to_routes

        //1. Build graph
        for (size_t i = 0; i < size(routes); ++i) {
            for (size_t j = 0; j < size(routes[i]); ++j) {
                auto stop = routes[i][j];
                graph[stop].emplace(i);
            }
        }

        //2. BFS - min # of Buses from src to target
        queue<int> q;
        unordered_set<int> visitedRoutes;
        
        int leastBuses = 0;
        q.emplace(src);

        while (!empty(q)) {
            auto szQ = size(q);
            for (size_t i = 0; i < szQ; ++i) {
                auto curStop = q.front();
                q.pop();

                if (curStop == target) return leastBuses;

                for (auto& nextRoute : graph[curStop]) {
                    if (visitedRoutes.count(nextRoute)) continue;
                    for (auto& nextStop : routes[nextRoute]) {
                        q.emplace(nextStop);
                    }
                    visitedRoutes.emplace(nextRoute);
                }
            }
            ++leastBuses;
        }

        return -1; //target unreachable with existing routes

    }
};
