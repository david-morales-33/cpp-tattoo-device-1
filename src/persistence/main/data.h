#pragma once

struct MainData
{
  int hour = 0;
  int minute = 0;
  int day = 0;
  int month = 0;
  int year = 0;
  int temp = 0;
  const char *week_day = "";
};

struct LetterData
{
  const char *text = "";
  int position = 0;
  LetterData(const char *t = "", int p = 0) : text(t), position(p) {}
};
