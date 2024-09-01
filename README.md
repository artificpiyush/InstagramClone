# InstagramClone

InstaClone is an social networking prototype inspired by Instagram, offering a range of features such as user account management, social interaction tools, messaging, and content sharing.

# Key Features

## User Management

* User Class: Oversees user accounts with distinct email addresses, passwords, and IDs.
* Account Registration: Ensures email and user ID uniqueness using unordered_map for rapid validation.
* Account Deletion: Allows users to permanently remove their accounts after password confirmation.
* Profile Management: Enables users to update their bio and profile picture.

## Social Networking

* Followers and Following: Users have the ability to follow or unfollow others, with accessible lists of their followers and the people they follow.
* Friend Class: Extends the User class, allowing users to view their friends' profile details, posts, and their network of followers and followings.


## Messaging
* Message Exchange: Users can send messages to one another, managed via a stack structure for easy access and conversation management.

## Content Sharing

* Post Class: Models a user’s post, containing an image link and caption.
* Feed Management: Automatically updates followers’ feeds with new photos posted by users.
