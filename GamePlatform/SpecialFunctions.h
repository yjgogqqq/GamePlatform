#pragma once
typedef struct
{
	float fDesPos;							//destination position
	float fMaxDesPos;
	float fPrePos;							//the last destination position
	float fPrePrePos;						//the destination position befor the last destinatio position
	float fMaxAngularVel;					//Max angular velocity
	float fMaxAngularAcc;					//MAX angular acceleration
}MotionParaList;

class CSpecialFunctions
{
public:
	CSpecialFunctions();
	~CSpecialFunctions();

	int GetIntDataFromConfigFile(LPCTSTR lpAppName, LPCTSTR lpKeyName, INT nDefault, LPCTSTR lpFileName);
	DWORD GetStringFromConfigFile(
		_In_  LPCTSTR lpAppName,
		_In_  LPCTSTR lpKeyName,
		_In_  LPCTSTR lpDefault,
		_Out_ LPTSTR  lpReturnedString,
		_In_  DWORD   nSize,
		_In_  LPCTSTR lpFileName
		);

	BOOL WriteStringToConfigFile(LPCTSTR lpAppName, LPCTSTR lpKeyName, LPCTSTR lpString, LPCTSTR lpFileName);
	float fnval(float knots[], float coefs[],float x);
	float LimitVelAndACC(MotionParaList *tspMotionParaList);

	void CharToHex(char *pt);
	float first_order_lag_filter(float input_now, float cal_pre, float k);
};

