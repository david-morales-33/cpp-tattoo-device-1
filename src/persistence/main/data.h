#pragma once

struct LetterData
{
  const char *text = "";
  int position = 0;
  LetterData(const char *t = "", int p = 0) : text(t), position(p) {}
};
