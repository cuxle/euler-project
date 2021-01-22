#include <iostream>
#include <vector>

using namespace std;

struct ScoreNode{
    int redScore = 0;
    int blueScore = 0;
};

bool isCircleFinished(int mode, ScoreNode &node)
{
    if ((node.redScore >= mode || node.blueScore >= mode) \
            && (abs(node.redScore - node.blueScore) >= 2)) {
        return true;
    }
    return false;
}
vector<ScoreNode> vec11;
vector<ScoreNode> vec21;
int main()
{
    string str;
    ScoreNode curNode11;
    ScoreNode curNode21;
    while (cin >> str) {
        for (int i = 0; i < str.size(); i++) {
            // 11 fen zhi
            if (str.at(i) == 'E') {
                vec11.push_back(curNode11);
                vec21.push_back(curNode21);
                goto out;
            }
            char ch = str.at(i);
            if (ch == 'W') {
                curNode11.redScore++;
                curNode21.redScore++;
            } else if (ch == 'L') {
                curNode11.blueScore++;
                curNode21.blueScore++;
            }
            if (isCircleFinished(11, curNode11)) {
                vec11.push_back(curNode11);
                curNode11.redScore = 0;
                curNode11.blueScore = 0;
            }

            if (isCircleFinished(21, curNode21)) {
                vec21.push_back(curNode21);
                curNode21.redScore = 0;
                curNode21.blueScore = 0;
            }




        }
    }
out:
    for (int i = 0; i < vec11.size(); i++) {
        cout << vec11.at(i).redScore << ":" << vec11.at(i).blueScore << endl;
    }
    cout << endl;
    for (int i = 0; i < vec21.size(); i++) {
        cout << vec21.at(i).redScore << ":" << vec21.at(i).blueScore << endl;
    }
    return 0;
}
