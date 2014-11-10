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
	
	class GeneralTokenDefine;
	class GeneralTypeDefine;
	class GeneralRuleDefine;

	class GeneralTableDefine
	{
		vector<shared_ptr<GeneralTypeDefine>>   types;
		vector<shared_ptr<GeneralTokenDefine>>  tokens;
		vector<shared_ptr<GeneralRuleDefine>>   rules;
	};
	/*
	token和IgnoreToken的定义

	*/
	class GeneralTokenDefine
	{
		wstring name;
		wstring regex;
		bool	ignore;
	};

	/*类型对象定义*/
	class GeneralTypeObject
	{

	};
	
	class GeneralArrayTypeObject : public GeneralTypeObject
	{
		shared_ptr<GeneralTypeObject>			type;
	};
	//对string类型的使用
	class GeneralStringTypeObject : public GeneralTypeObject
	{

	};
	//对自定义类型的使用
	class GeneralNormalTypeObject : public GeneralTypeObject
	{
		shared_ptr<wstring>						name;
	}; 
	//对嵌套定义类型的使用 例如 类型A下定义了类型B     A.B cc;
	class GeneralSubTypeObject : public GeneralTypeObject
	{ 
		shared_ptr<GeneralTypeObject>			parent;
		wstring									name;
	};
	class GeneralClassMemberTypeObject : public GeneralTypeObject
	{
		GeneralTypeObject						type;
		wstring									name;
	};
	class GeneralEnumMemberTypeObject : public GeneralTypeObject
	{
		wstring									name;
	};
	/*
	类型的声明的定义
	*/
	class GeneralTypeDefine
	{

	};
	class GeneralClassTypeDefine : public GeneralTypeDefine
	{
		vector<shared_ptr<GeneralTypeDefine>>				subType;
		vector<shared_ptr<GeneralClassMemberTypeObject>>	members;
		shared_ptr<GeneralTypeObject>						parent;
	};
	class GeneralEnumTypeDefine : public GeneralTypeDefine
	{
		vector<shared_ptr<GeneralEnumMemberTypeObject>>		members;
	};
	
	/*
	文法定义
	*/
	//文法元素
	//终结符号
	class GeneralGrammarTextTypeDefine;
	//非终结符号
	class GeneralGrammarNonTerminateTypeDefine;
	//文法的行为

	//序列
	class GeneralGrammarSequenceTypeDefine;
	//循环
	class GeneralGrammarLoopTypeDefine;
	//可选
	class GeneralGrammarOptionalTypeDefine;
	//赋值
	class GeneralGrammarAssignTypeDefine;
	//附加赋值 with{}
	class GeneralGrammarAdditionTypeDefine;
	//附加的key value
	class GeneralGrammarSetterTypeDefine;

	//Using操作. 隐式类型转换
	class GeneralGrammarUsingTypeDefine;
	//创建节点.区别返回类型
	class GeneralGrammarCreateTypeDefine;

	class GeneralGrammarTypeDefine
	{

	};
	class GeneralGrammarTextTypeDefine : public GeneralGrammarTypeDefine
	{
		wstring												text;
	};
	class GeneralGrammarNonTerminateTypeDefine : public GeneralGrammarTypeDefine
	{
		wstring												name;
	};
	class GeneralGrammarSequenceTypeDefine : public GeneralGrammarTypeDefine
	{
		shared_ptr<GeneralGrammarTypeDefine>				left;
		shared_ptr<GeneralGrammarTypeDefine>				right;
	};
	//循环
	class GeneralGrammarLoopTypeDefine : public GeneralGrammarTypeDefine
	{
		shared_ptr<GeneralGrammarTypeDefine>				grammar;
	};
	//可选
	class GeneralGrammarOptionalTypeDefine : public GeneralGrammarTypeDefine
	{
		shared_ptr<GeneralGrammarTypeDefine>				grammar;
	};
	//赋值
	class GeneralGrammarAssignTypeDefine : public GeneralGrammarTypeDefine
	{
		wstring												name;
		shared_ptr<GeneralGrammarTypeDefine>				grammar;
	};
	//附加赋值 with{}
	class GeneralGrammarAdditionTypeDefine : public GeneralGrammarTypeDefine
	{
		shared_ptr<GeneralGrammarTypeDefine>				grammar;
		vector<shared_ptr<GeneralGrammarSetterTypeDefine>>  setters;
	};
	//附加的key-value对
	class GeneralGrammarSetterTypeDefine : public GeneralGrammarTypeDefine
	{
		wstring												name;
		wstring												value;
	};
	//Using操作. 隐式类型转换
	class GeneralGrammarUsingTypeDefine : public GeneralGrammarTypeDefine
	{
		shared_ptr<GeneralGrammarTypeDefine>				grammar;
	};
	//创建节点 区别返回类型
	class GeneralGrammarCreateTypeDefine : public GeneralGrammarTypeDefine
	{
		shared_ptr<GeneralTypeObject>						type;
		shared_ptr<GeneralGrammarTypeDefine>				grammar;
	};
	class GeneralRuleDefine
	{
		shared_ptr<GeneralTypeObject>						type;
		wstring												name;
		vector<shared_ptr<GeneralGrammarTypeDefine>>		grammars;
	};
}