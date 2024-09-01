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
  

# Skills Demonstrated
## Data Structures and Algorithms (DSA)

* Manages user information efficiently through the use of unordered_map for fast lookups and stacks for organizing message threads.
* Incorporates algorithms for password creation and verification.
  
## Object-Oriented Programming (OOP)

* Class Design: Utilizes classes to encapsulate both data and behavior, ensuring modularity and code reuse.
* Inheritance: Employs inheritance to expand the functionality of existing classes.

## Database Concepts

* Data Management: Emulates database functionalities using unordered_map to handle user accounts and messaging.
* Data Persistence: Simulates data persistence through the use of data structures.

## System Architecture

* Scalability: Manages user interactions efficiently by leveraging data structures optimized for quick operations.
* Modularity: Each functionality is separated into distinct classes, which enhances system maintainability and future expansion.
   
## Learning Outcomes
* DSA in Practice: Demonstrates effective use of stacks for managing chat histories.
* OOP Fundamentals: Showcases the application of encapsulation, inheritance, and potentially polymorphism in class design.
* Database Simulation: Utilizes unordered_map to replicate key database operations.
* System Architecture: Designs a scalable and modular framework for social networking features.
  
## Conclusion

InstaClone adeptly brings together essential features found in Instagram, integrating DSA, OOP, database simulation, and system design principles. This project offers developers practical experience in building complex social media applications, equipping them with the skills needed to tackle more advanced software development tasks.
