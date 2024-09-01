// #include<iostream>
// #include<string>
// #include <vector>
// #include <unordered_map>
// #include <stack>
// #include <queue>
// #include <map>
// #include <algorithm>
// #include <random>
// using namespace std;


// unordered_map<string, vector<string>> UserData;
// unordered_map<string, bool> mailIds;
// unordered_map<string, bool> userIds;
// unordered_map<string, unordered_map<string, stack<string>>> messagesData;


// string generatePassword(int length = 8) {
//     const string upperCaseLetters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
//     const string lowerCaseLetters = "abcdefghijklmnopqrstuvwxyz";
//     const string digits = "0123456789";
//     const string specialChars = "!@#$%^&*()-_=+[]{}|;:,.<>?";
    
//     if (length < 8) {
//         length = 8; // Ensure the minimum length is 8
//     }

//     vector<char> password;

//     // Ensure at least one character from each category is included
//     password.push_back(upperCaseLetters[rand() % upperCaseLetters.size()]);
//     password.push_back(lowerCaseLetters[rand() % lowerCaseLetters.size()]);
//     password.push_back(digits[rand() % digits.size()]);
//     password.push_back(specialChars[rand() % specialChars.size()]);

//     // Fill the remaining length of the password with random characters from all categories
//     const string allChars = upperCaseLetters + lowerCaseLetters + digits + specialChars;
//     for (int i = 4; i < length; ++i) {
//         password.push_back(allChars[rand() % allChars.size()]);
//     }

//     // Set up a random number generator
//     random_device rd;
//     mt19937 g(rd()); // Instance of a randim number generator

//     // Shuffle the password to avoid a predictable pattern
//     shuffle(password.begin(), password.end(),g);

//     return string(password.begin(), password.end());
// }



// bool validPassword(string& password)
// {
//     if (password.length() < 8) {
//         return false; // Password length should be at least 8 characters
//     }

//     bool hasUpperCase = false;
//     bool hasLowerCase = false;
//     bool hasDigit = false;
//     bool hasSpecialChar = false;

//     for (char ch : password) {
//         if (isupper(ch)) {
//             hasUpperCase = true;
//         } else if (islower(ch)) {
//             hasLowerCase = true;
//         } else if (isdigit(ch)) {
//             hasDigit = true;
//         } else if (ispunct(ch)) { // Check for special characters
//             hasSpecialChar = true;
//         }
//     }

//     // Check if all required conditions are met
//     return hasUpperCase && hasLowerCase && hasDigit && hasSpecialChar;
// }



// class Post {
// public:
//     string imgUrl;
//     string caption;

//     Post(string imgUrl, string caption = "") {
//         this->imgUrl = imgUrl;
//         this->caption = caption;
//     }
// };




// class MyFeed {
// private:
//     vector<Post> feed;

// public:
//     void addToFeed(const Post& post) {
//         feed.push_back(post);
//     }

//     void viewMyFeed() {
//         cout << "My Feed:" << endl;
//         for (auto& post : feed) {
//             cout << post.imgUrl << " - " << post.caption << endl;
//         }
//     }
// };



// class User {
// protected:
//     string mailId;
//     string password;

// public:
//     string userId;
//     string bio;
//     vector<string> posts;
//     vector<User*> following;
//     vector<User*> followers;
//     string  profilePicture ;

//     void createAccount(string mailId) {
//         while (mailIds[mailId]) {
//             cout << "This Mail Id Already Exists. Enter a new one: " << endl;
//             cin >> mailId;
//         }
//         mailIds[mailId] = true;

      
//         cout << "Do you want an auto-generated password? (y/n): ";
//         char choice;
//         cin >> choice;

