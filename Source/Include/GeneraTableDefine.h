#pragma once
#include "stdafx.h"
/*!
 * \file GeneralTableDefine.h
 *
 * \author ZGF
 * \date ʮһ�� 2014
 *ͨ���﷨���ڵ�
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
	token��IgnoreToken�Ķ���

	*/
	class GeneralTokenDefine
	{
		wstring name;
		wstring regex;
		bool	ignore;
	};

	/*���Ͷ�����*/
	class GeneralTypeObject
	{

	};
	
	class GeneralArrayTypeObject : public GeneralTypeObject
	{
		shared_ptr<GeneralTypeObject>			type;
	};
	//��string���͵�ʹ��
	class GeneralStringTypeObject : public GeneralTypeObject
	{

	};
	//���Զ������͵�ʹ��
	class GeneralNormalTypeObject : public GeneralTypeObject
	{
		shared_ptr<wstring>						name;
	}; 
	//��Ƕ�׶������͵�ʹ�� ���� ����A�¶���������B     A.B cc;
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
	���͵������Ķ���
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
	�ķ�����
	*/
	//�ķ�Ԫ��
	//�ս����
	class GeneralGrammarTextTypeDefine;
	//���ս����
	class GeneralGrammarNonTerminateTypeDefine;
	//�ķ�����Ϊ

	//����
	class GeneralGrammarSequenceTypeDefine;
	//ѭ��
	class GeneralGrammarLoopTypeDefine;
	//��ѡ
	class GeneralGrammarOptionalTypeDefine;
	//��ֵ
	class GeneralGrammarAssignTypeDefine;
	//���Ӹ�ֵ with{}
	class GeneralGrammarAdditionTypeDefine;
	//���ӵ�key value
	class GeneralGrammarSetterTypeDefine;

	//Using����. ��ʽ����ת��
	class GeneralGrammarUsingTypeDefine;
	//�����ڵ�.���𷵻�����
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
	//ѭ��
	class GeneralGrammarLoopTypeDefine : public GeneralGrammarTypeDefine
	{
		shared_ptr<GeneralGrammarTypeDefine>				grammar;
	};
	//��ѡ
	class GeneralGrammarOptionalTypeDefine : public GeneralGrammarTypeDefine
	{
		shared_ptr<GeneralGrammarTypeDefine>				grammar;
	};
	//��ֵ
	class GeneralGrammarAssignTypeDefine : public GeneralGrammarTypeDefine
	{
		wstring												name;
		shared_ptr<GeneralGrammarTypeDefine>				grammar;
	};
	//���Ӹ�ֵ with{}
	class GeneralGrammarAdditionTypeDefine : public GeneralGrammarTypeDefine
	{
		shared_ptr<GeneralGrammarTypeDefine>				grammar;
		vector<shared_ptr<GeneralGrammarSetterTypeDefine>>  setters;
	};
	//���ӵ�key-value��
	class GeneralGrammarSetterTypeDefine : public GeneralGrammarTypeDefine
	{
		wstring												name;
		wstring												value;
	};
	//Using����. ��ʽ����ת��
	class GeneralGrammarUsingTypeDefine : public GeneralGrammarTypeDefine
	{
		shared_ptr<GeneralGrammarTypeDefine>				grammar;
	};
	//�����ڵ� ���𷵻�����
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