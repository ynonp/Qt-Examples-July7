#ifndef BASECONVERTER_H
#define BASECONVERTER_H

#include <QString>

class BaseConverter {
public:
    BaseConverter();

public:
    QString toHex(int dec);
    QString toBinary(int dec);
};

#endif // BASECONVERTER_H
