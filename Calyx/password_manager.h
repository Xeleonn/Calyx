#ifndef PASSWORD_MANAGER_H
#define PASSWORD_MANAGER_H

class Password
{
public:
	Password();

	const char* InputNewPassword(const char password);
	const char* EncryptPassword();
};

#endif