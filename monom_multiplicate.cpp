#include "pch.h"
#include "CppUnitTest.h"
#include "../task_8_sem_3/task_8_sem_3.cpp"
namespace Microsoft {
	namespace VisualStudio {
		namespace CppUnitTestFramework {
			template <> static std::wstring ToString(const list<pair<int, int>>& q) {
				wstringstream s;
				for (auto i = q.begin(); i != q.end(); i++) {
					s << "{" << i->first << ", " << i->second << "}" << " ";

				}
				return s.str();
			}
		}
	}
}
namespace Microsoft {
	namespace VisualStudio {
		namespace CppUnitTestFramework {
			template <> static std::wstring ToString(const monom& q) {
				wstringstream s;

				s << "{" << q.first << ", " << q.second << "}" << " ";


				return s.str();
			}
		}
	}
}
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace monommultiplicate
{
	TEST_CLASS(monommultiplicate)
	{
	public:
		
		TEST_METHOD(polynom_int)
		{
			polynom t_input = { {0,3},{1,2},{2,4} };
			int a = 3;
			polynom t_actual = 3*t_input;
			polynom t_exprcted = { {0,21},{1,6},{2,12} };
			Assert::AreEqual(t_actual.size(), t_exprcted.size(), L" different size");
			Assert::AreEqual(t_actual, t_exprcted);
		}
		TEST_METHOD(monom_int)
		{
			monom t_input =  {2,4};
			int a = 3;
			monom t_actual = 3 * t_input;
			monom t_exprcted = {2,12};
			Assert::AreEqual(t_actual, t_exprcted);
		}
		TEST_METHOD(monom_polynom)
		{
			monom t_input = {2,2};
			polynom t_input_2 = { {0,5},{1,2},{2,6} };
			polynom t_actual =  t_input*t_input_2;
			polynom t_exprcted = { {2,10},{3,4},{4,12} };
			Assert::AreEqual(t_actual.size(), t_exprcted.size(), L" different size");
			Assert::AreEqual(t_actual, t_exprcted);
		}
		TEST_METHOD(polynom_polynom)
		{
			polynom t_input = { {0,-1},{2,1},{5,5} };
			polynom t_input_2 = { {0,4},{2,1},{6,1} };
			polynom t_actual = t_input * t_input_2;
			polynom t_exprcted = {{0,-4},{2,3},{4,1},{5,20},{6,-1},{7,5},{8,1},{11,5}};
			Assert::AreEqual(t_actual.size(), t_exprcted.size(), L" different size");
			Assert::AreEqual(t_actual, t_exprcted);
		}
	};
}
