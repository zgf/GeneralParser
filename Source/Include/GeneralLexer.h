#pragma once
#include "stdafx.h"
#include "ztl_exception.h"

/*!
 * \file GeneralLexer.h
 *
 * \author ZGF
 * \date 十一月 2014
 *这是针对规范的词法分析头文件,也是未来生成文件的词法分析文件模板
 *
 */
namespace ztl
{
	enum class ParserTag
	{
		//TODO这里填充 Lex的Tag
		//可能也会填充Parser的Tag
	};
	struct LexTokenDefine
	{
		wstring name;
		wstring regex;
		bool    ignore;
	};

	struct TokenPosition
	{
		int index;
		int length;
	};
	struct TokenInfo
	{
		ParserTag		tag;
		TokenPosition	position;
		wstring			lex;
	};
	struct FileInfo
	{
		wstring name;
		wstring content;
	};
	class GeneralLexer
	{
	private:/*私有成员*/
		static unordered_map<wstring, ParserTag>						NameToEnumMap;
		vector<FileInfo>												fileInfoList;
		unordered_map<wstring, LexTokenDefine>							lexDefineMap;
		wstring															regex;
		unordered_map<wstring, vector<TokenInfo>>						reusltList;
	private:/*私有API*/

		static unordered_map<wstring, ParserTag> InitNameToEnumMap()
		{
			unordered_map<wstring, ParserTag> result;

			//TODO 这里填充初始化代码

			return result;
		}

		vector<FileInfo> SetFileInfoList(const vector<wstring>& fileNameList)
		{
			vector<FileInfo>	result;
			wifstream			inputHandle;
			for(auto& name : fileNameList)
			{
				inputHandle.open(name);
				AssertThrow(inputHandle.is_open(), ztl_exception(L"Can't find File: " + name));

				FileInfo	    info;
				info.name    = name;
				info.content = GetFileContent(name, inputHandle);
				result.emplace_back(move(info));
			}
			return result;
		}

		wstring GetFileContent(const wstring& name, wifstream& inputHandle)
		{
			istreambuf_iterator<wchar_t> beg(inputHandle);
			istreambuf_iterator<wchar_t> end;
			wstring						 content(beg, end);

			inputHandle.close();
			return content;
		}

		wstring GetRealRegexWString(const unordered_map<wstring, LexTokenDefine>& lexDefineMap)
		{
			vector<wstring> regex_list;
			regex_list.reserve(lexDefineMap.size());

			for(auto& element : lexDefineMap)
			{
				regex_list.emplace_back(L"(<" + element.first + L">" + element.second.regex + L")");
			}

			AssertThrow(!regex_list.empty(), ztl_exception(L"Can't find file!"));
			return accumulate(regex_list.begin() + 1, regex_list.end(), *regex_list.begin(), [](const wstring value, const wstring& first)
			{
				return value + L"|" + first;
			});
		}
	public:	/*公开的API*/
		GeneralLexer() = delete;

		GeneralLexer(const vector<wstring>& fileNameList, const unordered_map<wstring, LexTokenDefine>& _lexDefineMap) :lexDefineMap(lexDefineMap)
		{
			this->fileInfoList = SetFileInfoList(fileNameList);
			this->regex		   = GetRealRegexWString(lexDefineMap);
		}

		vector<TokenInfo> Parse(const wstring& content, RegexInterpretor& interpretor)
		{
			vector<TokenInfo> tokens;
			tokens.emplace_back(TokenInfo());
			auto& info   = tokens.back();
			auto  result = interpretor.Matches(content);

			for(auto&element : result)
			{
				assert(element.group.size() == 1);
				auto name = element.group.begin()->first;

				if(!lexDefineMap[name].ignore)
				{
					auto groupItem       = element.group.begin()->second;
					info.tag             = GeneralLexer::NameToEnumMap[name];
					info.lex             = groupItem.content;
					info.position.index  = groupItem.position;
					info.position.length = groupItem.length;
				}
			}
			return tokens;
		}

		void Parse()
		{
			RegexInterpretor	   interpretor(regex);
			for(auto& fileIter : this->fileInfoList)
			{
				auto parseResult = Parse(fileIter.content, interpretor);
				this->reusltList.insert({ fileIter.name, move(parseResult) });
			}
		}

		const unordered_map<wstring, vector<TokenInfo>>& GetReusltList() const
		{
			return reusltList;
		}
	};
	unordered_map<wstring, ParserTag>	GeneralLexer::NameToEnumMap = GeneralLexer::InitNameToEnumMap();
}