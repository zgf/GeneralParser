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
	namespace general_parser
	{

	

	
		/*
		token��IgnoreToken�Ķ���

		*/
		struct GeneralTokenDefine
		{
			wstring name;
			wstring regex;
			bool	ignore;
		};

		/*���Ͷ�����*/
		struct GeneralTypeObject :public enable_shared_from_this<GeneralTypeObject>
		{

		};

		struct GeneralArrayTypeObject : public GeneralTypeObject
		{
			shared_ptr<GeneralTypeObject>			element;
		};
		//��string���͵�ʹ��
		struct GeneralStringTypeObject : public GeneralTypeObject
		{

		};
		//���Զ������͵�ʹ��
		struct GeneralNormalTypeObject : public GeneralTypeObject
		{
			wstring									name;
		};
		//��Ƕ�׶������͵�ʹ�� ���� ����A�¶���������B     A.B cc;
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
		���͵������Ķ���
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
		�ķ�����
		*/
		//�ķ�Ԫ��
		//�ս����
		struct GeneralGrammarTextTypeDefine;
		//���ս����
		struct GeneralGrammarNonTerminateTypeDefine;
		//�ķ�����Ϊ

		//����
		struct GeneralGrammarSequenceTypeDefine;
		//ѭ��
		struct GeneralGrammarLoopTypeDefine;
		//��ѡ
		struct GeneralGrammarOptionalTypeDefine;
		//��ֵ
		struct GeneralGrammarAssignTypeDefine;
		//���Ӹ�ֵ with{}
		struct GeneralGrammarAdditionTypeDefine;
		//���ӵ�key value
		struct GeneralGrammarSetterTypeDefine;

		//Using����. ��ʽ����ת��
		struct GeneralGrammarUsingTypeDefine;
		//�����ڵ�.���𷵻�����
		struct GeneralGrammarCreateTypeDefine;
		//ѡ��
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
		//ѭ��
		struct GeneralGrammarLoopTypeDefine : public GeneralGrammarTypeDefine
		{
			shared_ptr<GeneralGrammarTypeDefine>				grammar;
		};
		//��ѡ
		struct GeneralGrammarOptionalTypeDefine : public GeneralGrammarTypeDefine
		{
			shared_ptr<GeneralGrammarTypeDefine>				grammar;
		};
		//��ֵ
		struct GeneralGrammarAssignTypeDefine : public GeneralGrammarTypeDefine
		{
			wstring												name;
			shared_ptr<GeneralGrammarTypeDefine>				grammar;
		};
		//���Ӹ�ֵ with{}
		struct GeneralGrammarAdditionTypeDefine : public GeneralGrammarTypeDefine
		{
			shared_ptr<GeneralGrammarTypeDefine>				grammar;
			vector<shared_ptr<GeneralGrammarSetterTypeDefine>>  setters;
		};
		//���ӵ�key-value��
		struct GeneralGrammarSetterTypeDefine : public GeneralGrammarTypeDefine
		{
			wstring												name;
			wstring												value;
		};
		//Using����. ��ʽ����ת��
		struct GeneralGrammarUsingTypeDefine : public GeneralGrammarTypeDefine
		{
			shared_ptr<GeneralGrammarTypeDefine>				grammar;
		};
		//�����ڵ� ���𷵻�����
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
		//�﷨����д����


		//Token��д
		struct GeneralTokenWriter
		{
			vector<shared_ptr<GeneralTokenDefine>> tokens;
		public:
			GeneralTokenWriter& Token(const wstring& name, const wstring& regex);
			GeneralTokenWriter& IgnoreToken(const wstring& name, const wstring& regex);
		private:
			GeneralTokenWriter& Token(const wstring& name, const wstring& regex,bool ignore);

		};
		//TypeObject��д
		shared_ptr<GeneralArrayTypeObject>			Array(const shared_ptr<GeneralTypeObject>& elementType);
		shared_ptr<GeneralClassMemberTypeObject>	ClassMember(const shared_ptr<GeneralTypeObject>& type, const wstring& name);
		shared_ptr<GeneralEnumMemberTypeObject>		EnumMember(const wstring& name);
		shared_ptr<GeneralNormalTypeObject>			Normal(const wstring& name);
		shared_ptr<GeneralStringTypeObject>			String();
		shared_ptr<GeneralSubTypeObject>			SubTypeObject(const shared_ptr<GeneralTypeObject>& parent, const wstring& name);

		//Type��д
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

		

		//������д
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

		

		//�ķ�������д
		struct GeneralSetterGrammarWriter;
		struct GeneralGrammarWriter
		{
			shared_ptr<GeneralGrammarTypeDefine> grammar;
		public:
			GeneralGrammarWriter::GeneralGrammarWriter() :grammar(make_shared<GeneralGrammarTypeDefine>())
			{

			}
		public:
			//����
			GeneralGrammarWriter&		Addition(const GeneralSetterGrammarWriter& writer);
			//���� As
			GeneralGrammarWriter&		Create(const shared_ptr<GeneralTypeObject>& type);
			//��ֵ
			GeneralGrammarWriter&		operator[](const wstring& name);
		};

		
		struct GeneralSetterGrammarWriter
		{
			vector<shared_ptr<GeneralGrammarSetterTypeDefine>> setters;
			GeneralSetterGrammarWriter& Setter(const wstring& name, const wstring& value);
		};

	

		//����+
		GeneralGrammarWriter operator+(const GeneralGrammarWriter& first, const GeneralGrammarWriter& second);
		//using!
		GeneralGrammarWriter operator!(const GeneralGrammarWriter& writer);
		//ѭ��*
		GeneralGrammarWriter operator*(const GeneralGrammarWriter& writer);
		//��ѡ~
		GeneralGrammarWriter operator~(const GeneralGrammarWriter& writer);
		//�ս����
		GeneralGrammarWriter Text(const wstring& text);
		//�ս����
		GeneralGrammarWriter GrammarSymbol(const wstring& name);

		GeneralGrammarWriter operator|(const GeneralGrammarWriter& left, const GeneralGrammarWriter& right);

		//struct GeneralTokenWriter;
		//struct GeneralTypeWriter;
		//struct GeneralRuleWriter;
		//Table��д
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