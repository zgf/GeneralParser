#pragma once
#include "stdafx.h"
namespace ztl
{
	class ztl_exception
	{
	public:
		ztl_exception() = delete;
		ztl_exception(const wstring& _message) :message(_message)
		{

		}
	public:
		void What()const
		{
			wcout << message << endl;
		}
	private:
		wstring message;
	};
#ifdef _DEBUG
	template<typename exception_type>
	void AssertThrow(bool result, const exception_type exception)
	{
		if(!result)
		{
			throw exception;
		}
	}
#endif // _DEBUG
	
}