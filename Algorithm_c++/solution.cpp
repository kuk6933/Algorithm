#include <vector>
#include <utility>
using namespace std;

vector<vector<pair<int,int>>> v(5);

void init()
{
    v.clear();
}

void hire(int mID, int mTeam, int mScore)
{
    v[mTeam-1].push_back(make_pair(mID, mScore));
}

void fire(int mID)
{
    for(int i=0; i<5; i++) {
        for (int j=0; j<v[i].size(); j++) {
            if(v[i][j].first == mID) {
                v[i].erase(v[i].begin() + j);
            }
        }
    }
}

void updateSoldier(int mID, int mScore)
{
    for(int i=0; i<5; i++) {
        for (int j=0; j<v[i].size(); j++) {
            if(v[i][j].first == mID) {
                v[i][j].second = mScore;
            }
        }
    }
}

void updateTeam(int mTeam, int mChangeScore)
{
    for(int i=0; i<v[mTeam].size(); i++){
        v[mTeam][i].second += mChangeScore;
        if(v[mTeam][i].second > 5) {
            v[mTeam][i].second= 5;
        } else if (v[mTeam][i].second < 1) {
            v[mTeam][i].second = 1;
        }
    }
}

int bestSoldier(int mTeam)
{
    int bestScore = 0;
    int Id;
    for(int i=0; i<v[mTeam].size(); i++) {
        if(v[mTeam][i].second > bestScore) {
            bestScore = v[mTeam][i].second;
            Id = v[mTeam][i].first;
        }
    }
    return Id;
}