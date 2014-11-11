#pragma once
#include "Include/GeneraTableDefine.h"

namespace ztl
{
	namespace general_parser
	{
		
		shared_ptr<GeneralTableDefine> BootStrapDefineTable()
		{
			GeneralTableWriter writer;
			writer.Token
				(
					GeneralTokenWriter()
					.Token(L"CLASS", L"class")
					.Token(L"ENUM", L"enum")
					.Token(L"Token", L"Token")
					.Token(L"DISCARDTOKEN", L"ignoretoken")
					.Token(L"RULE", L"rule")
					.Token(L"AS", L"as")
					.Token(L"WITH", L"with")
					.Token(L"OPEN", L"{")
					.Token(L"CLOSE", L"}")
					.Token(L"SEMICOLON", L")")
					.Token(L"COLON", L":")
					.Token(L"COMMA", L",")
					.Token(L"DOT", L".")
					.Token(L"ASSIGN", L"=")
					.Token(L"USING", L"!")
					.Token(L"OR", L"|")
					.Token(L"OPTOPEN", L"/[")
					.Token(L"OPTCLOSE", L"/]")
					.Token(L"PREOPEN", L"/(")
					.Token(L"PRECLOSE", L"/)")
					.Token(L"NAME", L"[a-zA-Z_]/w*")
					.Token(L"STRING", L"\"(\\\"|[^\"])*\"")
					.IgnoreToken(L"SPACE", L"/s+")
					.IgnoreToken(L"LINENOTE", L"//[^\n]*\n")
					.IgnoreToken(L"BLOCKNOTE", L"/*.*?*/ //")
				)
				.Type
				(
					GeneralTypeListWriter()
					.Class
					(
						GeneralClassTypeWriter()
						.Name(L"GeneralTokenDefine")
						.Member(ClassMember(String(), L"name"))
						.Member(ClassMember(String(), L"regex"))
						.Member(ClassMember(Normal(L"TokenOptional"),L"ignore"))
						.SubType
						(
							GeneralTypeListWriter()
							.Enum
							(
								GeneralEnumTypeWriter()
								.Name(L"TokenOptional")
								.Member(EnumMember(L"False"))
								.Member(EnumMember(L"True"))
							)
						)
					)
					.Class
					(
						GeneralClassTypeWriter()
						.Name(L"GeneralTypeObject")
					)
					.Class
					(
						GeneralClassTypeWriter()
						.Name(L"GeneralArrayTypeObject")
						.Member(ClassMember(Normal(L"GeneralTypeObject"), L"element"))
						.ParentType(Normal(L"GeneralTypeObject"))
					)
					.Class
					(
						GeneralClassTypeWriter()
						.Name(L"GeneralStringTypeObject")
						.ParentType(Normal(L"GeneralTypeObject"))
					)
					.Class
					(
						GeneralClassTypeWriter()
						.Name(L"GeneralNormalTypeObject")
						.Member(ClassMember(String(),L"name"))
						.ParentType(Normal(L"GeneralTypeObject"))
					)
					.Class
					(
						GeneralClassTypeWriter()
						.Name(L"GeneralSubTypeObject")
						.Member(ClassMember(Normal(L"GeneralTypeObject"),L"parent"))
						.Member(ClassMember(String(), L"name"))
						.ParentType(Normal(L"GeneralTypeObject"))
					)
					.Class
					(
						GeneralClassTypeWriter()
						.Name(L"GeneralClassMemberTypeObject")
						.Member(ClassMember(Normal(L"GeneralTypeObject"), L"type"))
						.Member(ClassMember(String(), L"name"))
						.ParentType(Normal(L"GeneralTypeObject"))
					)
					.Class
					(
						GeneralClassTypeWriter()
						.Name(L"GeneralEnumMemberTypeObject")
						.Member(ClassMember(String(), L"name"))
						.ParentType(Normal(L"GeneralTypeObject"))
					)
					.Class
					(
						GeneralClassTypeWriter()
						.Name(L"GeneralTypeDefine")
					)
					.Class
					(
						GeneralClassTypeWriter()
						.Name(L"GeneralClassTypeDefine")
						.Member(ClassMember(String(), L"name"))
						.Member(ClassMember(Normal(L"GeneralTypeObject"), L"parent"))
						.Member(ClassMember(Array(Normal(L"GeneralTypeDefine")), L"subType"))
						.Member(ClassMember(Array(Normal(L"GeneralClassMemberTypeObject")), L"members"))
						.ParentType(Normal(L"GeneralTypeDefine"))
					)
					.Class
					(
						GeneralClassTypeWriter()
						.Name(L"GeneralEnumTypeDefine")
						.Member(ClassMember(String(), L"name"))
						.Member(ClassMember(Array(Normal(L"GeneralEnumMemberTypeObject")), L"members"))
						.ParentType(Normal(L"GeneralTypeDefine"))
					)
					.Class
					(
						GeneralClassTypeWriter()
						.Name(L"GeneralGrammarTypeDefine")
					)
					.Class
					(
						GeneralClassTypeWriter()
						.Name(L"GeneralGrammarTextTypeDefine")
						.Member(ClassMember(String(), L"text"))
						.ParentType(Normal(L"GeneralGrammarTypeDefine"))
					)
					.Class
					(
						GeneralClassTypeWriter()
						.Name(L"GeneralGrammarNormalTypeDefine")
						.Member(ClassMember(String(), L"name"))
						.ParentType(Normal(L"GeneralGrammarTypeDefine"))
					)
					.Class
					(
						GeneralClassTypeWriter()
						.Name(L"GeneralGrammarSequenceTypeDefine")
						.Member(ClassMember(Normal(L"GeneralGrammarTypeDefine"), L"left"))
						.Member(ClassMember(Normal(L"GeneralGrammarTypeDefine"), L"right"))
						.ParentType(Normal(L"GeneralGrammarTypeDefine"))
					)
					.Class
					(
						GeneralClassTypeWriter()
						.Name(L"GeneralGrammarLoopTypeDefine")
						.Member(ClassMember(Normal(L"GeneralGrammarTypeDefine"), L"grammar"))
						.ParentType(Normal(L"GeneralGrammarTypeDefine"))
					)
					.Class
					(
						GeneralClassTypeWriter()
						.Name(L"GeneralGrammarOptionalTypeDefine")
						.Member(ClassMember(Normal(L"GeneralGrammarTypeDefine"), L"grammar"))
						.ParentType(Normal(L"GeneralGrammarTypeDefine"))
					)
					.Class
					(
						GeneralClassTypeWriter()
						.Name(L"GeneralGrammarAssignTypeDefine")
						.Member(ClassMember(String(), L"name"))
						.Member(ClassMember(Normal(L"GeneralGrammarTypeDefine"), L"grammar"))
						.ParentType(Normal(L"GeneralGrammarTypeDefine"))
					)
					.Class
					(
						GeneralClassTypeWriter()
						.Name(L"GeneralGrammarAdditionTypeDefine")
						.Member(ClassMember(Normal(L"GeneralGrammarTypeDefine"), L"grammar"))
						.Member(ClassMember(Array(Normal(L"GeneralGrammarSetterTypeDefine")), L"setters"))
						.ParentType(Normal(L"GeneralGrammarTypeDefine"))
					)
					.Class
					(
						GeneralClassTypeWriter()
						.Name(L"GeneralGrammarSetterTypeDefine")
						.Member(ClassMember(String(), L"name"))
						.Member(ClassMember(String(), L"value"))
						.ParentType(Normal(L"GeneralGrammarTypeDefine"))
					)
					.Class
					(
						GeneralClassTypeWriter()
						.Name(L"GeneralGrammarUsingTypeDefine")
						.Member(ClassMember(String(), L"name"))
						.Member(ClassMember(Normal(L"GeneralGrammarTypeDefine"), L"grammar"))
						.ParentType(Normal(L"GeneralGrammarTypeDefine"))
					)
					.Class
					(
						GeneralClassTypeWriter()
						.Name(L"GeneralGrammarCreateTypeDefine")
						.Member(ClassMember(Normal(L"GeneralTypeObject"), L"type"))
						.Member(ClassMember(Normal(L"GeneralGrammarTypeDefine"), L"grammar"))
						.ParentType(Normal(L"GeneralGrammarTypeDefine"))
					)
					.Class
					(
						GeneralClassTypeWriter()
						.Name(L"GeneralGrammarAlternationTypeDefine")
						.Member(ClassMember(Normal(L"GeneralGrammarTypeDefine"), L"first"))
						.Member(ClassMember(Normal(L"GeneralGrammarTypeDefine"), L"second"))
						.ParentType(Normal(L"GeneralGrammarTypeDefine"))
					)
					.Class
					(
						GeneralClassTypeWriter()
						.Name(L"GeneralRuleDefine")
						.Member(ClassMember(Normal(L"GeneralTypeObject"), L"type"))
						.Member(ClassMember(String(), L"name"))
						.Member(ClassMember(Array(Normal(L"GeneralGrammarTypeDefine")), L"grammars"))
					)
					.Class
					(
					GeneralClassTypeWriter()
					.Name(L"GeneralTableDefine")
					.Member(ClassMember(Array(Normal(L"GeneralTypeDefine")), L"types"))
					.Member(ClassMember(Array(Normal(L"GeneralTokenDefine")), L"tokens"))
					.Member(ClassMember(Array(Normal(L"GeneralRuleDefine")), L"rules"))
					)
				)
				.RuleList
				(
					GeneralRuleListWriter()
					.Rule
					(
						GeneralRuleWriter()
						.Name(L"Type")
						.ReturnType(Normal(L"GeneralTypeObject"))
						|Text(L"NAME")[L"name"].Create(Normal(L"GeneralNormalTypeObject"))
						| Text(L"token").Create(Normal(L"GeneralTokenTypeObject"))
						| (GrammarSymbol(L"Type")[L"parent"] + Text(L".") + Text(L"NAME")[L"name"]).Create(Normal(L"GeneralSubTypeObject"))
						| (GrammarSymbol(L"Type")[L"element"] + Text(L"[") + Text(L"]")).Create(Normal(L"GeneralArrayTypeObject"))
					)
					.Rule
					(
						GeneralRuleWriter()
						.Name(L"EnumMember")
						.ReturnType(Normal(L"GeneralEnumMemberTypeObject"))
						| (Text(L"NAME")[L"name"] + Text(L",")).Create(Normal(L"GeneralNormalTypeObject"))
					)
					.Rule
					(
						GeneralRuleWriter()
						.Name(L"Enum")
						.ReturnType(Normal(L"GeneralEnumTypeDefine"))
						| (Text(L"enum") + Text(L"NAME")[L"name"] + Text(L"{") + *(GrammarSymbol(L"EnumMember")[L"members"]) + Text(L"}")).Create(Normal(L"GeneralEnumTypeDefine"))
					)
					.Rule
					(
						GeneralRuleWriter()
						.Name(L"ClassMember")
						.ReturnType(Normal(L"GeneralClassMemberTypeObject"))
						| (GrammarSymbol(L"Type")[L"type"] + Text(L"NAME")[L"name"] + Text(L";")).Create(Normal(L"GeneralClassMemberTypeObject"))
					)
					.Rule
					(
						GeneralRuleWriter()
						.Name(L"TypeDecl")
						.ReturnType(Normal(L"GeneralTypeDefine"))
						| !GrammarSymbol(L"Enum")
						| !GrammarSymbol(L"Class")
					)
					.Rule
					(
						GeneralRuleWriter()
						.Name(L"Class")
						.ReturnType(Normal(L"GeneralClassTypeDefine"))
						| (
							Text(L"class") +
							Text(L"NAME")[L"name"] +
							~(
								Text(L":") + 
								GrammarSymbol(L"Type")[L"parent"]
								) +
							Text(L"{") +
							*(
								GrammarSymbol(L"ClassMember")[L"members"] | GrammarSymbol(L"TypeDecl")[L"subTypes"]
							 ) +
							Text(L"}")
						  )
						  .Create(Normal(L"GeneralClassTypeDefine"))
					)
					.Rule
					(
						GeneralRuleWriter()
						.Name(L"SequenceGrammar")
						.ReturnType(Normal(L"GeneralGrammarTypeDefine"))
						| !GrammarSymbol(L"PrimitiveGrammar")
						| (
							GrammarSymbol(L"SequenceGrammar")[L"first"]+
							GrammarSymbol(L"PrimitiveGrammar")[L"second"]
						  )
						  .Create(Normal(L"GeneralGrammarSequenceTypeDefine"))
					)
					.Rule
					(
						GeneralRuleWriter()
						.Name(L"AlternativeGrammar")
						.ReturnType(Normal(L"GeneralGrammarTypeDefine"))
						| !GrammarSymbol(L"SequenceGrammar")
						| (
						GrammarSymbol(L"AlternativeGrammar")[L"left"] +
						Text(L"|") +
						GrammarSymbol(L"SequenceGrammar")[L"right"]
						)
						.Create(Normal(L"GeneralGrammarAlternationTypeDefine"))
					)
					.Rule
					(
						GeneralRuleWriter()
						.Name(L"SetterGrammar")
						.ReturnType(Normal(L"GeneralGrammarTypeDefine"))
						| (
							Text(L"NAME")[L"name"] +
							Text(L"=")+
							Text(L"STRING")[L"value"]
						)
						.Create(Normal(L"GeneralGrammarSetterTypeDefine"))
					)
					.Rule
					(
						GeneralRuleWriter()
						.Name(L"Grammar")
						.ReturnType(Normal(L"GeneralGrammarTypeDefine"))
						| (
						GrammarSymbol(L"Grammar")[L"grammar"] +
						Text(L"as") +
						GrammarSymbol(L"Type")[L"type"]
						)
						.Create(Normal(L"GeneralGrammarCreateTypeDefine"))
						| (
							GrammarSymbol(L"Grammar")[L"grammar"] + 
							Text(L"with")+
							Text(L"{")+
							*(
								GrammarSymbol(L"SetterGrammar")[L"setters"]
							 ) +
							Text(L"}")
						).Create(Normal(L"GeneralGrammarAdditionTypeDefine"))
					)
					.Rule
					(
						GeneralRuleWriter()
						.Name(L"PrimitiveGrammar")
						.ReturnType(Normal(L"GeneralGrammarTypeDefine"))
						|(
							Text(L"NAME")[L"name"])
						.Create(Normal(L"GeneralGrammarNormalTypeDefine"))
						|(
							Text(L"STRING")[L"text"])
						.Create(Normal(L"GeneralGrammarTextTypeDefine"))
						|(
							GrammarSymbol(L"PrimitiveGrammar")[L"grammar"] +
							Text(L":") +
							GrammarSymbol(L"NAME")[L"name"]
						)
						.Create(Normal(L"GeneralGrammarAssignTypeDefine"))
						| (
							Text(L"!") + 
							GrammarSymbol(L"PrimitiveGrammar")[L"grammar"]
							).Create(Normal(L"GeneralGrammarUsingTypeDefine"))
						| (
							Text(L"[") + 
							GrammarSymbol(L"Grammar")[L"grammar"]+
							Text(L"]")
						  ).Create(Normal(L"GeneralGrammarOptionalTypeDefine"))
						| (
							Text(L"{") + 
							GrammarSymbol(L"Grammar")[L"grammar"] + 
							Text(L"}")
						  ).Create(Normal(L"GeneralGrammarLoopTypeDefine"))
						| Text(L"(")+
						  !GrammarSymbol(L"Grammar")+
						  Text(L")")
					)
					.Rule
					(
						GeneralRuleWriter()
						.Name(L"TokenDecl")
						.ReturnType(Normal(L"GeneralTokenDefine"))
						| (
							Text(L"token") +
							Text(L"NAME")[L"name"] +
							Text(L"=") +
							Text(L"STRING")[L"regex"] +
							Text(L";")
						  )
						  .Create(Normal(L"GeneralTokenDefine"))
							.Addition(
								GeneralSetterGrammarWriter()
								.Setter(L"ignore", L"False")
							)
						| (
							Text(L"ignoretoken") +
							Text(L"NAME")[L"name"] +
							Text(L"=") +
							Text(L"STRING")[L"regex"] +
							Text(L";")
						  )
						.Create(Normal(L"GeneralTokenDefine"))
							.Addition(
								GeneralSetterGrammarWriter()
								.Setter(L"ignore", L"True")
							)
					)
					.Rule
					(
						GeneralRuleWriter()
						.Name(L"RuleDecl")
						.ReturnType(Normal(L"GeneralRuleDefine"))
						| (
							Text(L"rule")+
							GrammarSymbol(L"Type")[L"type"]+
							Text(L"NAME")[L"name"] + 
							*(
								Text(L"=") +
								GrammarSymbol(L"Grammar")[L"grammars"])+
								Text(L";")

							)
						.Create(Normal(L"GeneralRuleDefine"))
					)
					.Rule
					(
						GeneralRuleWriter()
						.Name(L"ParserDecl")
						.ReturnType(Normal(L"GeneralTableDefine"))
						| (
							GrammarSymbol(L"TypeDecl")[L"types"] +
							GrammarSymbol(L"TokenDecl")[L"tokens"] +
							GrammarSymbol(L"RuleDecl")[L"rules"] 
						)
						.Create(Normal(L"GeneralTableDefine"))
					)
				)
				;
			return writer.table;
		}
	}
}
/*


*/