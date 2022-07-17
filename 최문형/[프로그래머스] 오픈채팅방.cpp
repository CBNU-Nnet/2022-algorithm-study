#include <sstream>
#include <string>
#include <vector>
#include <map>

using namespace std;


// order배열 [명령어, UID] -> map<uid, nickname>
vector<string> solution(vector<string> record) {

	map<string, string> uid_to_name;
	vector<pair<int, string>> orders;
	for (auto i : record) {
		string cmd[3];

		istringstream sstream(i);
		sstream >> cmd[0];

		if (cmd[0] == "Enter") {
			sstream >> cmd[1] >> cmd[2];

			uid_to_name[cmd[1]] = cmd[2];
			orders.push_back({ 0, cmd[1] });
		}
		// Leave
		else if (cmd[0] == "Leave") {
			sstream >> cmd[1];

			orders.push_back({ 1, cmd[1] });
		}
		// change 
		else {
			sstream >> cmd[1] >> cmd[2];
			uid_to_name[cmd[1]] = cmd[2];
		}
	}


	vector<string> answer;

	for (auto order : orders) {
		if (order.first == 0) {
			answer.push_back(uid_to_name[order.second] + "님이 들어왔습니다.");
		}
		else {
			answer.push_back(uid_to_name[order.second] + "님이 나갔습니다.");
		}
	}

	return answer;
}
