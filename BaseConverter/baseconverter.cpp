#include "baseconverter.h"

BaseConverter::BaseConverter()
{
}

QString BaseConverter::toHex(int dec)
{
    return QString::number(dec, 16);
}

QString BaseConverter::toBinary(int dec)
{
    return QString::number(dec, 2);
}
