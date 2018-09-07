#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Skubak_Task/Skubak_Task.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Skubak_UnitTest
{		
	//Проверка класса TaskA
		TEST_CLASS(Task_A)
		{
		public:
			TEST_METHOD(Big_small_symbols)//значение "АА" и "аа" разные значения
			{
				TaskA  task_a = TaskA();
				int result = task_a.count_new("Wowodowo", 'w', 'o');
				Assert::AreEqual(result, 2);
			}
			TEST_METHOD(Three_symbols_counts_two_times)//три символа подрят считаются два раза
			{
				TaskA  task_a = TaskA();
				int result = task_a.count_new("www leningrad www", 'w', 'w');
				Assert::AreEqual(result, 4);
			}
		};

        //Проверка класса TaskВ
		TEST_CLASS(Task_B)
		{
		public:
			
			TEST_METHOD(Find_Comma)	//проверка на замену с запятой на точку
			{
				    string result2=".......";
					TaskB  task_b = TaskB();
					string result = task_b.Repl(",,,,...");
					Assert::AreEqual(result, result2);
			}
		};

		TEST_CLASS(Task_C)
		{
		public:
			TEST_METHOD(Find_Numbers)//проверка на вывод цифр
			{
				string result2 = "11334";
				TaskC  task_c = TaskC();
				string result = task_c.numbers("11..33.4,D");
				Assert::AreEqual(result, result2);
			}
		};

	}
