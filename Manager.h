#include <stdlib.h>
// #include <windows.h>
#include "Book.h"
#include "DBUtil.h"
#include "TimeUtil.h"
#include "User.h"
#include <algorithm>
#include <ctype.h>
#include <iomanip>
#include <time.h>
#include <vector>
using namespace std;
#pragma once
class Manager : public User {
public:
  Manager(DBUtil dbUtil);
  ~Manager();
  void ShowMenu();
  bool AddBook();
  bool DisplayAllBook();
  bool QueryBook(string strBookName);
  bool DeleteBook(int nBookId);
  bool DiaplayAllBorrowRecord();
  bool AddUser();
  bool DisplayAllUser();
  TimeUtil m_timeUtil;
  DBUtil m_dbUtil;
};
