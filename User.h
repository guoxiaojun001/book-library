﻿#pragma once
#include <string>
using namespace std;
class User {
public:
  User();
  ~User();

public:
  int m_nID;            //用户ID
  string m_strName;     //用户名
  string m_strPassword; //用户密码
  int m_nRole;          //用户角色，1表示管理员，2表示普通用户
};
