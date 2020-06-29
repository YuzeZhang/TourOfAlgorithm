//
// Created by Zeno on 2020/6/29.
//

bool isPathCrossing(string path) {
    map<pair<int, int>, int> mp;
    int size = path.length();
    pair<int, int> curLocation = make_pair(0, 0);
    mp[curLocation]++;
    for (int i = 0; i < size; i++) {
        if (path[i] == 'N') {
            curLocation.second++;
        } else if (path[i] == 'S') {
            curLocation.second--;
        } else if (path[i] == 'E') {
            curLocation.first++;
        } else if (path[i] == 'W') {
            curLocation.first--;
        }
        if (mp[curLocation] != 0) {
            return true;
        } else {
            mp[curLocation]++;
        }
    }
    return false;
}