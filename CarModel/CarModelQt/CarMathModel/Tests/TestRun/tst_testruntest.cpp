#include <QString>
#include <QtTest>
class TestRunTest : public QObject
{
    Q_OBJECT

public:
    TestRunTest();

private Q_SLOTS:
    void testCase1();
};

TestRunTest::TestRunTest()
{
}

void TestRunTest::testCase1()
{
}

QTEST_MAIN(TestRunTest)

#include "tst_testruntest.moc"
