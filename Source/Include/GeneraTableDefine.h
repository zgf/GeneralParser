#pragma once
#include "stdafx.h"
/*!
 * \file GeneralTableDefine.h
 *
 * \author ZGF
 * \date 十一月 2014
 *通用语法树节点
 * 
 */
namespace ztl
{
	namespace general_parser
	{

	

	
		/*
		token和IgnoreToken的定义

		*/
		struct GeneralTokenDefine
		{
			wstring name;
			wstring regex;
			bool	ignore;
		};

		/*类型对象定义*/
		struct GeneralTypeObject :public enable_shared_from_this<GeneralTypeObject>
		{

		};

		struct GeneralArrayTypeObject : public GeneralTypeObject
		{
			shared_ptr<GeneralTypeObject>			element;
		};
		//对string类型的使用
		struct GeneralStringTypeObject : public GeneralTypeObject
		{

		};
		//对自定义类型的使用
		struct GeneralNormalTypeObject : public GeneralTypeObject
		{
			wstring									name;
		};
		//对嵌套定义类型的使用 例如 类型A下定义了类型B     A.B cc;
		struct GeneralSubTypeObject : public GeneralTypeObject
		{
			shared_ptr<GeneralTypeObject>			parent;
			wstring									name;
		};
		struct GeneralClassMemberTypeObject : public GeneralTypeObject
		{
			shared_ptr<GeneralTypeObject>			type;
			wstring									name;
		};
		struct GeneralEnumMemberTypeObject : public GeneralTypeObject
		{
			wstring									name;
		};
		/*
		类型的声明的定义
		*/
		struct GeneralTypeDefine :public enable_shared_from_this <GeneralTypeDefine>
		{

		};
		struct GeneralClassTypeDefine : public GeneralTypeDefine
		{
			vector<shared_ptr<GeneralTypeDefine>>				subType;
			vector<shared_ptr<GeneralClassMemberTypeObject>>	members;
			shared_ptr<GeneralTypeObject>						parent;
			wstring												name;
		};
		struct GeneralEnumTypeDefine : public GeneralTypeDefine
		{
			vector<shared_ptr<GeneralEnumMemberTypeObject>>		members;
			wstring												name;
		};

		/*
		文法定义
		*/
		//文法元素
		//终结符号
		struct GeneralGrammarTextTypeDefine;
		//非终结符号
		struct GeneralGrammarNonTerminateTypeDefine;
		//文法的行为

		//序列
		struct GeneralGrammarSequenceTypeDefine;
		//循环
		struct GeneralGrammarLoopTypeDefine;
		//可选
		struct GeneralGrammarOptionalTypeDefine;
		//赋值
		struct GeneralGrammarAssignTypeDefine;
		//附加赋值 with{}
		struct GeneralGrammarAdditionTypeDefine;
		//附加的key value
		struct GeneralGrammarSetterTypeDefine;

