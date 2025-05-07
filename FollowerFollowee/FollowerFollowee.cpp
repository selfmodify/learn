// FollowerFollowee.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

typedef int UserId;

struct FollowerData {
};

struct FolloweeData {
};

map<UserId, map<int, vector<string>>> inboxes;
map<UserId, map<UserId, FollowerData>> followers;  // whom am I following
map<UserId, map<UserId, FolloweeData>> following; // Users following me

bool follow(UserId me, UserId other) {
    if (following.count(me) > 0 && following[me].count(other) > 0) {
        return false;
    }
    following[me][other] = FolloweeData();
    followers[other][me] = FollowerData();
    std::cout << "me: " << me << " +++ Following +++ " << "Other: " << other;
    return true;
}

bool unfollow(UserId me, UserId other) {
    if (following.count(me) == 0 || following[me].count(other) == 0) {
        return false;
    }
    following[me].erase(other);
    followers[other].erase(me);
    std::cout << "me: " << me << " ---- UnFollowing --- " << "Other: " << other;
    return true;

}

void tweet(UserId me, int tweet_id, const std::string& data) {
    for (const auto& kv : followers[me]) {
        inboxes[kv.first][tweet_id].push_back(data);
    }
}

void show_my_feed(UserId me) {
    cout << "Feeds:\n";
    for (const auto& entry : inboxes[me]) {
        for (const auto& tweet : entry.second) {
            std::cout << "\nTweet: " << entry.first << " " << tweet; //. << " " << tweet.second;
        }
    }
}

int FollowerFollowee_main()
{
    UserId me = 1;
    UserId other = 5;
    UserId gaga = 13;
    std::cout << "\n" << follow(me, other);
    std::cout << "\n" << follow(me, other);
    std::cout << "\n" << unfollow(me, other);
    std::cout << "\n" << follow(me, other);
    std::cout << "\n" << follow(me, gaga);
    std::cout << "\n" << follow(other, gaga);
    tweet(gaga, 77, "Hello!!!!");
    show_my_feed(me);
    show_my_feed(other);
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
