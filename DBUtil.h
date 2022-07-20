#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #ifdef __linux__
#include <arpa/inet.h>
#include <cerrno>
#include <fcntl.h>
#include <net/if.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <unistd.h>
#define INVALID_SOCKET -1
#define SOCKET int
#define ARG_ACCEPT socklen_t
#define closesocket(s) close(s)
// #else
//     #include <winsock2.h>
//     #include <ws2tcpip.h>
//     #define ARG_ACCEPT int
// #endif
#include "Book.h"
#include "BorrowRecord.h"
#include "TimeUtil.h"
#include "User.h"
#include <iostream>
#include <mysql/mysql.h>
#include <vector>
#pragma once

static string szUsername; //用户名
static string szPswd;     //密码

class DBUtil {
public:
  DBUtil();
  ~DBUtil();
  bool OpenDB();
  bool CloseDB();
  User ReadUser(string strUserName, string strUserPWD);
  bool AddBook(Book book);
  bool SelectAllBook(vector<Book> &books);
  bool SelectBookByName(string strBookName, vector<Book> &books);
  bool SelectBookById(int nBookId, Book &book);
  bool DeleteBookById(int nBookId);
  bool AddBorrowRecord(BorrowRecord borrowRecord);
  bool ExtendBorrowRecord(int nRecordId);
  bool SelectBorrowRecordByRecordId(BorrowRecord &borrowRecord, int nRecordId);
  bool FinishBorrowRecord(int nRecordId, int nBookId);
  bool SelectAllBorrowRecord(vector<BorrowRecord> &borrowRecords);
  bool SelectBorrowRecordByUserId(vector<BorrowRecord> &borrowRecords,
                                  int nUserId, int nType);
  User SelectUserById(int nUserId);
  bool AddUser(User user);
  bool SelectAllUser(vector<User> &users);

public:
  string szHost;     //主机名
  string szDatabase; //数据库名
  int nPort;         //端口号
  MYSQL myCont;
  MYSQL_RES *result;
  MYSQL_ROW sql_row;
  MYSQL_FIELD *fd;
  bool isOpen;
  TimeUtil timeUtil;
};