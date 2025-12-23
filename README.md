# 🔐 User Authentication System

A secure command-line user authentication system built in C with multiple security features including password strength validation, OTP verification, and security question recovery.

## ✨ Features

- **Account Creation** - Create secure user accounts with email and password
- **Login System** - Authenticate users with email/password credentials
- **Strong Password Validation** - Enforces:
  - Minimum 8 characters
  - At least one uppercase letter
  - At least one lowercase letter
  - At least one digit
  - At least one special character
- **Password Recovery** - Two methods:
  - OTP (One-Time Password) verification
  - Security question authentication
- **Change Password** - Secure password update for logged-in users
- **Session Management** - Maintains user login state

## 📁 Project Structure

```
PROJECT CODE/
├── main.c              # Main program entry point and menu system
├── account.c           # Account creation, login, and password management
├── otp.c              # OTP generation and verification
├── password.c         # Password strength validation
├── recovery.c         # Password recovery mechanisms
└── README.md          # Project documentation

## 🚀 Getting Started

### Prerequisites

- GCC compiler (or any C compiler)
- Terminal/Command Prompt

### Compilation

Compile all source files together:

bash
gcc main.c account.c otp.c password.c recovery.c -o auth_system
./auth_system


## 📖 Usage

### Main Menu Options

1. **Create Account**
   - Enter email address
   - Create a strong password
   - Choose a security question (Pet's name, Birth city, or Mother's name)
   - Provide answer to security question

2. **Login**
   - Enter registered email
   - Enter password

3. **Forgot Password**
   - Choose recovery method:
     - **OTP**: System generates a 6-digit OTP (3 attempts allowed)
     - **Security Question**: Answer your security question

4. **Exit**
   - Close the application

### User Menu (After Login)

1. **Change Password**
   - Enter current password
   - Set new strong password

2. **Logout**
   - End current session

## 🔒 Security Features

- **Password Strength Enforcement**: All passwords must meet complexity requirements
- **OTP System**: Time-based one-time password for account recovery
- **Security Questions**: Alternative recovery method for account access
- **Session Management**: Secure login/logout functionality
- **Input Validation**: Protected against invalid inputs

## 💡 Example

```
*** USER AUTHENTICATION SYSTEM ***

--- MENU ---
1. Create Account
2. Login
3. Forgot Password
4. Exit
Choice: 1

=== CREATE ACCOUNT ===
Email: user@example.com
Password: ********
Confirm: ********

Security Question (choose 1, 2, or 3):
1. Pet's name?
2. Birth city?
3. Mother's name?
Choice: 1
Answer: ****

Account created!
```

## 📝 Code Structure

The project uses modular design with:
- Global variables for user session data
- External function declarations for cross-file functionality
- Switch-case statements for menu navigation
- Input validation for robust error handling

## 🤝 Contributing

Contributions are welcome! Please feel free to submit a Pull Request.

1. Fork the project
2. Create your feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

## 📄 License

This project is licensed under the MIT License - see the [LICENSE] file for details.

## 👤 Author

**Kashiika**

## 🙏 Acknowledgments

- Built as a learning project for C programming
- Demonstrates core concepts: modular programming, file handling, and user authentication


⭐ **Star this repository if you find it helpful!**