//         if (tolower(choice) == 'y') {
//             password = generatePassword();
//             cout << "Generated Password: " << password << endl;
//         } else {
//             cout << "Enter Your Password: " << endl;
//             cin >> password;
//             while (!validPassword(password)) {
//                 cout << "Enter a Stronger Password: " << endl;
//                 cin >> password;
//             }
//         }

        
//         cout << "Enter User ID: " << endl;
//         string newUserId;
//         cin >> newUserId;
//         while (userIds[newUserId]) {
//             cout << "This User ID Already Exists. Enter a new one: " << endl;
//             cin >> newUserId;
//         }

//         userId = newUserId;
//         this->password = password;
//         this->mailId = mailId;

//         UserData[userId] = { mailId, password, "" };
//     }

//     void deleteAccount(string userId, string password) {
//         string mail;
//         cout << "Enter Your Mail Id: " << endl;
//         cin >> mail;
//         if (UserData[userId][0] == mail && UserData[userId][1] == password) {
//             UserData.erase(userId);
//         } else {
//             cout << "Incorrect password or mail id" << endl;
//         }
//     }

//     void follow(User* userToFollow) {
//         following.push_back(userToFollow);
//         userToFollow->followers.push_back(this);
//     }

//     void unfollow(User* userToUnfollow) {
//         following.erase(remove(following.begin(), following.end(), userToUnfollow), following.end());
//         userToUnfollow->followers.erase(remove(userToUnfollow->followers.begin(), userToUnfollow->followers.end(), this), userToUnfollow->followers.end());
//     }

//     void showMyFollowing() {
//         cout << "Following: ";
//         for (auto& user : following) {
//             cout << user->userId << " ";
//         }
//         cout << endl;
//     }

//     void showMyFollowers() {
//         cout << "Followers: ";
//         for (auto& user : followers) {
//             cout << user->userId << " ";
//         }
//         cout << endl;
//     }

//     void sendMessage(string message, User& receiver) {
//         messagesData[userId][receiver.userId].push(message);
//         messagesData[receiver.userId][userId].push(message);
//     }

//     void postPhoto(string imgUrl, string caption = "") {
//         posts.push_back(imgUrl);

//         // Add this post to all followers' feeds
//         for (auto& follower : followers) {
//             follower->addToFeed(Post(imgUrl, caption));
//         }
//     }

//     void addToFeed(const Post& post) {
//         // To be implemented in MyFeed class
//     }

//     void editProfile(string newBio, string newProfilePicture) {
//         bio = newBio;
//         profilePicture = newProfilePicture;
//         cout << "Profile updated successfully." << endl;
//     }



//     void showPreviousChats(string friendUserId, int n = -1) {
//         if (messagesData[userId].find(friendUserId) == messagesData[userId].end()) {
//             cout << "No previous chats with this user." << endl;
//             return;
//         }

//         stack<string>& chatStack = messagesData[userId][friendUserId];

//         if (n == -1 || n > chatStack.size()) {
//             n = chatStack.size();
//         }

//         vector<string> messages;
//         for (int i = 0; i < n; ++i) {
//             messages.push_back(chatStack.top());
//             chatStack.pop();
//         }

//         // Print messages in reverse order to maintain original sequence
//         for (auto it = messages.rbegin(); it != messages.rend(); ++it) {
//             cout << *it << endl;
//         }

//         // Push messages back to the stack
//         for (const auto& message : messages) {
//             chatStack.push(message);
//         }
//     }
// };

// class Friend : public User {
// public:
//     void viewFriendDetails(User& friendUser) {
//         // Check if the current user is following friendUser
//         auto it = find(friendUser.followers.begin(), friendUser.followers.end(), this);
//         if (it != friendUser.followers.end()) {
//             cout << "UserID: " << friendUser.userId << endl;
//             cout << "Bio: " << friendUser.bio << endl;
//             cout << "Posts: " << endl;
//             for (const auto& post : friendUser.posts) {
//                 cout << post << endl;
//             }
//             cout << "Following: " << friendUser.following.size() << endl;
//             cout << "Followers: " << friendUser.followers.size() << endl;
//         } else {
//             cout << "You are not following this user." << endl;
//         }
//     }
// };

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
