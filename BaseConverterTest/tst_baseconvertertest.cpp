#include <QtCore/QString>
#include <QtTest/QtTest>
#include "baseconverter.h"

class BaseConverterTest : public QObject
{
    Q_OBJECT

public:
    BaseConverterTest();

private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void testCase1();
    void testCase1_data();

    /*
    void init();
    void cleanup();
    */
};

BaseConverterTest::BaseConverterTest()
{
}

void BaseConverterTest::initTestCase()
{
}

void BaseConverterTest::cleanupTestCase()
{
}

void BaseConverterTest::testCase1()
{
    QFETCH(int, dec);
    QFETCH(QString, hex);
    QFETCH(QString, bin);

    BaseConverter b;
    QVERIFY2(b.toBinary(dec) == bin, "Binary Failure");
    QVERIFY2(b.toHex(dec) == hex,
             QString("Hex Failure: %1 != %2 ").arg(b.toHex(dec), hex).toAscii());
}

void BaseConverterTest::testCase1_data()
{
    QTest::addColumn<int>("dec");
    QTest::addColumn<QString>("hex");
    QTest::addColumn<QString>("bin");

    QTest::newRow("101") << 10 << QString::number(12, 16) << QString::number(10, 2);
    QTest::newRow("aaa") << 50 << QString::number(50, 16) << QString::number(50, 2);
}

QTEST_APPLESS_MAIN(BaseConverterTest);

#include "tst_baseconvertertest.moc"
