#include <vector>
#include <map>
#include <set>

using namespace std;

/* *** Submittable Portion *** */

typedef pair<int, int> ii;

#define REP(i,a,b) for(int i = int(a); i<=int(b); ++i)

class Solution {
public:
	bool dfs(vector<vector<char> > &board, ii cur, set<ii > visited, string word, int position){
		if(position == word.size()-1) return true;

		visited.insert(cur);

		char c = word[position];

		ii check(cur.first, cur.second);

		REP(i,-1,1){
			check.first = cur.first + i;
			REP(j,-1,1){
				check.second = cur.first + j;
				if(board[check.first][check.second] == c){
					if(visited.find(check) == visited.end()){
						if(dfs(board, check, visited, word, position + 1)) return true;
					}
				}
			}
		}

		return false;
	}

    bool exist(vector<vector<char> > &board, string word) {

    	//Build Node Pointers
        map<char, vector<ii> > nodeMap;
        int i(0), j(0);
        for(vector<vector<char> >::iterator it1 = board.begin(); it1 != board.end(); ++it1){
        	for(vector<char>::iterator it2 = (*it1).begin(); it2 != (*it1).end(); ++it2){
        		if(nodeMap.find(*it2) != nodeMap.end()){
        			nodeMap[*it2].push_back(ii(i,j));
        		}
        		j++;
        	}
        	i++;
        	j = 0;
        }

        char init = word[0];

        if(nodeMap.find(init) == nodeMap.end()) return false;
        set<ii > v;
        for(vector<ii >::iterator it = nodeMap[init].begin(); it != nodeMap[init].end(); ++it){
        	if(dfs(board, ii(it->first, it->second), v,  word, 0)) return true;
        }

        return false;
    }
};