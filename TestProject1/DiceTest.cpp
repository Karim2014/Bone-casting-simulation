#include "stdafx.h"
#include "..\Лабораторная работа 1\dice.h"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace	Microsoft::VisualStudio::TestTools::UnitTesting;

namespace TestProject1
{
	[TestClass]
	public ref class DiceTest
	{
	public: 
		[TestMethod]
		void TestMethod1()
		{
			Dice* dice = new Dice(2000, 6);
			cout << dice->throwDice();    
		}
	};
}
