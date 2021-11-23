#include "pch.h"
#include "CppUnitTest.h"
#include "../task_8_sem_3/task_8_sem_3.cpp"
namespace Microsoft {
	namespace VisualStudio {
		namespace CppUnitTestFramework {
			template <> static std::wstring ToString(const list<pair<int, int>>& q) {
				wstringstream s;
				for (auto i = q.begin(); i != q.end(); i++) {
					s << "{"  << i->first << ", " << i->second<<"}" << " ";

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

namespace testplus
{
	TEST_CLASS(testplus)
	{
	public:
		
		TEST_METHOD(ppolynom_normal_2)
		{

			polynom t_input = { {0,3},{1,2},{2,4} };
			polynom t_input2 = { {0,4},{1,5},{2,3} };
			polynom t_actual = t_input + t_input2;
			polynom t_exprcted = { {0,7},{1,7},{2,8} };
			Assert::AreEqual(t_actual.size(), t_exprcted.size(), L" different size");
			Assert::AreEqual(t_actual, t_exprcted);
		}
		
		TEST_METHOD(ppolynom_nenormal_2)
		{

			polynom t_input = { {2,4},{5,5 } };
			polynom t_input2 = { {0,4},{1,5},{2,3} };
			polynom t_actual = t_input + t_input2;
			polynom t_exprcted = { {0,4},{1,5},{2,7},{5,5} };
			Assert::AreEqual(t_actual.size(), t_exprcted.size(), L" different size");
			Assert::AreEqual(t_actual, t_exprcted);
		}
		TEST_METHOD(ppolynom_nenormal_3)
		{

			polynom t_input = { {0,3} };
			polynom t_input2 = { {2,3} };
			polynom t_actual = t_input + t_input2;
			polynom t_exprcted = { {0,3},{2,3} };
			Assert::AreEqual(t_actual.size(), t_exprcted.size(), L" different size");
			Assert::AreEqual(t_actual, t_exprcted);
		}
		TEST_METHOD(pt)
		{

			polynom t_input = { {0,1},{1,1} };
			polynom t_input2 = { {0,1},{1,-1} };
			polynom t_actual = t_input + t_input2;
			polynom t_exprcted = { {0,2},{1,0} };
			Assert::AreEqual(t_actual.size(), t_exprcted.size(), L" different size");
			Assert::AreEqual(t_actual, t_exprcted);
		}
	};
}