		//Using操作. 隐式类型转换
		struct GeneralGrammarUsingTypeDefine;
		//创建节点.区别返回类型
		struct GeneralGrammarCreateTypeDefine;
		//选择
		struct GeneralGrammarAlterationTypeDefine;
		struct GeneralGrammarTypeDefine :public enable_shared_from_this<GeneralGrammarTypeDefine>
		{

		};
		struct GeneralGrammarTextTypeDefine : public GeneralGrammarTypeDefine
		{
			wstring												text;
		};
		struct GeneralGrammarNormalTypeDefine : public GeneralGrammarTypeDefine
		{
			wstring												name;
		};
		struct GeneralGrammarSequenceTypeDefine : public GeneralGrammarTypeDefine
		{
			shared_ptr<GeneralGrammarTypeDefine>				first;
			shared_ptr<GeneralGrammarTypeDefine>				second;
		};
		//循环
		struct GeneralGrammarLoopTypeDefine : public GeneralGrammarTypeDefine
		{
			shared_ptr<GeneralGrammarTypeDefine>				grammar;
		};
		//可选
		struct GeneralGrammarOptionalTypeDefine : public GeneralGrammarTypeDefine
		{
			shared_ptr<GeneralGrammarTypeDefine>				grammar;
		};
		//赋值
		struct GeneralGrammarAssignTypeDefine : public GeneralGrammarTypeDefine
		{
			wstring												name;
			shared_ptr<GeneralGrammarTypeDefine>				grammar;
		};
		//附加赋值 with{}
		struct GeneralGrammarAdditionTypeDefine : public GeneralGrammarTypeDefine
		{
			shared_ptr<GeneralGrammarTypeDefine>				grammar;
			vector<shared_ptr<GeneralGrammarSetterTypeDefine>>  setters;
		};
		//附加的key-value对
		struct GeneralGrammarSetterTypeDefine : public GeneralGrammarTypeDefine
		{
			wstring												name;
			wstring												value;
		};
		//Using操作. 隐式类型转换
		struct GeneralGrammarUsingTypeDefine : public GeneralGrammarTypeDefine
		{
			shared_ptr<GeneralGrammarTypeDefine>				grammar;
		};
		//创建节点 区别返回类型
		struct GeneralGrammarCreateTypeDefine : public GeneralGrammarTypeDefine
		{
			shared_ptr<GeneralTypeObject>						type;
			shared_ptr<GeneralGrammarTypeDefine>				grammar;
		};
		struct GeneralGrammarAlterationTypeDefine : public GeneralGrammarTypeDefine
		{
			shared_ptr<GeneralGrammarTypeDefine>				left;
			shared_ptr<GeneralGrammarTypeDefine>				right;
		};

		struct GeneralRuleDefine
		{
			shared_ptr<GeneralTypeObject>						type;
			wstring												name;
			vector<shared_ptr<GeneralGrammarTypeDefine>>		grammars;
		};

		struct GeneralTableDefine
		{
			vector<shared_ptr<GeneralTypeDefine>>   types;
			vector<shared_ptr<GeneralTokenDefine>>  tokens;
			vector<shared_ptr<GeneralRuleDefine>>   rules;
		};
		//语法树手写工具


		//Token手写
		struct GeneralTokenWriter
		{
			vector<shared_ptr<GeneralTokenDefine>> tokens;
		public:
			GeneralTokenWriter& Token(const wstring& name, const wstring& regex);
			GeneralTokenWriter& IgnoreToken(const wstring& name, const wstring& regex);
		private:
			GeneralTokenWriter& Token(const wstring& name, const wstring& regex,bool ignore);

		};
		//TypeObject手写
		shared_ptr<GeneralArrayTypeObject>			Array(const shared_ptr<GeneralTypeObject>& elementType);
		shared_ptr<GeneralClassMemberTypeObject>	ClassMember(const shared_ptr<GeneralTypeObject>& type, const wstring& name);
		shared_ptr<GeneralEnumMemberTypeObject>		EnumMember(const wstring& name);
		shared_ptr<GeneralNormalTypeObject>			Normal(const wstring& name);
		shared_ptr<GeneralStringTypeObject>			String();
		shared_ptr<GeneralSubTypeObject>			SubTypeObject(const shared_ptr<GeneralTypeObject>& parent, const wstring& name);

		//Type手写
		struct GeneralClassTypeWriter;
		struct GeneralEnumTypeWriter;
		struct GeneralTypeListWriter
		{
			vector<shared_ptr<GeneralTypeDefine>> types;
	
		public:
			GeneralTypeListWriter& Class(const GeneralClassTypeWriter& writer);
			GeneralTypeListWriter& Enum(const GeneralEnumTypeWriter& writer);
		};

		struct GeneralClassTypeWriter
		{
			shared_ptr<GeneralClassTypeDefine> _struct;
		public:
			GeneralClassTypeWriter::GeneralClassTypeWriter() :_struct(make_shared<GeneralClassTypeDefine>())
			{

			}
		public:
			GeneralClassTypeWriter& Name(const wstring& name);
			GeneralClassTypeWriter& Member(const shared_ptr<GeneralClassMemberTypeObject>& member);
			GeneralClassTypeWriter& SubType(const GeneralTypeListWriter& writer);
			GeneralClassTypeWriter& ParentType(const shared_ptr<GeneralTypeObject>& type);
		};

