#include "Book.h"
#include "BorrowRecord.h"
#include "DBUtil.h"
#include "TimeUtil.h"
#include "User.h"
#include <algorithm>
#include <ctype.h>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include <vector>
using namespace std;
class Student : public User {
public:
  Student(DBUtil dbUtil);
  ~Student();
  void ShowMenu();
  bool QueryBook(string strBookName);
  bool BorrowBook(int nBookId);
  bool ReturnBook();
  bool ShowMyBorrowRecord();
  bool RenewBook();

public:
  TimeUtil m_timeUtil;
  DBUtil m_dbUtil;
};
