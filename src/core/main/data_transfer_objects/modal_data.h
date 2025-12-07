#pragma once

class ModalData
{
private:
    const char *text;
    int position;

public:
    ModalData(const char *_text, int _position) : text(_text), position(_position) {}
    const char *getText() const { return text; }
    const int getPosition() const { return position; }
};