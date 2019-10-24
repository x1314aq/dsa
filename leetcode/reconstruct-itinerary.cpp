/**
 * Leetcode 332 Reconstruct Itinerary
 * brutal DFS
 */

#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
	map<string, multiset<string>> targets;
	vector<string> route;

	vector<string> findItinerary(vector<pair<string, string>> tickets) {
		for (auto ticket : tickets)
			targets[ticket.first].insert(ticket.second);
		visit("JFK");
		return vector<string>(route.rbegin(), route.rend());
	}

	void visit(string airport) {
		while (targets[airport].size()) {
			string next = *targets[airport].begin();
			targets[airport].erase(targets[airport].begin());
			visit(next);
		}
		route.push_back(airport);
	}
};

int main()
{
    return 0;
}
