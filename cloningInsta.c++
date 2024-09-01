#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <random>
using namespace std;

unordered_map<string, vector<string>> userAccounts;
unordered_map<string, bool> registeredEmails;
unordered_map<string, bool> registeredUsernames;
unordered_map<string, unordered_map<string, stack<string>>> chatHistory;

string generatePassword(int length = 8) {
    const string uppercaseLetters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const string lowercaseLetters = "abcdefghijklmnopqrstuvwxyz";
    const string numbers = "0123456789";
    const string specialCharacters = "!@#$%^&*()-_=+[]{}|;:,.<>?";

    if (length < 8) {
        length = 8; // Ensure the minimum length is 8
    }

    vector<char> password;

    // Ensure at least one character from each category is included
    password.push_back(uppercaseLetters[rand() % uppercaseLetters.size()]);
    password.push_back(lowercaseLetters[rand() % lowercaseLetters.size()]);
    password.push_back(numbers[rand() % numbers.size()]);
    password.push_back(specialCharacters[rand() % specialCharacters.size()]);

    // Fill the remaining length of the password with random characters from all categories
    const string allCharacters = uppercaseLetters + lowercaseLetters + numbers + specialCharacters;
    for (int i = 4; i < length; ++i) {
        password.push_back(allCharacters[rand() % allCharacters.size()]);
    }

    // Set up a random number generator
    random_device rd;
    mt19937 generator(rd());

    // Shuffle the password to avoid a predictable pattern
    shuffle(password.begin(), password.end(), generator);

    return string(password.begin(), password.end());
}

bool isValidPassword(string& password) {
    if (password.length() < 8) {
        return false; // Password length should be at least 8 characters
    }

    bool hasUppercase = false;
    bool hasLowercase = false;
    bool hasDigit = false;
    bool hasSpecialCharacter = false;

    for (char ch : password) {
        if (isupper(ch)) {
            hasUppercase = true;
        } else if (islower(ch)) {
            hasLowercase = true;
        } else if (isdigit(ch)) {
            hasDigit = true;
        } else if (ispunct(ch)) {
            hasSpecialCharacter = true;
        }
    }

    return hasUppercase && hasLowercase && hasDigit && hasSpecialCharacter;
}

class Post {
public:
    string imageUrl;
    string captionText;

    Post(string imageUrl, string captionText = "") {
        this->imageUrl = imageUrl;
        this->captionText = captionText;
    }
};

class Feed {
private:
    vector<Post> posts;

public:
    void addPostToFeed(const Post& post) {
        posts.push_back(post);
    }

    void viewFeed() {
        cout << "My Feed:" << endl;
        for (auto& post : posts) {
            cout << post.imageUrl << " - " << post.captionText << endl;
        }
    }
};

class User {
protected:
    string email;
    string password;

public:
    string username;
    string bioDescription;
    vector<string> userPosts;
    vector<User*> followingUsers;
    vector<User*> followersList;
    string profileImage;

    void createAccount(string email) {
        while (registeredEmails[email]) {
            cout << "This Email Already Exists. Enter a new one: " << endl;
            cin >> email;
        }
        registeredEmails[email] = true;

        cout << "Do you want an auto-generated password? (y/n): ";
        char choice;
        cin >> choice;

        if (tolower(choice) == 'y') {
            password = generatePassword();
            cout << "Generated Password: " << password << endl;
        } else {
            cout << "Enter Your Password: " << endl;
            cin >> password;
            while (!isValidPassword(password)) {
                cout << "Enter a Stronger Password: " << endl;
                cin >> password;
            }
        }

        cout << "Enter Username: " << endl;
        string newUsername;
        cin >> newUsername;
        while (registeredUsernames[newUsername]) {
            cout << "This Username Already Exists. Enter a new one: " << endl;
            cin >> newUsername;
        }

        username = newUsername;
        password = "newPassword";
        this->email = email;

        userAccounts[username] = { email, password, "" };
    }

    void deleteAccount(string username, string password) {
        string emailInput;
        cout << "Enter Your Email: " << endl;
        cin >> emailInput;
        if (userAccounts[username][0] == emailInput && userAccounts[username][1] == password) {
            userAccounts.erase(username);
        } else {
            cout << "Incorrect password or email" << endl;
        }
    }

    void followUser(User* userToFollow) {
        followingUsers.push_back(userToFollow);
        userToFollow->followersList.push_back(this);
    }

    void unfollowUser(User* userToUnfollow) {
        followingUsers.erase(remove(followingUsers.begin(), followingUsers.end(), userToUnfollow), followingUsers.end());
        userToUnfollow->followersList.erase(remove(userToUnfollow->followersList.begin(), userToUnfollow->followersList.end(), this), userToUnfollow->followersList.end());
    }

    void displayFollowing() {
        cout << "Following: ";
        for (auto& user : followingUsers) {
            cout << user->username << " ";
        }
        cout << endl;
    }

    void displayFollowers() {
        cout << "Followers: ";
        for (auto& user : followersList) {
            cout << user->username << " ";
        }
        cout << endl;
    }

    void sendMessage(string message, User& recipient) {
        chatHistory[username][recipient.username].push(message);
        chatHistory[recipient.username][username].push(message);
    }

    void uploadPhoto(string imageUrl, string captionText = "") {
        userPosts.push_back(imageUrl);

        for (auto& follower : followersList) {
            follower->addPostToFeed(Post(imageUrl, captionText));
        }
    }

    void addPostToFeed(const Post& post) {
        // To be implemented in Feed class
    }

    void updateProfile(string newBio, string newProfileImage) {
        bioDescription = newBio;
        profileImage = newProfileImage;
        cout << "Profile updated successfully." << endl;
    }

    void showChatHistory(string friendUsername, int n = -1) {
        if (chatHistory[username].find(friendUsername) == chatHistory[username].end()) {
            cout << "No previous chats with this user." << endl;
            return;
        }

        stack<string>& conversationStack = chatHistory[username][friendUsername];

        if (n == -1 || n > conversationStack.size()) {
            n = conversationStack.size();
        }

        vector<string> messages;
        for (int i = 0; i < n; ++i) {
            messages.push_back(conversationStack.top());
            conversationStack.pop();
        }

        for (auto it = messages.rbegin(); it != messages.rend(); ++it) {
            cout << *it << endl;
        }

        for (const auto& message : messages) {
            conversationStack.push(message);
        }
    }
};

class Friend : public User {
public:
    void viewFriendDetails(User& friendUser) {
        auto it = find(friendUser.followersList.begin(), friendUser.followersList.end(), this);
        if (it != friendUser.followersList.end()) {
            cout << "Username: " << friendUser.username << endl;
            cout << "Bio: " << friendUser.bioDescription << endl;
            cout << "Posts: " << endl;
            for (const auto& post : friendUser.userPosts) {
                cout << post << endl;
            }
            cout << "Following: " << friendUser.followingUsers.size() << endl;
            cout << "Followers: " << friendUser.followersList.size() << endl;
        } else {
            cout << "You are not following this user." << endl;
        }
    }
};

int main(){
    User user;
    user.createAccount("verma._24");
    return 0;
}