		struct GeneralEnumTypeWriter
		{
			shared_ptr<GeneralEnumTypeDefine> _enum;
		public:
			GeneralEnumTypeWriter::GeneralEnumTypeWriter() :_enum(make_shared<GeneralEnumTypeDefine>())
			{

			}
		public:
			GeneralEnumTypeWriter& Name(const wstring& name);
			GeneralEnumTypeWriter& Member(const shared_ptr<GeneralEnumMemberTypeObject>& member);
		};

		

		//规则手写
		struct GeneralRuleWriter;
		struct GeneralRuleListWriter
		{
			vector<shared_ptr<GeneralRuleDefine>> rules;
		public:
			GeneralRuleListWriter& Rule(const GeneralRuleWriter& writer);
		};

		struct GeneralGrammarWriter;
		struct GeneralRuleWriter
		{
			shared_ptr<GeneralRuleDefine> rule;
		public:
			GeneralRuleWriter::GeneralRuleWriter() :rule(make_shared<GeneralRuleDefine>())
			{

			}
		public:
			GeneralRuleWriter& Name(const wstring& name);
			GeneralRuleWriter& ReturnType(const shared_ptr<GeneralTypeObject>& type);

			GeneralRuleWriter& operator|(const GeneralGrammarWriter& writer);
			GeneralRuleWriter& Grammar(const GeneralGrammarWriter& writer);

		};

		

		//文法规则手写
		struct GeneralSetterGrammarWriter;
		struct GeneralGrammarWriter
		{
			shared_ptr<GeneralGrammarTypeDefine> grammar;
		public:
			GeneralGrammarWriter::GeneralGrammarWriter() :grammar(make_shared<GeneralGrammarTypeDefine>())
			{

			}
		public:
			//附加
			GeneralGrammarWriter&		Addition(const GeneralSetterGrammarWriter& writer);
			//创建 As
			GeneralGrammarWriter&		Create(const shared_ptr<GeneralTypeObject>& type);
			//赋值
			GeneralGrammarWriter&		operator[](const wstring& name);
		};

		
		struct GeneralSetterGrammarWriter
		{
			vector<shared_ptr<GeneralGrammarSetterTypeDefine>> setters;
			GeneralSetterGrammarWriter& Setter(const wstring& name, const wstring& value);
		};

	

		//序列+
		GeneralGrammarWriter operator+(const GeneralGrammarWriter& first, const GeneralGrammarWriter& second);
		//using!
		GeneralGrammarWriter operator!(const GeneralGrammarWriter& writer);
		//循环*
		GeneralGrammarWriter operator*(const GeneralGrammarWriter& writer);
		//可选~
		GeneralGrammarWriter operator~(const GeneralGrammarWriter& writer);
		//终结符号
		GeneralGrammarWriter Text(const wstring& text);
		//终结符号
		GeneralGrammarWriter GrammarSymbol(const wstring& name);

		GeneralGrammarWriter operator|(const GeneralGrammarWriter& left, const GeneralGrammarWriter& right);

		//struct GeneralTokenWriter;
		//struct GeneralTypeWriter;
		//struct GeneralRuleWriter;
		//Table手写
		struct GeneralTableWriter
		{
			shared_ptr<GeneralTableDefine>	table;
		public:
			GeneralTableWriter::GeneralTableWriter() :table(make_shared<GeneralTableDefine>())
			{

			}
		public:
			GeneralTableWriter& Token(const GeneralTokenWriter& writer);
			GeneralTableWriter& Type(const GeneralTypeListWriter& writer);
			GeneralTableWriter& RuleList(const GeneralRuleListWriter& writer);
		};
		shared_ptr<GeneralTableDefine> BootStrapDefineTable();
	}
}